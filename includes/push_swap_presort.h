/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_presort.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:24:41 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 20:24:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PRESORT_H
# define PUSH_SWAP_PRESORT_H

void	ft_advanced_sort(int *args, int size);
int		*array_dup(int *args, int size);
int		position_locator(t_ps_hub *data);
int		push_args_to_stack_a(t_ps_hub *data);
int		push_args_to_stack_x(t_ps_hub *data);

#endif