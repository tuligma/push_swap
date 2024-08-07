/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:18:26 by npentini          #+#    #+#             */
/*   Updated: 2024/08/07 21:13:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	body_of_separation(t_ps_hub *data, t_ps_stack *x, t_list *current)
{
	if (add_to_end_series(data->a, x, current))
	{
		if (rotate_series(data, data->a, x, current) != 0)
			return (EPSMAL);
	}
	else if (swap_head_to_next_series(x, current))
	{
		if (swap_series(data, data->a, x, current) != 0)
			return (EPSMAL);
	}
	else if (add_to_head_series(x, current))
	{
		if (reverse_series(data, data->a) != 0)
			return (EPSMAL);
	}
	else
	{
		if (push_series(data, data->a, data->b) != 0)
			return (EPSMAL);
	}
	return (0);
}

int	separation(t_ps_hub *data)
{
	t_ps_stack	*a;
	t_list		*current;

	a = data->a;
	while (a->count > data->series->length)
	{
		current = a->head;
		if (body_of_separation(data, data->series->x, current) != 0)
			return (EPSMAL);
	}
	return (0);
}

// int	separation(t_ps_hub *data)
// {
// 	t_ps_stack	*a;
// 	t_ps_stack	*b;
// 	t_ps_stack	*x;
// 	t_list		*current;

// 	a = data->a;
// 	b = data->b;
// 	x = data->series->x;
// 	while (a->count > data->series->length)
// 	{
// 		current = a->head;
// 		if (x->tail != NULL
// 			&& *((int *)a->tail->content) == *((int *)x->tail->content)
// 			&& *((int *)current->content) > *((int *)x->tail->content))
// 		{
// 			rotate(a);
// 			if (add_move(data, data->protocols->ra) != 0)
// 				return (EPSMAL);
// 			if (add_to_stack_x(x, &data->series->length,
// 					&*((int *)current->content), rotate) != 0)
// 				return (EPSMAL);
// 		}
// 		else if ((current->next != NULL
// 				&& x->head != NULL && x->head->next != NULL)
// 			&& (*((int *)current->next->content) == *((int *)x->head->content))
// 			&& (*((int *)current->content) > *((int *)x->head->content)
// 				&& *((int *)current->content) < *((int *)x->head->next->content)))
// 		{
// 			swap(a);
// 			if (add_move(data, data->protocols->sa) != 0)
// 				return (EPSMAL);
// 			if (add_to_stack_x(x, &data->series->length, &*((int *)current->content), swap) != 0)
// 				return (EPSMAL);
// 		}
// 		else if (x->head != NULL && *((int *)current->content) == *((int *)x->head->content))
// 		{
// 			reverse_rotate(a);
// 			if (add_move(data, data->protocols->rra) != 0)
// 				return (EPSMAL);
// 		}
// 		else
// 		{
// 			push(a, b);
// 			if (add_move(data, data->protocols->pb) != 0)
// 				return (EPSMAL);
// 		}
// 	}
// 	return (0);
// }
