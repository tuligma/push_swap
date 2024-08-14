/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:17:27 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_node_int(void *content)
{
	ft_printf("node: %d\n", *((int *)content));
}

int	(**process_init())(t_ps_hub *data)
{
	int	(**process)(t_ps_hub *);

	process = ft_calloc(PROCESS_COUNT + 1, sizeof(int (*)(t_ps_hub *)));
	if (process == NULL)
		return (NULL);
	process[0] = dup_checker;
	process[1] = sort_checker;
	process[2] = position_locator;
	process[3] = push_args_to_stack_a;
	process[4] = two_arguments;
	process[5] = three_arguments;
	process[6] = more_arguments;
	process[7] = NULL;
	return (process);
}

int	main(int argc, char *argv[])
{
	t_ps_hub	*data;
	int			result;
	int			x;

	result = error_checker(argc, argv);
	if (result == 1)
		return (error_print(EXIT_FAILURE));
	else if (result == 2)
		return (EXIT_SUCCESS);
	data = init_handler(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	else if (data->arg_count <= 1)
		return (free_all(&data, EXIT_SUCCESS));
	data->process = process_init();
	if (data->process == NULL)
		return (free_all(&data, EXIT_FAILURE));
	x = -1;
	while (data->process[++x] != NULL)
	{
		result = data->process[x](data);
		if (result != 0)
			return (free_all(&data, EXIT_FAILURE));
	}
	return (free_all(&data, EXIT_SUCCESS));
}
