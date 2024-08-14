/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:35:34 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:29:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	lst_rev_sort_checker(t_ps_stack *stack)
{
	t_list	*current;
	int		content1;
	int		content2;

	current = stack->head;
	while (current != NULL && current->next != NULL)
	{
		content1 = *((int *)current->content);
		content2 = *((int *)current->next->content);
		if (content1 < content2)
			return (1);
		current = current->next;
	}
	return (0);
}

int	lst_sort_checker(t_ps_hub *data)
{
	t_list	*current;
	int		content1;
	int		content2;

	current = data->a->head;
	while (current != NULL && current->next != NULL)
	{
		content1 = *((int *)current->content);
		content2 = *((int *)current->next->content);
		if (content1 > content2)
			return (1);
		current = current->next;
	}
	return (0);
}

int	lst_sort_checker_circular_ext2(t_ps_stack *a,
	t_list *current)
{
	int	content_1;
	int	content_2;
	int	min;
	int	max;

	min = 0;
	max = 0;
	current_min_max(a, &min, &max);
	content_1 = *((int *)current->content);
	if (current->next == NULL)
		content_2 = *((int *)a->head->content);
	else
		content_2 = *((int *)current->next->content);
	if (content_1 == max && content_2 == min)
		return (0);
	if (a->tail != NULL
		&& *((int *)a->tail->content) == max
		&& content_2 != min)
		return (1);
	else if (content_1 > content_2)
		return (1);
	return (0);
}

int	lst_sort_checker_circular_ext1(t_ps_stack *a,
	t_list *current)
{
	t_list	*start;

	start = current;
	while (1)
	{
		if (lst_sort_checker_circular_ext2(a, current) != 0)
			return (1);
		current = current->next;
		if (current == NULL)
			current = a->head;
		if (current == start)
			break ;
	}
	return (0);
}

int	lst_sort_checker_circular(t_ps_hub *data)
{
	t_ps_stack	*a;
	t_list		*current;
	int			min;
	int			max;

	a = data->a;
	current = a->head;
	current_min_max(a, &min, &max);
	while (current != NULL && *((int *)current->content) != min)
		current = current->next;
	if (lst_sort_checker_circular_ext1(a, current) != 0)
		return (1);
	return (0);
}
