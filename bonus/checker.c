/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:25:50 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:16:35 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_all_b(t_ps_hub **data, int status)
{
	if (data != NULL && *data != NULL)
		free_data(data);
	if (status == EXIT_FAILURE)
		ft_printf("KO\n");
	else if (status == EXIT_SUCCESS)
		ft_printf("OK\n");
	return (0);
}

int	(**checker_process_init())(t_ps_hub *data)
{
	int	(**checker_process)(t_ps_hub *);

	checker_process = ft_calloc(CPROCESS_COUNT + 1,
			sizeof(int (*)(t_ps_hub *)));
	if (checker_process == NULL)
		return (NULL);
	checker_process[0] = dup_checker;
	checker_process[1] = push_args_to_stack_a;
	checker_process[2] = protocols_extraction;
	checker_process[3] = protocols_execution;
	checker_process[4] = lst_sort_checker;
	checker_process[5] = NULL;
	return (checker_process);
}

void	print_node_int(void *content)
{
	ft_printf("node: %d\n", *((int *)content));
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
		return (free_all_b(&data, EXIT_SUCCESS));
	data->process = checker_process_init();
	if (data->process == NULL)
		return (free_all_b(&data, EXIT_FAILURE));
	x = -1;
	while (data->process[++x] != NULL)
	{
		result = data->process[x](data);
		if (result != 0)
			return (free_all_b(&data, EXIT_FAILURE));
	}
	return (free_all_b(&data, EXIT_SUCCESS));
}
