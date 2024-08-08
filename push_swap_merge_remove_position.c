/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_remove_position.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:23:40 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 04:06:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		find_rotate_or_reverse_b(t_ps_hub *data, int pos, int *rotation, char stack)
{
	int	temp_pos;
	int	count;

	temp_pos = pos;
	if (stack == 'b')
		count = data->b->count;
	else
		count = data->a->count;
	if (count - temp_pos < pos)
	{
		temp_pos = count - temp_pos;
		*rotation = 1;
	}
	return (temp_pos);
}

void	is_best_move_in_b(t_ps_hub *data, t_list *current, int pos_b)
{
	t_ps_cost *cost;
	int	reverse_a;
	int	reverse_b;
	int	pos_a;
	int	temp_pos_b;

	cost = data->cost;
	reverse_a = 0;
	reverse_b = 0;
	pos_a = find_insert_position(data, data->a, *((int *)current->content));
	temp_pos_b = find_rotate_or_reverse_b(data, pos_b, &reverse_b, 'b');
	pos_a = find_rotate_or_reverse_b(data, pos_a, &reverse_a, 'a');
	if (pos_a + temp_pos_b < cost->best_step)
	{
		cost->best_step = pos_a + temp_pos_b;
		cost->pos_a = pos_a;
		cost->pos_b = temp_pos_b;
		cost->reverse_a = reverse_a;
		cost->reverse_b = reverse_b;
	}
}


void	find_best_move_in_b(t_ps_hub *data, t_ps_stack *b, t_ps_cost *cost)
{
	t_list *current;
	int	pos_b;

	current = b->head;
	pos_b = 0;
	cost->best_step = INT_MAX;
	while (current != NULL)
	{
		// if (data->d_min_mid - 2 > 0 && *((int *)current->content) < data->median)
		// {
		// 	current = current->next;
		// 	continue ;
		// }
		is_best_move_in_b(data, current, pos_b);
		current = current->next;
		pos_b++;
		// (data->d_min_mid)--;
	}
}