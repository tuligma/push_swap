/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protocols1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:20:53 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 13:25:49 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// void	both_push(t_ps_stack *a, t_ps_stack *b)
// {
// 	t_list	*node_a;
// 	t_list	*node_b;


// 	if (a->count > 0 && b->count > 0)
// 	{
// 		node_a = pop_head(a);
// 		node_b = pop_head(b);
// 		push_head(a, node_b);
// 		push_head(b, node_a);
// 	}
// }

void	push(t_ps_stack *pop, t_ps_stack *push)
{
	t_list	*node;

	if (pop->count > 0)
	{
		node = pop_head(pop);
		push_head(push, node);
	}
}

void	reverse_rotate(t_ps_stack *stack)
{
	t_list *new_tail;
	t_list *head;
	t_list *tail;
	int	count;

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
	t_list *new_head;
	t_list *head;
	t_list *tail;
	int	count;

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
	count	= stack->count;

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
