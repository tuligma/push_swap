/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:19:13 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 20:05:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGORITHM_H
# define PUSH_SWAP_ALGORITHM_H





int		add_move(t_ps_hub *data, char *move);
int		sort_head_a(t_ps_hub *data);
int		push_b_inbetweens_median_to_max(t_ps_hub *data);
int		push_b_inbetweens_min_to_median(t_ps_hub *data);
int		lst_sort_checker(t_ps_stack *stack);
int		lst_rev_sort_checker(t_ps_stack *stack);
void	print_moves(t_list *moves);
void	print_protocols(void **moves);
int	sort_partition_x(t_ps_hub *data);
int	sort_partition_x_ext(t_ps_hub *data, int content1, int content2);




#endif