/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:32:24 by npentini          #+#    #+#             */
/*   Updated: 2024/08/12 14:07:37 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_int_array(int **array)
{
	if (array != NULL && *array != NULL)
	{
		free(*array);
		*array = NULL;
		array = NULL;
	}
}

void	free_array(char ***array, int x)
{
	if (array != NULL && *array != NULL)
	{
		while ((*array)[++x] != NULL)
		{
			free((*array)[x]);
			(*array)[x] = NULL;
		}
		free((*array)[x]);
		(*array)[x] = NULL;
		free(*array);
		*array = NULL;
	}
}

void	free_stack_list(t_ps_stack **stack)
{
	if (stack != NULL && *stack != NULL)
	{
		if ((*stack)->head != NULL)
			ft_lstclear(&(*stack)->head, free_node);
		(*stack)->head = NULL;
		free(*stack);
		*stack = NULL;
	}
}

void	free_series(t_ps_series **series)
{
	if (series != NULL && *series != NULL)
	{
		if ((*series)->series != NULL)
			free_int_array(&(*series)->series);
		free_stack_list(&(*series)->x);
		free(*series);
		*series = NULL;
	}
}
