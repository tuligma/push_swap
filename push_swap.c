/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/07/29 02:45:10 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps_hub *data;
	
	if (error_checker(argc, argv) == 1)
		return (1);
	data = init_handler(argc, argv);
	if (data == NULL)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	if (dup_checker(data) != 0 || sort_checker(data) != 0)
		return (free_data(&data, 0, -1));
	int x;
	x = -1;
	while (++x < data->arg_count)
		ft_printf("arg%d: %d\n", x + 1, (data)->args[x]);
	ft_printf("Success!!\n");
	free_data(&data, 0, -1);
	return (0);
}