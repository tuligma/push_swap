/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_presort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:23:48 by npentini          #+#    #+#             */
/*   Updated: 2024/08/08 14:18:53 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_advanced_sort(int *args, int size)
{
	int	temp;
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size - 1 - y)
		{
			if (args[x] > args[x + 1])
			{
				temp = args[x];
				args[x] = args[x + 1];
				args[x + 1] = temp;
			}
		}
	}
}

int	*array_dup(int *args, int size)
{
	int	*sorted_args;
	int	x;

	sorted_args = ft_calloc(sizeof(int), size);
	if (sorted_args == NULL)
		return (NULL);
	x = -1;
	while (++x < size)
		sorted_args[x] = args[x];
	return (sorted_args);
}

int	position_locator(t_ps_hub *data)
{
	int	*sorted_args;
	int	x;
	
	if (data->arg_count < 3)
		return (0);
	sorted_args = array_dup(data->args, data->arg_count);
	if (sorted_args == NULL)
		return (error_print(ERR_MALLOC_FAILED));
	ft_advanced_sort(sorted_args, data->arg_count);
	data->min = sorted_args[0];
	data->max = sorted_args[data->arg_count - 1];
	if (data->arg_count % 2 == 0)
		data->median = sorted_args[(data->arg_count / 2) - 1];
	else
		data->median = sorted_args[data->arg_count / 2];
	x = 0;
	while (sorted_args[x] != data->median)
		x++;
	data->d_min_mid = x + 1;
	data->d_mid_max = data->arg_count - data->d_min_mid;
	free(sorted_args);
	return (0);
}
