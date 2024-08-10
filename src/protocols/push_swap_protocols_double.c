/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols_double.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:47:10 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 21:17:48 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*pop_head(t_ps_stack *stack)
{
	t_list	*node;

	node = stack->head;
	if (stack->count > 0)
	{
		stack->head = stack->head->next;
		if (stack->head != NULL)
			stack->head->prev = NULL;
		else
			stack->tail = NULL;
		stack->count--;
	}
	return (node);
}

void	push_head(t_ps_stack *stack, t_list *node)
{
	if (node == NULL)
		return ;
	node->next = stack->head;
	if (stack->head != NULL)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->count++;
}

void	push(t_ps_stack *pop, t_ps_stack *push)
{
	t_list	*node;

	if (pop->count > 0)
	{
		node = pop_head(pop);
		push_head(push, node);
	}
}

void	both_protocol(t_ps_stack *a,
	t_ps_stack *b, void (*fsingle)(t_ps_stack *))
{
	fsingle(a);
	fsingle(b);
}
