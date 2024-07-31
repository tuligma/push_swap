/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/08/01 00:57:04 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	lst_sort_checker(t_ps_stack *stack)
{
	t_list *current;

	current = stack->head;
	while (current != NULL && current->next != NULL)
	{
		if (current->content > current->next->content)
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

int	partition(t_ps_hub *data)
{
	t_ps_stack *a;
	t_ps_stack *b;
	int	content;
	int	size;
	
	a = data->a;
	b = data->b;
	size = a->count;
	while (data->b->count < size - 1)
	{
		content = *((int*)a->head->content);
		if (content < data->max)
		{
			push(a,b);
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
		 if (content < data->max && content >= data->median)
		{
			push(b,a);
			if (add_move(data, data->protocols->pa) != 0 || sort_head_a(data) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		} 
		else
		{
			rotate(b);
			if (add_move(data, data->protocols->rb) != 0)
				return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		}
	}
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
		if (add_move(data, data->protocols->pa) != 0 || sort_head_a(data) != 0)
			return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	}
	return (0);
}

void	print_moves(t_list *moves)
{
	t_list *current;
	int	x;
	char	*str;
	
	current = moves;
	x = -1;
	while(current != NULL)
	{
		str = (char *)current->content;
		ft_printf("%s -> move: %d\n", str, ++x);
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
	ft_printf("\nOriginal:\n");
	ft_lstiter(data->a->head, print_node);
	partition(data);
	sort_stack_median(data);
	sort_stack_min(data);
	ft_printf("\nstack a:\n");
	ft_lstiter(data->a->head, print_node);
	ft_printf("\nstack b:\n");
	ft_lstiter(data->b->head, print_node);
	ft_printf("\n");
	print_moves(data->moves);
	ft_printf("\ntotal moves: %d\n\n", data->total_moves);
	free_data(&data, 0, -1);
	return (0);
}