/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_stack_zipper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:31:11 by npentini          #+#    #+#             */
/*   Updated: 2024/08/02 00:11:42 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	add_move(t_ps_hub *data, char *move)
{
	t_list	*node;

	node = ft_lstnew((void *)move);
	if (node == NULL)
		return (EPSMAL);
	if (data->moves == NULL)
		data->moves = node;
	else
		ft_lstadd_back(&data->moves, node);
	data->total_moves++;
	return (0);
}

int	sort_head_a(t_ps_hub *data)
{
	t_ps_stack	*a;
	int			content1;
	int			content2;

	a = data->a;
	content1 = *((int *)a->head->content);
	content2 = *((int *)a->head->next->content);
	if (content1 > content2)
	{
		swap(a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
	}
	return (0);
}

int	push_b_inbetweens_median_to_max(t_ps_hub *data)
{
	t_ps_stack	*b;
	t_ps_stack	*a;
	int			content;
	int			x;

	b = data->b;
	a = data->a;
	x = 0;
	if (b == NULL)
		return (0);
	while (++x < data->d_mid_max)
	{
		content = *((int *)b->head->content);
		if (content < data->max && content > data->median)
		{
			push(b, a);
			if (add_move(data, data->protocols->pa) != 0
				|| sort_head_a(data) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		}
		// if (x == data->d_mid_max - 1)
		// {
		// 	reverse_rotate(a);
		// 	if (add_move(data, data->protocols->rra) != 0)
		// 	return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		// }
	}
	reverse_rotate(a);
	if (add_move(data, data->protocols->rra) != 0)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}

int	push_b_inbetweens_min_to_median(t_ps_hub *data)
{
	t_ps_stack	*b;
	t_ps_stack	*a;

	b = data->b;
	a = data->a;
	while (b->count != 0)
	{
		push(b, a);
		if (add_move(data, data->protocols->pa) != 0
			|| sort_head_a(data) != 0)
			return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	}
	reverse_rotate(a);
	if (add_move(data, data->protocols->rra) != 0)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}