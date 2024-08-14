/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols_execute_print.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:53:30 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 10:57:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_push(t_ps_stack *push_to, char *move, t_ps_hub *data)
{
	t_ps_stack	*pop;

	if (push_to == data->a)
		pop = data->b;
	else
		pop = data->a;
	if (pop->count > 0)
	{
		push(pop, push_to);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}
}

void	move_both(void (*f)(t_ps_stack *), char *move, t_ps_hub *data)
{
	if (data->a->count > 0 && data->b->count > 0)
	{
		both_protocol(data->a, data->b, f);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}
}

void	move_single(void (*f)(t_ps_stack *),
	t_ps_stack *stack, char *move, t_ps_hub *data)
{
	if (stack->count > 0)
	{
		f(stack);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}
}

void	min_to_head(t_ps_hub *data, t_ps_stack *a)
{
	t_list	*current;
	int		reverse;
	int		pos;

	current = a->head;
	pos = 0;
	reverse = 0;
	while (current != NULL)
	{
		if (*(int *)current->content == data->min)
			break ;
		pos++;
		current = current->next;
	}
	if (a->count - pos < pos)
	{
		pos = a->count - pos;
		reverse = 1;
	}
	if (reverse == 1)
		rotate_or_reverse_action(data, a, pos, reverse_rotate);
	else
		rotate_or_reverse_action(data, a, pos, rotate);
}
