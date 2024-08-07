/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:26:43 by npentini          #+#    #+#             */
/*   Updated: 2024/08/07 19:41:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	count_ascend_series(t_ps_stack *a)
{
	t_list	*current;
	int		count;
	int		max_count;

	current = a->head;
	count = 1;
	max_count = 1;
	while (current != NULL && current->next != NULL)
	{
		if (*((int *)current->content) < *((int *)current->next->content))
		{
			count++;
			if (count > max_count)
				max_count = count;
		}
		else
			count = 1;
		current = current->next;
	}
	return (max_count);
}

void	extract_last_ascend(t_ps_stack *a, t_ps_series *series,
	t_list *current, int count)
{
	int		x;
	int		y;

	x = count - 1;
	y = 0;
	while (current != NULL && current->prev != NULL)
	{
		if (*((int *)current->content) > *((int *)current->prev->content))
		{
			if (x == count - 1)
				series->end = a->count - 1 - y;
			series->series[x] = *((int *)current->content);
			x--;
			if (x == 0)
			{
				series->series[x] = *((int *)current->prev->content);
				series->start = a->count - 1 - (y + 1);
				break ;
			}
		}
		else
			x = count - 1;
		current = current->prev;
		y++;
	}
}

t_ps_series	*store_series(t_ps_hub *data, t_ps_stack *a,
	int (*f_ascend)(t_ps_stack *))
{
	t_ps_series	*series;

	if (struct_init((void **)&data->series, sizeof(t_ps_series)) != 0)
		return (NULL);
	data->series->x = ft_calloc(1, sizeof(t_ps_stack));
	if (data->series->x == NULL)
		return (NULL);
	series = data->series;
	series->length = f_ascend(a);
	series->series = ft_calloc(series->length, sizeof(int));
	if (series->series == NULL)
		return (NULL);
	extract_last_ascend(a, series, a->tail, series->length);
	return (series);
}

int	add_to_stack_x(t_ps_stack *x, int *length, int *content,
	void (*f)(t_ps_stack *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == NULL)
		return (EPSMAL);
	ft_lstadd_front(&x->head, node);
	f(x);
	(*length)++;
	return (0);
}
