/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:26:52 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 00:24:47 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"


// void	find_best_move_in_b(t_ps_hub *data, t_ps_stack *b, t_ps_cost *cost)
// {
// 	t_list *current;
// 	int	reverse_a;
// 	int	reverse_b;
// 	int	pos_a;
// 	int	pos_b;
// 	int	temp_pos_b;

// 	current = b->head;
// 	pos_b = 0;
// 	cost->best_step = INT_MAX;
// 	while (current != NULL)
// 	{
// 		reverse_a = 0;
// 		reverse_b = 0;
// 		pos_a = find_insert_position(data, data->a, *((int *)current->content));
// 		temp_pos_b = pos_b;
// 		if (b->count - temp_pos_b < pos_b)
// 		{
// 			temp_pos_b = b->count - temp_pos_b;
// 			reverse_b = 1;
// 		}
// 		else
// 			reverse_b = 0;
// 		if (data->a->count - pos_a < pos_a)
// 		{
// 			pos_a = data->a->count - pos_a;
// 			reverse_a = 1;
// 		}
// 		else
// 			reverse_a = 0;
// 		if (pos_a + temp_pos_b < cost->best_step)
// 		{
// 			cost->best_step = pos_a + temp_pos_b;
// 			cost->pos_a = pos_a;
// 			cost->pos_b = temp_pos_b;
// 			cost->reverse_a = reverse_a;
// 			cost->reverse_b = reverse_b;
// 		}
// 		// if (cost->best_step <= 3)
// 		// 	return ;
// 		current = current->next;
// 		pos_b++;
// 	}
// }


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

int	find_which_to_push(t_ps_hub* data, t_ps_stack *b, t_ps_stack *a)
{
	t_ps_cost *cost;

	if (data->cost == NULL && struct_init((void **)&data->cost, sizeof(t_ps_cost)) != 0)
		return (EPSMAL);
	cost = data->cost;
	find_best_move_in_b(data, b, cost);
	// if (cost->pos_a > 0)
	// {
	// 	if (cost->reverse_a == 1)
	// 	{
	// 		if (rotate_or_reverse_stack_a(data, a, cost->pos_a, reverse_rotate) != 0)
	// 			return (EPSMAL);
	// 	}
	// 	else 
	// 	{
	// 		if (rotate_or_reverse_stack_a(data, a, cost->pos_a, rotate) != 0)
	// 			return (EPSMAL);
	// 	}
	// }
	// if (cost->pos_b > 0)
	// {
	// 	if (cost->reverse_b == 1)
	// 	{
	// 		if(rotate_or_reverse_stack_a(data, b, cost->pos_b, reverse_rotate) != 0)
	// 			return (EPSMAL);
	// 	}
	// 	else
	// 	{
	// 		if (rotate_or_reverse_stack_a(data, b, cost->pos_b, rotate) != 0)
	// 			return (EPSMAL);
	// 	}
	// }
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