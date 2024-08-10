/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:37:54 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 21:45:51 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PARTITION_H
# define PUSH_SWAP_PARTITION_H

int			count_ascend_series(t_ps_stack *a);
void		extract_last_ascend(t_ps_stack *a,
				t_ps_series *series, t_list *current, int count);
t_ps_series	*store_series(t_ps_hub *data, t_ps_stack *a,
				int (*f_ascend)(t_ps_stack *));
int			add_to_stack_x(t_ps_stack *x, int *length,
				int *content, void (*f)(t_ps_stack *));
int			add_to_x_series(t_ps_stack *x, t_list *current);
int			add_to_x_tail_prev(t_ps_hub *data, t_ps_stack *x, t_list *current);
int			add_to_end_series(t_ps_stack *a,
				t_ps_stack *x, t_list *current);
int			swap_head_to_next_series(t_ps_stack *x, t_list *current);
int			add_to_head_series(t_ps_stack *x, t_list *current);
int			x_tail_prev_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current);
int			rotate_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current);
int			swap_series(t_ps_hub *data, t_ps_stack *a, t_ps_stack *x, t_list *current);
int			body_of_separation_ext(t_ps_hub *data, t_ps_stack *x, t_list *current);
int			body_of_separation(t_ps_hub *data, t_ps_stack *x, t_list *current);
int			separation(t_ps_hub *data);

#endif