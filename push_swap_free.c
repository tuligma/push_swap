/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:34:48 by npentini          #+#    #+#             */
/*   Updated: 2024/07/28 05:48:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

// void	free_data_11(t_ps_hub **data, int x)
// {
// 	free_array(&(*data)->args, x);
// }

void	free_data_0(t_ps_hub **data, int x)
{
	free_data(data, 11, x);
	if ((*data)->args != NULL)
		free((*data)->args);
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
