/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:18:26 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 01:33:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	body_of_separation_ext(t_ps_hub *data, t_ps_stack *x, t_list *current)
{
	if (add_to_x_series(x, current))
	{
		if (add_to_stack_x(x, &data->series->length,
				&*((int *)current->content), NULL) != 0)
			return (ERR_MALLOC_FAILED);
		return (1);
	}
	else if (add_to_x_tail_prev(data, x, current) != 0)
	{
		if (x_tail_prev_series(data, data->a, x, current) != 0)
			return (ERR_MALLOC_FAILED);
		return (1);
	}
	return (0);
}

int	body_of_separation(t_ps_hub *data, t_ps_stack *x, t_list *current)
{
	if (body_of_separation_ext(data, x, current) != 0)
		return (0);
	else if (add_to_end_series(data->a, x, current))
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
	if (data->arg_count == 4 && lst_rev_sort_checker(a) == 0)
	{
		while (a->count > 3)
			move_push(data->b, STR_PB, data);
		three_arguments(data);
		return (0);
	}
	data->series = store_series(data, data->a, count_ascend_series);
	if (data->series == NULL)
		return (error_print(ERR_MALLOC_FAILED));
	if (push_args_to_stack_x(data) != 0)
		return (error_print(ERR_MALLOC_FAILED));
	while (a->count > data->series->length)
	{
		current = a->head;
		if (body_of_separation(data, data->series->x, current) != 0)
			return (error_print(ERR_MALLOC_FAILED));
	}
	free_series(&data->series);
	return (0);
}
