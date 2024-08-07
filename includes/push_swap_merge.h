/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:05:01 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 00:26:02 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MERGE_H
# define PUSH_SWAP_MERGE_H

void	current_min_max(t_ps_stack *a, int *min, int *max);
int	rotate_or_reverse_action(t_ps_hub *data,
	t_ps_stack *stack, int count ,void (*f)(t_ps_stack *));

#endif
