/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:21:44 by npentini          #+#    #+#             */
/*   Updated: 2024/08/07 11:21:00 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PROTOCOLS_H
# define PUSH_SWAP_PROTOCOLS_H

t_list	*pop_head(t_ps_stack *stack);
void	push_head(t_ps_stack *stack, t_list *node);
// void	both_push(t_ps_stack *a, t_ps_stack *b);
void	push(t_ps_stack *pop, t_ps_stack *push);
void	reverse_rotate(t_ps_stack *stack);
void	rotate(t_ps_stack *stack);
void	swap(t_ps_stack *stack);
void	both_protocol(t_ps_stack *a, t_ps_stack *b,
			void (*f1)(t_ps_stack *));
#endif