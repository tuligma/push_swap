/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 13:42:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	move_push(t_ps_stack *push_to, char *move, t_ps_hub *data)
{
	t_ps_stack *pop;

	if (push_to == data->a)
		pop = data->b;
	else
		pop = data->a;
	if (pop->count > 0)
	{
		push(pop, push_to);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}

}

void	move_both(void (*f)(t_ps_stack *), char *move, t_ps_hub *data)
{
	if (data->a->count > 0 && data->b->count > 0)
	{
		both_protocol(data->a, data->b, f);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}
}

void	move_single(void (*f)(t_ps_stack *), t_ps_stack *stack, char *move, t_ps_hub *data)
{
	if (stack->count > 0)
	{
		f(stack);
		ft_printf("%s\n", move);
		(data->total_moves)++;
	}
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

void	min_to_head(t_ps_hub *data, t_ps_stack *a)
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
		rotate_or_reverse_action(data, a, pos, reverse_rotate);
	else
		rotate_or_reverse_action(data, a, pos, rotate);
}


int	three_arguments(t_ps_hub *data)
{
	if (*((int *)data->a->head->content) == data->max)
		move_single(rotate, data->a, STR_RA, data);
	else if (*((int *)data->a->head->next->content) == data->max)
		move_single(reverse_rotate, data->a, STR_RRA, data);
	if (*((int *)data->a->head->content) > *((int *)data->a->head->next->content))
		move_single(swap, data->a, STR_SA, data);
	return (0);
}

int	two_arguments(t_ps_hub *data)
{
	int	content_1;
	int	content_2;

	if (data->arg_count > 2)
		return (0);
	content_1 = *((int *)data->a->head->content);
	content_2 = *((int *)data->a->head->next->content);
	if (content_1 > content_2)
		move_single(swap, data->a, STR_SA, data);
	return (0);
}

int	free_all(t_ps_hub **data, int status)
{
	if (data != NULL && *data != NULL)
		free_data(data, 0, -1);
	if (status == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	lst_sort_checker_circular(t_ps_hub *data)
{
	t_ps_stack *a;
	t_list *current;
	t_list *start_node;
	int	content_1;
	int	content_2;

	// ft_printf("\nStack A:\n");
	// ft_lstiter(data->a->head, print_node);
	a = data->a;
	current = a->head;
	while (current != NULL && *((int *)current->content) != data->min)
		current = current->next;
	start_node = current;
	while (1)
	{
		content_1 =  *((int *)current->content);
		if (current->next == NULL)
			content_2 =  *((int *)a->head->content);
		else
			content_2 =  *((int *)current->next->content);
		if (content_1 == data->max && content_2 == data->min)
			return (0);
		if (content_1 > content_2)
			return (1);
		current = current->next;
		if (current == NULL)
			current = a->head;
		if (current == start_node)
			return (1);
	}
	return (0);
}

int	first_check_stack_a(t_ps_hub *data)
{
	t_ps_stack *a;

	a = data->a;
	rotate(a);
	if (lst_sort_checker_circular(data) == 0)
	{
		reverse_rotate(a);
		move_single(rotate, a, STR_RA, data);
		min_to_head(data, data->a);
		return (0);
	}
	else
		reverse_rotate(a);

	reverse_rotate(a);
	if (lst_sort_checker_circular(data) == 0)
	{
		rotate(a);
		move_single(reverse_rotate, a, STR_RRA, data);
		min_to_head(data, data->a);
		return (0);
	}
	else
		rotate(a);
	swap(a);
	if (lst_sort_checker_circular(data) == 0)
	{
		swap(a);
		move_single(swap, a, STR_SA, data);
		min_to_head(data, data->a);
		return (0);
	}
	else
		swap(a);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_ps_hub *data;
	int		result;

	result = error_checker(argc, argv);
	if (result == 1)
		return (EXIT_FAILURE);
	else if (result == 2)
		return (EXIT_SUCCESS);
	data = init_handler(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	else if (data->arg_count <= 1)
		return (free_all(&data, EXIT_SUCCESS));
	result = dup_checker(data);
	if (result != 0)
		return (free_all(&data, EXIT_FAILURE));
	result = sort_checker(data);
	if (result != 0)
		return (free_all(&data, EXIT_SUCCESS));
	result = position_locator(data);
	if (result != 0)
		return (free_all(&data, EXIT_FAILURE));
	result = push_args_to_stack_a(data);
	if (result != 0)
		return (free_all(&data, EXIT_FAILURE));
	// ft_printf("Success!!");
	// ft_printf("\nPush node Stack A:\n");
	// ft_lstiter(data->a->head, print_node);
	if (data->arg_count == 2)
		two_arguments(data);
	else if (data->arg_count == 3)
		three_arguments(data);
	else
	{
		if (first_check_stack_a(data) != 0)
		{
			result = separation(data);
			if (result != 0)
				return (free_all(&data, EXIT_FAILURE));
			result = execute_merge(data);
			if (result != 0)
				return (free_all(&data, EXIT_FAILURE));
			min_to_head(data, data->a);
		}
	}
	// ft_printf("\nSuccess!!");
	// ft_printf("\nArg 2 Stack A:\n");
	// ft_lstiter(data->a->head, print_node);
	// else
	// {
	// 	// ft_printf("\nStack A:\n");
	// 	// ft_lstiter(data->a->head, print_node);
	// 	// int subsq = count_ascend_series(data->a);
	// 	// ft_printf("ascending series count: %d\n", subsq);
	// 	data->series = store_series(data, data->a, count_ascend_series);
	// 	// ft_printf("start: %d | end: %d\n", data->series->start, data->series->end);
	// 	// for (int x = 0; x < data->series->length; x++)
	// 	// {
	// 	// 	ft_printf("%d ", data->args[data->series->start + x]);
	// 	// }
	// 	if (push_args_to_node(data, data->series->x, data->series->series, data->series->length) != 0)
	// 		return (free_data(&data, 0, -1));
	// 	// ft_printf("\nStack X:\n");
	// 	// ft_lstiter(data->series->x->head, print_node);
	// 	separation(data);

	// 	find_which_to_push(data, data->b, data->a);
	// 	// ft_printf("\nMerging:\n");
	// 	// ft_printf("\nStack A:\n");
	// 	// ft_lstiter(data->a->head, print_node);
	// 	// ft_printf("\nStack B:\n");
	// 	// ft_lstiter(data->b->head, print_node);
	// 	min_to_head(data, data->a);
	// 	// ft_printf("\nArrange:\n");
	// 	// ft_printf("\nStack A:\n");
	// 	// ft_lstiter(data->a->head, print_node);
	// }
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

	// ft_printf("\nSort:\n");
	// ft_printf("\nStack A:\n");
	// ft_lstiter(data->a->head, print_node);
	// ft_printf("\nStack B:\n");
	// ft_lstiter(data->b->head, print_node);

	// // if (!lst_sort_checker(data->a))
	// // 	print_moves(data->moves);
	// // // // // ft_printf("\nAfter:\n");
	// // // // // ft_lstiter(data->a->head, print_node);
	// ft_printf("\ntotal moves: %d\n\n", data->total_moves);
	// if (lst_sort_checker(data->a) == 0)
	// {
	// 	// ft_printf("\nstack a:\n");
	// 	// ft_lstiter(data->a->head, print_node);
	// 	ft_printf("Sorted asf!!!\n\n");
	// }
	free_data(&data, 0, -1);
	return (0);
}