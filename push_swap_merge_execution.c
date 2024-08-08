/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_execution.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:26:52 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 03:43:34 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"


int	rotate_or_reverse_action(t_ps_hub *data,
	t_ps_stack *stack, int count ,void (*f)(t_ps_stack *))
{
	char	*protocol;
	int	x;
	
	if (stack == data->a && f == rotate)
		protocol = data->protocols->ra;
	else if (stack == data->a && f == reverse_rotate)
		protocol = data->protocols->rra;
	else if (stack == data->b && f == rotate)
		protocol = data->protocols->rb;
	else if (stack == data->b && f == reverse_rotate)
		protocol = data->protocols->rrb;
	x = -1;
	while (++x < count)
	{
		f(stack);
		if (add_move(data, protocol) != 0)
				return (EPSMAL);
	}
	return (0);
}

int	final_rotation_ab(t_ps_hub *data, t_ps_stack *stack, t_ps_cost *cost, int pos)
{
	int	reverse;

	if (stack == data->a)
		reverse = cost->reverse_a;
	else
		reverse = cost->reverse_b;
	if (pos > 0)
	{
		if (reverse == 1)
		{
			if (rotate_or_reverse_action(data, stack, pos, reverse_rotate) != 0)
				return (EPSMAL);
		}
		else 
		{
			if (rotate_or_reverse_action(data, stack, pos, rotate) != 0)
				return (EPSMAL);
		}
	}
	return (0);
}

int	simultaneuos_action(t_ps_hub *data,
	int count ,void (*f)(t_ps_stack *))
{
	t_ps_stack *a;
	t_ps_stack *b;
	char	*protocol;
	int	x;
	
	a = data->a;
	b = data->b;
	if (f == reverse_rotate)
		protocol = data->protocols->rrr;
	else
		protocol = data->protocols->rr;
	x = -1;
	while (++x < count)
	{
		both_protocol(a, b, f);
		if (add_move(data, protocol) != 0)
				return (EPSMAL);
		(data->cost->pos_a)--;
		(data->cost->pos_b)--;
	}
	return (0);
}

int	final_rotation_simultaneous(t_ps_hub *data, t_ps_cost *cost)
{
	int	count;
	void (*f)(t_ps_stack *);
	
	if (cost->pos_a > 0 && cost->pos_b > 0 && cost->reverse_a == cost->reverse_b)
	{
		if (cost->pos_a <= cost->pos_b)
			count = cost->pos_a;
		else if (cost->pos_b < cost->pos_a)
			count = cost->pos_b;
		if (cost->reverse_a == 1 && cost->reverse_b == 1)
			f = reverse_rotate;
		else
			f = rotate;
		if (simultaneuos_action(data, count, f) != 0)
			return (EPSMAL);
	}
	return 0;
}

int	find_which_to_push(t_ps_hub* data, t_ps_stack *b, t_ps_stack *a)
{
	t_ps_cost *cost;
	
	if (data->cost == NULL && struct_init((void **)&data->cost, sizeof(t_ps_cost)) != 0)
		return (EPSMAL);
	cost = data->cost;
	find_best_move_in_b(data, b, cost);
	if (final_rotation_simultaneous(data, cost) != 0)
		return (EPSMAL);
	if (final_rotation_ab(data, a, cost, cost->pos_a) != 0)
		return (EPSMAL);
	if (final_rotation_ab(data, b, cost, cost->pos_b) != 0)
		return (EPSMAL);
	push(b, a);
			if (add_move(data, data->protocols->pa) != 0)
				return (EPSMAL);
	if (b->count > 0)
		find_which_to_push(data, b, a);
	return (0);
}