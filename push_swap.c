/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/08/01 05:13:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// int min_to_median(t_ps_hub *data)
// {
// 	t_ps_stack *b;
// 	t_ps_stack  *a;
// 	int content1;

// 	b = data->b;
// 	a = data->a;
// 	while (b->count != 0)
// 	{
// 		content1 = *((int *)b->head->content);
// 		if (content1 > data->min && content1 < data->median)
// 		{
// 			push(b, a);
// 			if (add_move(data, data->protocols->sb) != 0 || sort_head_a(data) != 0)
// 				return (EPSMAL);
// 		}
// 	}
// 	reverse_rotate(a);
// 	if (add_move(data, data->protocols->rra) != 0)
// 		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
// 	return (0);
// }


// int median_to_max(t_ps_hub *data)
// {
// 	t_ps_stack *b;
// 	t_ps_stack  *a;
// 	int content1;
// 	int	x;
// 	// int	content2;

// 	b = data->b;

int	lst_sort_checker(t_ps_stack *stack)
{
	t_list *current;
	int content1;
	int	content2;
	
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

int	lst_rev_sort_checker(t_ps_stack *stack)
{
	t_list *current;
	int content1;
	int	content2;
	
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

int	add_move(t_ps_hub *data, char *move)
{
	t_list *node;
	
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

int sort_head_a(t_ps_hub *data)
{
	t_ps_stack *a;
	int content1;
	int	content2;

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

int	partition(t_ps_hub *data)
{
	t_ps_stack *a;
	t_ps_stack *b;
	int	content;
	
	a = data->a;
	b = data->b;
	while (data->a->count > 3)
	{
		content = *((int*)a->head->content);
		if (content != data->min && content != data->median && content != data->median)
		{
			push(a,b);
			if (b->count == 1)
			{
				b->min = content;
				b->max = content;
			}
			else
			{
				if (content < b->min)
					b->min = content;
				if (content > b->max)
					b->max = content;
			}
			
			if (add_move(data, data->protocols->pb) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		}
		else
		{
			rotate(a);
			if (add_move(data, data->protocols->ra) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		}
	}
	return (0);
}


// 	a = data->a;
// 	x = -1;
// 	while (++x < data->d_mid_max)
// 	{
// 		content1 = *((int *)b->head->content);
// 		if (content1 > data->median && content1 < data->max)
// 		{
// 			push(b, a);
// 			if (add_move(data, data->protocols->sb) != 0 || sort_head_a(data) != 0)
// 				return (EPSMAL);
// 		}
// 		else
// 		{
// 			rotate(b);
// 			if (add_move(data, data->protocols->rb) != 0)
// 				return (EPSMAL);
// 		}
// 		x++;
// 	}
// 	reverse_rotate(a);
// 	if (add_move(data, data->protocols->rra) != 0)
// 		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
// 	return (0);
// }

int	sort_partition_b(t_ps_hub *data)
{
	t_ps_stack *b;
	int content1;
	int	content2;

	b = data->b;
	content1 = *((int *)b->head->content);
	content2 = *((int *)b->head->next->content);
	while(lst_rev_sort_checker(b) != 0)
	{
		content1 = *((int *)b->head->content);
		content2 = *((int *)b->head->next->content);
		if (content1 == b->min && content2 == b->max)
		{
			rotate(b);
			if (add_move(data, data->protocols->rb) != 0)
				return (EPSMAL);
		}
		else if (content1 < content2)
		{
			swap(b);
			if (add_move(data, data->protocols->sb) != 0)
			return (EPSMAL);
		}
		else
		{
			rotate(b);
			if (add_move(data, data->protocols->rb) != 0)
				return (EPSMAL);
		}
	}
	return (0);
}

	int	sort_partition_x(t_ps_hub *data)
	{
		t_ps_stack *a;
		int content1;
		int	content2;

		a = data->a;
		content1 = *((int *)a->head->content);
		content2 = *((int *)a->head->next->content);
		while(1)
		{
			content1 = *((int *)a->head->content);
			content2 = *((int *)a->head->next->content);
			if (content1 == data->max && content2 == data->min)
				break ;
			if (content1 < content2)
			{
				swap(a);
				if (add_move(data, data->protocols->sa) != 0)
				return (EPSMAL);
			}
			else
			{
				rotate(a);
				if (add_move(data, data->protocols->ra) != 0)
					return (EPSMAL);
			}
		}
		return (0);
}

int sort_partition_a(t_ps_hub *data)
{
	t_ps_stack *a;
	int content1;
	int	content2;

	a = data->a;
	content1 = *((int *)a->head->content);
	content2 = *((int *)a->head->next->content);
	if (content1 == data->median && content2 == data->min)
	{
		swap(a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
		reverse_rotate(a);
		if (add_move(data, data->protocols->rra) != 0)
			return (EPSMAL);
	}
	else if (content1 == data->median && content2 == data->max)
	{
		swap(a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
	}
	else if (content1 == data->max && content2 == data->median)
	{
		swap(a);
		if (add_move(data, data->protocols->sa) != 0)
			return (EPSMAL);
		rotate(a);
		if (add_move(data, data->protocols->ra) != 0)
			return (EPSMAL);
	}
	else if (content1 == data->min && content2 == data->max)
	{
		rotate(a);
		if (add_move(data, data->protocols->ra) != 0)
			return (EPSMAL);
	}
	return (0);
}

int	sort_stack_median(t_ps_hub *data)
{
	t_ps_stack *b;
	t_ps_stack *a;
	int	content;
	int	x;

	b = data->b;
	a = data->a;
	x = -1;
	while (++x < data->d_mid_max)
	{
		content = *((int *)b->head->content);
		if (content < data->max && content > data->median)
		{
			push(b,a);
			if (add_move(data, data->protocols->pa) != 0 || sort_head_a(data) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		}
	}
	reverse_rotate(a);
	if (add_move(data, data->protocols->rra) != 0)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}

int	sort_stack_min(t_ps_hub *data)
{
	t_ps_stack *b;
	t_ps_stack *a;

	b = data->b;
	a = data->a;
	while (b->count != 0)
	{
		push(b,a);
		if (add_move(data, data->protocols->pa) != 0)
			return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		// sort_head_a(data);
	}
	reverse_rotate(a);
	if (add_move(data, data->protocols->rra) != 0)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}

void	print_moves(t_list *moves)
{
	t_list *current;
	char	*str;
	
	current = moves;
	while(current != NULL)
	{
		str = (char *)current->content;
		ft_printf("%s\n", str);
		current = current->next;
	}
}

void	print_protocols(void **moves)
{
	int	x;
	
	x = -1;
	while(++x < PROTO_COUNT)
	{
		ft_printf("%s -> move: %d\n", (char *)moves[x], x);
	}
}

int	main(int argc, char *argv[])
{
	t_ps_hub *data;
	
	if (error_checker(argc, argv) == 1)
		return (1);
	data = init_handler(argc, argv);
	if (data == NULL)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	if (dup_checker(data) != 0 || sort_checker(data) != 0)
		return (free_data(&data, 0, -1));
	if (position_locator(data) != 0)
		return (free_data(&data, 0, -1));
	if (push_args_to_node(data) != 0)
		return (free_data(&data, 0, -1));
	partition(data);
	sort_partition_a(data);
	sort_partition_b(data);
	sort_stack_median(data);
	sort_stack_min(data);


	// if (lst_sort_checker(data->a))
	// ft_printf("\n");
	print_moves(data->moves);
	// ft_printf("\ntotal moves: %d\n\n", data->total_moves);
	// if (lst_sort_checker(data->a) == 0)
	// {
	// 	ft_printf("\nstack a:\n");
	// 	ft_lstiter(data->a->head, print_node);
	// 	ft_printf("Sorted asf!!!");
	// }
	free_data(&data, 0, -1);
	return (0);
}