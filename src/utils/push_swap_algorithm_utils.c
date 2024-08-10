/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:35:34 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 00:36:22 by npentini         ###   ########.fr       */
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

int	lst_sort_checker(t_ps_stack *stack)
{
	t_list	*current;
	int		content1;
	int		content2;

	current = stack->head;
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

int	lst_sort_checker_circular_ext(t_ps_hub *data,
	t_ps_stack *a, t_list *current)
{
	t_list	*start;
	int		content_1;
	int		content_2;

	start = current;
	while (1)
	{
		content_1 = *((int *)current->content);
		if (current->next == NULL)
			content_2 = *((int *)a->head->content);
		else
			content_2 = *((int *)current->next->content);
		if (content_1 == data->max && content_2 == data->min)
			return (0);
		if (content_1 > content_2)
			return (1);
		current = current->next;
		if (current == NULL)
			current = a->head;
		if (current == start)
			return (1);
	}
	return (0);
}

int	lst_sort_checker_circular(t_ps_hub *data)
{
	t_ps_stack	*a;
	t_list		*current;

	a = data->a;
	current = a->head;
	while (current != NULL && *((int *)current->content) != data->min)
		current = current->next;
	if (lst_sort_checker_circular_ext(data, a, current) != 0)
		return (1);
	return (0);
}

void	*print_free_error(t_ps_hub *data, int error_code)
{
	error_print(error_code);
	if (data != NULL)
		free_data(&data);
	return (NULL);
}
