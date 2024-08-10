/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:21:44 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 10:58:32 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PROTOCOLS_H
# define PUSH_SWAP_PROTOCOLS_H

t_list	*pop_head(t_ps_stack *stack);
void	push_head(t_ps_stack *stack, t_list *node);
void	push(t_ps_stack *pop, t_ps_stack *push);
void	reverse_rotate(t_ps_stack *stack);
void	rotate(t_ps_stack *stack);
void	swap(t_ps_stack *stack);
void	both_protocol(t_ps_stack *a, t_ps_stack *b,
			void (*f1)(t_ps_stack *));
void	move_push(t_ps_stack *push_to, char *move, t_ps_hub *data);
void	move_both(void (*f)(t_ps_stack *), char *move, t_ps_hub *data);
void	move_single(void (*f)(t_ps_stack *),
			t_ps_stack *stack, char *move, t_ps_hub *data);
void	min_to_head(t_ps_hub *data, t_ps_stack *a);
#endif