/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_execution.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:26:52 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 13:03:31 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_or_reverse_action(t_ps_hub *data,
	t_ps_stack *stack, int count, void (*f)(t_ps_stack *))
{
	char	*protocol;
	int		x;

	if (stack == data->a && f == rotate)
		protocol = STR_RA;
	else if (stack == data->a && f == reverse_rotate)
		protocol = STR_RRA;
	else if (stack == data->b && f == rotate)
		protocol = STR_RB;
	else if (stack == data->b && f == reverse_rotate)
		protocol = STR_RRB;
	x = -1;
	while (++x < count)
	{
		if (stack == data->a)
			move_single(f, data->a, protocol, data);
		else if (stack == data->b)
			move_single(f, data->b, protocol, data);
	}
}

void	final_rotation_ab(t_ps_hub *data,
	t_ps_stack *stack, t_ps_cost *cost, int pos)
{
	int	reverse;

	if (stack == data->a)
		reverse = cost->reverse_a;
	else
		reverse = cost->reverse_b;
	if (pos > 0)
	{
		if (reverse == 1)
			rotate_or_reverse_action(data, stack, pos, reverse_rotate);
		else
			rotate_or_reverse_action(data, stack, pos, rotate);
	}
}

void	simultaneuos_action(t_ps_hub *data,
	int count, void (*f)(t_ps_stack *))
{
	char	*protocol;
	int		x;

	if (f == reverse_rotate)
		protocol = STR_RRR;
	else
		protocol = STR_RR;
	x = -1;
	while (++x < count)
	{
		move_both(f, protocol, data);
		(data->cost->pos_a)--;
		(data->cost->pos_b)--;
	}
}

void	final_rotation_simultaneous(t_ps_hub *data, t_ps_cost *cost)
{
	void	(*f)(t_ps_stack *);
	int		count;

	if (cost->pos_a > 0
		&& cost->pos_b > 0 && cost->reverse_a == cost->reverse_b)
	{
		if (cost->pos_a <= cost->pos_b)
			count = cost->pos_a;
		else if (cost->pos_b < cost->pos_a)
			count = cost->pos_b;
		if (cost->reverse_a == 1 && cost->reverse_b == 1)
			f = reverse_rotate;
		else
			f = rotate;
		simultaneuos_action(data, count, f);
	}
}

int	execute_merge(t_ps_hub *data)
{
	t_ps_stack	*a;
	t_ps_stack	*b;
	t_ps_cost	*cost;

	if (data->cost == NULL
		&& struct_init((void **)&data->cost, sizeof(t_ps_cost)) != 0)
		return (ERR_MALLOC_FAILED);
	a = data->a;
	b = data->b;
	cost = data->cost;
	find_best_move_in_b(data, b, cost);
	final_rotation_simultaneous(data, cost);
	final_rotation_ab(data, a, cost, cost->pos_a);
	final_rotation_ab(data, b, cost, cost->pos_b);
	move_push(a, STR_PA, data);
	if (b->count > 0)
		execute_merge(data);
	return (0);
}
