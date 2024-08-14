/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:19:13 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:34:56 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGORITHM_H
# define PUSH_SWAP_ALGORITHM_H

int		lst_rev_sort_checker(t_ps_stack *stack);
int		lst_sort_checker(t_ps_hub *data);
int		lst_sort_checker_circular_ext2(t_ps_stack *a, t_list *current);
int		lst_sort_checker_circular_ext1(t_ps_stack *a, t_list *current);
int		lst_sort_checker_circular(t_ps_hub *data);
void	*print_free_error(t_ps_hub *data, int error_code);
int		first_check_test(t_ps_hub *data,
			void (*f)(t_ps_stack *), char *protocol);
int		first_check_stack_a(t_ps_hub *data);
int		three_arguments(t_ps_hub *data);
int		two_arguments(t_ps_hub *data);
int		more_arguments(t_ps_hub *data);
int		(**process_init(void))(t_ps_hub *data);

#endif