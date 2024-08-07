/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition_moves.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:14:08 by npentini          #+#    #+#             */
/*   Updated: 2024/08/07 21:15:21 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	rotate_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current)
{
	rotate(a);
	if (add_move(data, data->protocols->ra) != 0)
		return (EPSMAL);
	if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), rotate) != 0)
		return (EPSMAL);
	return (0);
}

int	swap_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current)
{
	swap(a);
	if (add_move(data, data->protocols->sa) != 0)
		return (EPSMAL);
	if (add_to_stack_x(x, &data->series->length,
			&*((int *)current->content), swap) != 0)
		return (EPSMAL);
	return (0);
}

int	reverse_series(t_ps_hub *data, t_ps_stack *a)
{
	reverse_rotate(a);
	if (add_move(data, data->protocols->rra) != 0)
		return (EPSMAL);
	return (0);
}

int	push_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *b)
{
	push(a, b);
	if (add_move(data, data->protocols->pb) != 0)
		return (EPSMAL);
	return (0);
}
