/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:30:31 by npentini          #+#    #+#             */
/*   Updated: 2024/07/31 23:22:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_node(void *content)
{
	ft_printf("node: ");
	ft_printf("%d\n", *(int*)content);
}

int	moves_bind_init(void **moves, char **str)
{
	int	x;

	x = -1;
	while (++x < PROTO_COUNT)
	{
		moves[x] = ft_strdup(str[x]);
		if (str == NULL)
			return (EPSMAL);
	}
	return (0);
}

int	moves_init(t_ps_hub *data)
{
	char	**str;
	int			result;

	result = struct_init((void **)&data->protocols, sizeof(t_ps_move));
	if (result != 0)
		return (EPSMAL);
	str = ft_calloc(PROTO_COUNT, sizeof(char *));
	if (str == NULL)
		return (EPSMAL);
	str[0] = STR_SA;
	str[1] = STR_SB;
	str[2] = STR_SS;
	str[3] = STR_PA;
	str[4] = STR_PB;
	str[5] = STR_RA;
	str[6] = STR_RB;
	str[7] = STR_RR;
	str[8] = STR_RRA;
	str[9] = STR_RRB;
	str[10] = STR_RRR;
	if (moves_bind_init((void **)&data->protocols->sa, str) != 0)
	{
		free(str);
		return (EPSMAL);
	}
	// print_protocols((void **)&data->protocols->sa);
	free(str);
	return (result);
}

int	push_args_to_node(t_ps_hub *data)
{
	t_list *node;
	int			x;

	x = -1;
	while (++x < data->arg_count)
	{
		node = ft_lstnew(&data->args[x]);
		if (node == NULL)
			return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		if (x == 0)
		{
			data->a->head = node;
		}
		else
			ft_lstadd_back(&data->a->head, node);
	}
	data->a->tail = ft_lstlast(data->a->head);
	data->a->count = data->arg_count;
	if (moves_init(data) != 0)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}