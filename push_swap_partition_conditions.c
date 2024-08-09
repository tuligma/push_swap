/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition_conditions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:10:59 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 23:20:47 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	add_to_x_series(t_ps_stack *x, t_list *current)
{
	return (current->next != NULL
		&& *((int *)current->next->content) == *((int *)x->head->content)
		&& *((int *)current->content) < *((int *)x->head->content));
}

// put head node to tail if greater than current series tail!!!
int	add_to_end_series(t_ps_stack *a,
	t_ps_stack *x, t_list *current)
{
	return (x->tail != NULL
		&& *((int *)a->tail->content) == *((int *)x->tail->content)
		&& *((int *)current->content) > *((int *)x->tail->content));
}

//swap if the head is greater than next and less than next-next
int	swap_head_to_next_series(t_ps_stack *x, t_list *current)
{
	return ((current->next != NULL && x->head != NULL
			&& x->head->next != NULL)
		&& (*((int *)current->next->content) == *((int *)x->head->content))
		&& (*((int *)current->content) > *((int *)x->head->content)
			&& *((int *)current->content) < *((int *)x->head->next->content)));
}

// reverse rotate if the current head and series head is aligned
int	add_to_head_series(t_ps_stack *x, t_list *current)
{
	return (x->head != NULL
		&& *((int *)current->content) == *((int *)x->head->content));
}