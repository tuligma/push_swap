/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_per_args.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:39:59 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 12:12:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	first_check_test(t_ps_hub *data, void (*f)(t_ps_stack *), char *protocol)
{
	t_ps_stack	*a;
	void		(*undo)(t_ps_stack *);

	if (f == rotate)
		undo = reverse_rotate;
	else if (f == reverse_rotate)
		undo = rotate;
	else if (f == swap)
		undo = f;
	a = data->a;
	f(a);
	if (lst_sort_checker_circular(data) == 0)
	{
		undo(a);
		move_single(f, a, protocol, data);
		min_to_head(data, a);
		return (0);
	}
	else
		undo(a);
	return (1);
}

int	first_check_stack_a(t_ps_hub *data)
{
	if (lst_sort_checker_circular(data) != 0)
	{
		if (first_check_test(data, rotate, STR_RA) == 0)
			return (0);
		else if (first_check_test(data, reverse_rotate, STR_RRA) == 0)
			return (0);
		else if (first_check_test(data, swap, STR_SA) == 0)
			return (0);
		return (1);
	}
	else
		min_to_head(data, data->a);
	return (0);
}

int	two_arguments(t_ps_hub *data)
{
	int	content_1;
	int	content_2;

	if (data->a->count != 2)
		return (0);
	content_1 = *((int *)data->a->head->content);
	content_2 = *((int *)data->a->head->next->content);
	if (content_1 > content_2)
		move_single(swap, data->a, STR_SA, data);
	return (0);
}

int	three_arguments(t_ps_hub *data)
{
	t_ps_stack	*a;

	if (data->a->count != 3)
		return (0);
	a = data->a;
	if (*((int *)a->head->content) == data->max)
		move_single(rotate, data->a, STR_RA, data);
	else if (*((int *)a->head->next->content) == data->max)
		move_single(reverse_rotate, data->a, STR_RRA, data);
	if (*((int *)a->head->content) > *((int *)a->head->next->content))
		move_single(swap, data->a, STR_SA, data);
	return (0);
}

int	more_arguments(t_ps_hub *data)
{
	if (data->arg_count < 4)
		return (0);
	if (first_check_stack_a(data) != 0)
	{
		if (separation(data) != 0)
			return (free_all(&data, EXIT_FAILURE));
		if (execute_merge(data) != 0)
			return (free_all(&data, EXIT_FAILURE));
		min_to_head(data, data->a);
	}
	min_to_head(data, data->a);
	return (0);
}
