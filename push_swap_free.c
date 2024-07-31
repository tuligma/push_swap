/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:34:48 by npentini          #+#    #+#             */
/*   Updated: 2024/07/31 23:36:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_struct_array(void **array, int x)
{
	if (array != NULL && *array!= NULL)
	{
		while (++x < PROTO_COUNT)
		{
			free(array[x]);
			array[x] = NULL;
		}
	}
}

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

void	free_node(void *content)
{
	(void)content;
}

void	free_data_0(t_ps_hub **data, int x)
{
	free_data(data, 11, x);
	if ((*data)->args != NULL)
		free((*data)->args);
	ft_lstclear(&(*data)->a->head, free_node);
	ft_lstclear(&(*data)->b->head, free_node);
	ft_lstclear(&(*data)->moves, free_node);
	if ((*data)->protocols != NULL)
	{
		if ((*data)->protocols->sa != NULL)
			free_struct_array((void **)&(*data)->protocols->sa, x);
		free((*data)->protocols);
		(*data)->protocols = NULL;
	}
	if ((*data)->a != NULL)
	{
		free((*data)->a);
		(*data)->a = NULL;
	}
	if ((*data)->b != NULL)
	{
		free((*data)->b);
		(*data)->b = NULL;
	}
	(*data)->args = NULL;
	free(*data);
	*data = NULL;
	data = NULL;
}

int	free_data(t_ps_hub **data, int which_to_free, int x)
{
	if (data != NULL && *data != NULL  && which_to_free != -1)
	{
		if (which_to_free == 11 && *data != NULL && (*data)->args != NULL)
			free_int_array(&(*data)->args);
		if (which_to_free == 0)
			free_data_0(data, x);
	}
	return (1);
}
