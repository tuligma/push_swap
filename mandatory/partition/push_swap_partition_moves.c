/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition_moves.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:14:08 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 21:44:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//all moves here are the statements of the conditions on body of separation
int	x_tail_prev_series(t_ps_hub *data, t_ps_stack *a,
	t_ps_stack *x, t_list *current)
{
	move_single(reverse_rotate, a, STR_RRA, data);
	if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), reverse_rotate) != 0)
		return (ERR_MALLOC_FAILED);
	move_single(swap, a, STR_SA, data);
	swap(x);
	return (0);
}

int	rotate_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current)
{
	move_single(rotate, a, STR_RA, data);
	if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), rotate) != 0)
		return (ERR_MALLOC_FAILED);
	return (0);
}

int	swap_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current)
{
	move_single(swap, a, STR_SA, data);
	if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), swap) != 0)
		return (ERR_MALLOC_FAILED);
	return (0);
}
