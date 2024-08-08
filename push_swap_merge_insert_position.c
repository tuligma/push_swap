/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_insert_position.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:04:34 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 04:02:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	current_min_max(t_ps_stack *a, int *min, int *max)
{
	t_list	*current;
	int		content;
	
	current = a->head;
	if (current != NULL)
	{
		content = *((int *)current->content);
		*min = content;
		*max = content;
		current = current->next;
	}
	while (current != NULL)
	{
		content = *((int *)current->content);
		if (content < *min)
			*min = content;
		if (content > *max)
			*max = content;
		current = current->next;
	}
}

int	insertion_position_max_min(t_list *current, int content, int max, int min)
{
	if (current->next != NULL && (content > max || content < min))
	{
		if (content < *((int *)current->content) && (*((int *)current->content) == max || *((int *)current->next->content) == min))
			return (1);
		else if (content > *((int *)current->content)  && (*((int *)current->content) == max || *((int *)current->next->content) == min))
			return (1);
	}
	return (0);
}

int	insertion_position_inbetween(t_ps_hub *data,
	t_list *current, int content, int max)
{
	if (current->next != NULL&& content == data->max  && *((int *)current->content) == max)
		return (1);
	else if (content == data->min  && *((int *)current->content) == max)
		return (1);
	else if (current->next != NULL && content > *((int *)current->content) && content < *((int *)current->next->content))
			return (1);
	return (-1);
}

int find_insert_position(t_ps_hub *data, t_ps_stack *a, int content)
{
	t_list *current;
	int	position;
	int	max;
	int	min;

	max = 0;
	min = 0;
	current_min_max(a, &min, &max);
	position = 0;
	current = a->head;
	while (current != NULL)
	{
		// if (data->d_min_mid > 0 && *((int *)current->content) < data->median)
		// {
		// 	current = current->next;
		// 	position++;
		// 	continue ;
		// }
		if (insertion_position_max_min(current, content, max, min) == 1)
			return (++position);
		if (insertion_position_inbetween(data, current, content, max) == 1)
			return (++position);
		else if (data->a->tail != NULL && current == data->a->tail && content > *((int *)current->content) && content < *((int *)data->a->head->content))
			return (0);
		current = current->next;
		position++;
	}
	return (position);
}


