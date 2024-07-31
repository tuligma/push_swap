/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:49:42 by npentini          #+#    #+#             */
/*   Updated: 2024/07/29 20:30:51 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	struct_init(void **struct_ptr, size_t struct_size)
{
	*struct_ptr = ft_calloc(1, struct_size);
	if (*struct_ptr == NULL)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	return (0);
}

int	argument_counter(t_ps_hub *data ,char **args)
{
	int	x;

	x = 0;
	while (args[x] != NULL)
		x++;
	data->arg_count += x;
	return (0);
}

int	argument_strip(t_ps_hub *data, char **args)
{
	int	x;

	x = -1;
	while (args[++x] != NULL)
	{
		data->args[data->i] = (int)ft_atol(args[x]);
		data->i++;
	}
	return (0);
}

int	argument_extraction(t_ps_hub *data, int argc, char **argv, int (*f)(t_ps_hub*, char **))
{
	char	**args;
	int		x;
	int		result;

	x = 0;
	while (++x < argc)
	{
		args = ft_split(argv[x], ' ');
		if (args == NULL)
			return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
		result = f(data,args);
		free_array(&args, -1);
		if (result != 0)
			return (result);
	}
	return (0);
}

t_ps_hub	*init_handler(int argc, char *argv[])
{
	t_ps_hub	*data;
	int			result;

	result = struct_init((void **)&data, sizeof(t_ps_hub));
	if (result != 0)
		return(NULL);
	result = argument_extraction(data, argc, argv, argument_counter);
	if (result != 0)
		return(free_data(&data, 0, -1), NULL);
	data->args = ft_calloc(data->arg_count + 1, sizeof(int));
	if (data->args == NULL)
		return(free_data(&data, 0, -1), NULL);
	result = argument_extraction(data, argc, argv, argument_strip);
	if (result != 0)
		return(free_data(&data, 0, -1), NULL);
	result = struct_init((void **)&data->a, sizeof(t_ps_stack));
	if (result != 0)
		return(free_data(&data, 0, -1), NULL);
	result = struct_init((void **)&data->b, sizeof(t_ps_stack));
	if (result != 0)
		return(free_data(&data, 0, -1), NULL);
	return (data);
}