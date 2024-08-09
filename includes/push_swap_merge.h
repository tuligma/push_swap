/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:05:01 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 20:08:45 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MERGE_H
# define PUSH_SWAP_MERGE_H

void	current_min_max(t_ps_stack *a, int *min, int *max);
int	insertion_position_max_min(t_list *current, int content, int max, int min);
int	insertion_position_inbetween(t_ps_hub *data,
	t_list *current, int content, int max);
int find_insert_position(t_ps_hub *data, t_ps_stack *a, int content);

int		find_rotate_or_reverse_b(t_ps_hub *data, int pos, int *rotation, char stack);
void	is_best_move_in_b(t_ps_hub *data, t_list *current, int pos_b);
void	find_best_move_in_b(t_ps_hub *data, t_ps_stack *b, t_ps_cost *cost);

void	rotate_or_reverse_action(t_ps_hub *data,
		t_ps_stack *stack, int count ,void (*f)(t_ps_stack *));
void	final_rotation_ab(t_ps_hub *data, t_ps_stack *stack, t_ps_cost *cost, int pos);
void	simultaneuos_action(t_ps_hub *data,
		int count ,void (*f)(t_ps_stack *));
void	final_rotation_simultaneous(t_ps_hub *data, t_ps_cost *cost);
int	execute_merge(t_ps_hub* data);

#endif
