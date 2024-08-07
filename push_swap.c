/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 00:34:19 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	min_to_head(t_ps_hub *data, t_ps_stack *a)
{
	t_list	*current;
	int	reverse;
	int	pos;

	current = a->head;
	pos = 0;
	reverse = 0;
	while (current != NULL)
	{
		if (*(int *)current->content == data->min)
			break ;
		pos++;
		current = current->next;
	}
	if (a->count - pos < pos)
	{
		pos = a->count - pos;
		reverse = 1;
	}
	if (reverse == 1)
	{
		if (rotate_or_reverse_action(data, a, pos, reverse_rotate) != 0)
			return (EPSMAL);
	}
	else
	{
		if (rotate_or_reverse_action(data, a, pos, rotate) != 0)
						return (EPSMAL);
	}
	return (0);
}


int	three_arguments(t_ps_hub *data)
{
	if (*((int *)data->a->head->content) == data->max)
	{
		rotate(data->a);
		if (add_move(data, data->protocols->ra) != 0)
			return (EPSMAL);	
	}
	else if (*((int *)data->a->head->next->content) == data->max)
	{
		reverse_rotate(data->a);
		if (add_move(data, data->protocols->rra) != 0)
			return (EPSMAL);
	}
	if (*((int *)data->a->head->content) > *((int *)data->a->head->next->content))
	{
		swap(data->a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
	}
	return (0);
}

int	two_argument(t_ps_hub *data)
{
	
	int			content_1;
	int			content_2;

	content_1 = *((int *)data->a->head->content);
	content_2 = *((int *)data->a->head->next->content);
	if (data->arg_count == 2 && content_1 > content_2)
	{
		swap(data->a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
	}
	return (0);
}


int	main(int argc, char *argv[])
{
	t_ps_hub *data;

	if (error_checker(argc, argv) == 1)
		return (1);
	data = init_handler(argc, argv);
	if (data == NULL)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	if (dup_checker(data) != 0 || (data->arg_count >= 3 && sort_checker(data) != 0))
		return (free_data(&data, 0, -1));
	if (data->arg_count >= 3 && position_locator(data) != 0)
		return (free_data(&data, 0, -1));
	if (push_args_to_node(data, data->a, data->args, data->arg_count) != 0)
		return (free_data(&data, 0, -1));
	ft_printf("\nStack A:\n");
	ft_lstiter(data->a->head, print_node);

	if (data->arg_count == 2)
		two_argument(data);
	else if (data->arg_count == 3)
		three_arguments(data);
	else
	{
		ft_printf("\nStack A:\n");
		ft_lstiter(data->a->head, print_node);
		int subsq = count_ascend_series(data->a);
		ft_printf("ascending series count: %d\n", subsq);
		data->series = store_series(data, data->a, count_ascend_series);
		ft_printf("start: %d | end: %d\n", data->series->start, data->series->end);
		for (int x = 0; x < data->series->length; x++)
		{
			ft_printf("%d ", data->args[data->series->start + x]);
		}
		if (push_args_to_node(data, data->series->x, data->series->series, data->series->length) != 0)
			return (free_data(&data, 0, -1));
		ft_printf("\nStack X:\n");
		ft_lstiter(data->series->x->head, print_node);
		separation(data);

		find_which_to_push(data, data->b, data->a);
		ft_printf("\nMerging:\n");
		ft_printf("\nStack A:\n");
		ft_lstiter(data->a->head, print_node);
		ft_printf("\nStack B:\n");
		ft_lstiter(data->b->head, print_node);
		min_to_head(data, data->a);
		ft_printf("\nArrange:\n");
		ft_printf("\nStack A:\n");
		ft_lstiter(data->a->head, print_node);
	}
	// // ft_printf("\nSeparation:\n");
	// // ft_printf("\nStack A:\n");
	// // ft_lstiter(data->a->head, print_node);
	// // ft_printf("\nStack B:\n");
	// // ft_lstiter(data->b->head, print_node);

	// // // ft_printf("min: %d | median: %d | max: %d | d_mid_max: %d | d_min_mid: %d | arg_count: %d\n", data->min, data->median, data->max, data->d_mid_max, data->d_min_mid, data->arg_count);
	// // // sort_partition_a(data);
	// // // sort_partition_b(data);
	// // ft_printf("\nSort:\n");
	// // ft_printf("\nStack A:\n");
	// // ft_lstiter(data->a->head, print_node);
	// // ft_printf("\nStack B:\n");
	// // ft_lstiter(data->b->head, print_node);
	
	// // push_b_inbetweens_median_to_max(data);
	// // push_b_inbetweens_min_to_median(data);

	// // ft_printf("\nSort:\n");
	// // ft_printf("\nStack A:\n");
	// // ft_lstiter(data->a->head, print_node);
	// // ft_printf("\nStack B:\n");
	// // ft_lstiter(data->b->head, print_node);

	if (!lst_sort_checker(data->a))
		print_moves(data->moves);
	// // // ft_printf("\nAfter:\n");
	// // // ft_lstiter(data->a->head, print_node);
	ft_printf("\ntotal moves: %d\n\n", data->total_moves);
	if (lst_sort_checker(data->a) == 0)
	{
		ft_printf("\nstack a:\n");
		ft_lstiter(data->a->head, print_node);
		ft_printf("Sorted asf!!!\n\n");
	}
	free_data(&data, 0, -1);
	return (0);
}