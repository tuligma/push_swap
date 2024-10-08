/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:34:48 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:31:25 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*print_free_error(t_ps_hub *data, int error_code)
{
	error_print(error_code);
	if (data != NULL)
		free_data(&data);
	return (NULL);
}

int	free_all(t_ps_hub **data, int status)
{
	if (data != NULL && *data != NULL)
		free_data(data);
	if (status == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

void	free_node(void *content)
{
	(void)content;
}

void	free_others(t_ps_hub **data)
{
	if ((*data)->process != NULL)
	{
		free((*data)->process);
		(*data)->process = NULL;
	}
	if ((*data)->cost != NULL)
	{
		free((*data)->cost);
		(*data)->cost = NULL;
	}
	if ((*data)->checker != NULL)
	{
		if ((*data)->checker->head != NULL)
			ft_lstclear(&(*data)->checker->head, free);
		free((*data)->checker);
		(*data)->checker = NULL;
	}
}

int	free_data(t_ps_hub **data)
{
	if (data != NULL && *data != NULL)
	{
		free_int_array(&(*data)->args);
		free_stack_list(&(*data)->a);
		free_stack_list(&(*data)->b);
		free_series(&(*data)->series);
		free_others(data);
		free(*data);
		*data = NULL;
		data = NULL;
	}
	return (1);
}
