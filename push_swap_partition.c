/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:18:26 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 14:03:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"


int	body_of_separation(t_ps_hub *data, t_ps_stack *x, t_list *current)
{
	if (add_to_x_series(x, current))
	{
		if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), NULL) != 0)
			return (ERR_MALLOC_FAILED);
		return (0);
	}
	// if (data->arg_count == 4 && x->tail != NULL && data->a->tail != NULL && x->tail->prev != NULL && *((int *)data->a->tail->content) == *((int *)x->tail->content) &&*((int *)current->content) < *((int *)x->tail->content) && *((int *)current->content) > *((int *)x->tail->prev->content))
	// {
	// 	move_single(reverse_rotate, data->a, STR_RRA, data);
	// 	if (add_to_stack_x(x, &data->series->length,
	// 		&*((int *)current->content), reverse_rotate) != 0)
	// 		return (ERR_MALLOC_FAILED);
	// 	move_single(swap, data->a, STR_SA, data);
	// 	swap(x);
	// 	// move_single(rotate, data->a, STR_RA, data);
	// 	// move_single(rotate, data->a, STR_RA, data);
	// 	// rotate(x);
	// 	// rotate(x);
	// 	return (0);
	// }
	if (add_to_end_series(data->a, x, current))
	{
		if (rotate_series(data, data->a, x, current) != 0)
			return (ERR_MALLOC_FAILED);
	}
	else if (swap_head_to_next_series(x, current))
	{
		if (swap_series(data, data->a, x, current) != 0)
			return (ERR_MALLOC_FAILED);
	}
	else if (add_to_head_series(x, current))
		move_single(reverse_rotate, data->a, STR_RRA, data);
	else
		move_push(data->b, STR_PB, data);
	return (0);
}

int	separation(t_ps_hub *data)
{
	t_ps_stack	*a;
	t_list		*current;

	a = data->a;
	data->series = store_series(data, data->a, count_ascend_series);
	if (data->series == NULL)
		return (error_print(ERR_MALLOC_FAILED));
	if (push_args_to_stack_x(data) != 0)
		return (error_print(ERR_MALLOC_FAILED));
	if (data->arg_count == 4)
	{
		while (a->count > 3)
			move_push(data->b, STR_PB, data);
		three_arguments(data);
		return (0);
	}
	while (a->count > data->series->length)
	{
		current = a->head;
		if (body_of_separation(data, data->series->x, current) != 0)
			return (error_print(ERR_MALLOC_FAILED));
	}
	return (0);
}
