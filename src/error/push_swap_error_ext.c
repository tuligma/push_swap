/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_ext.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:42:27 by npentini          #+#    #+#             */
/*   Updated: 2024/08/09 19:35:46 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	dup_checker(t_ps_hub *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->arg_count - 1)
	{
		x = y;
		while (++x < data->arg_count)
		{
			if (data->args[y] == data->args[x])
				return (error_print(ERR_DUP_ARG));
		}
	}
	return (0);
}

int	sort_checker(t_ps_hub *data)
{
	int	x;

	x = -1;
	while (++x < data->arg_count - 1)
	{
		if (data->args[x] > data->args[x + 1])
			return (0);
	}
	return (1);
}
