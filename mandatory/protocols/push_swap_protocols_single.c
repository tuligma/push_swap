/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols_single.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:20:53 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 21:17:45 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_ps_stack *stack)
{
	t_list	*new_tail;
	t_list	*head;
	t_list	*tail;
	int		count;

	head = stack->head;
	tail = stack->tail;
	count = stack->count;
	if (count > 1)
	{
		new_tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		stack->head = tail;
		stack->tail = new_tail;
		stack->tail->next = NULL;
		stack->head->prev = NULL;
	}
}

void	rotate(t_ps_stack *stack)
{
	t_list	*new_head;
	t_list	*head;
	t_list	*tail;
	int		count;

	head = stack->head;
	tail = stack->tail;
	count = stack->count;
	if (count > 1)
	{
		new_head = head->next;
		tail->next = head;
		head->prev = tail;
		head->next = NULL;
		stack->tail = head;
		stack->head = new_head;
		stack->head->prev = NULL;
	}
}

void	swap(t_ps_stack *stack)
{
	t_list	*head;
	t_list	*node_1;
	t_list	*node_2;
	int		count;

	head = stack->head;
	count = stack->count;
	if (count > 1)
	{
		node_1 = head;
		node_2 = head->next;
		if (node_2 != NULL)
		{
			node_1->next = node_2->next;
			if (node_1->next != NULL)
				node_1->next->prev = node_1;
			else
				stack->tail = node_1;
			node_2->next = node_1;
			node_2->prev = NULL;
			node_1->prev = node_2;
			stack->head = node_2;
		}
	}
}
