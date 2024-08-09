/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:30:31 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 02:49:34 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_node(void *content)
{
	ft_printf("node: ");
	ft_printf("%d\n", *(int*)content);
}

int	push_args_to_stack_a(t_ps_hub *data)
{
	t_ps_stack *a;
	t_list *node;
	int		*args;
	int			x;

	x = -1;
	a = data->a;
	args = data->args;
	while (++x < data->arg_count)
	{
		node = ft_lstnew(&args[x]);
		if (node == NULL)
			return (error_print(ERR_MALLOC_FAILED));
		if (x == 0)
			a->head = node;
		else
			ft_lstadd_back(&a->head, node);
	}
	a->tail = ft_lstlast(a->head);
	a->count = data->arg_count;
	return (0);
}

int	push_args_to_stack_x(t_ps_hub *data)
{
	t_ps_stack *x;
	t_list *node;
	int		*args;
	int			i;

	i = -1;
	x = data->series->x;
	args = data->series->series;
	while (++i < data->series->length)
	{
		node = ft_lstnew(&args[i]);
		if (node == NULL)
			return (error_print(ERR_MALLOC_FAILED));
		if (i == 0)
			x->head = node;
		else
			ft_lstadd_back(&x->head, node);
	}
	x->tail = ft_lstlast(x->head);
	x->count = data->arg_count;
	return (0);
}
