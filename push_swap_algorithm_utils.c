/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:35:34 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 02:50:29 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"



int	lst_rev_sort_checker(t_ps_stack *stack)
{
	t_list	*current;
	int		content1;
	int		content2;

	current = stack->head;
	while (current != NULL && current->next != NULL)
	{
		content1 = *((int *)current->content);
		content2 = *((int *)current->next->content);
		if (content1 < content2)
			return (1);
		current = current->next;
	}
	return (0);
}

void	print_moves(t_list *moves)
{
	t_list	*current;
	char	*str;

	current = moves;
	while(current != NULL)
	{
		str = (char *)current->content;
		ft_printf("%s\n", str);
		current = current->next;
	}
}

// void	print_protocols(void **moves)
// {
// 	int	x;
	
// 	x = -1;
// 	while(++x < PROTO_COUNT)
// 		ft_printf("%s -> move: %d\n", (char *)moves[x], x);
// }