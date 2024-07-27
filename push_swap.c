/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:43:57 by npentini          #+#    #+#             */
/*   Updated: 2024/07/27 03:49:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	other_element_checker(char *str)
{
	int	x;
	
	x = -1;
	while (str[++x] != '\0')
	{
		if (!ft_isdigit(str[x]) && !ft_isspace(str[x]) && !ft_issign(str[x]))
			return (1);
	}
	return (0);
}

int	argument_checker(int argc, char *argv[])
{
	int	x;

	x = 0;
	while (++x < argc)
	{
		if (argv[x] != NULL && other_element_checker(argv[x]))
			return (1);
	}
	return (0);
}

int	error_print(int error_code, char *error_message)
{
	if (error_code != 0)
	{
		if (error_code != EPSARG)
			ft_printf("Error\n");
		ft_printf("%s\n", error_message);
	}
	return (1);
}

int	error_handler(int argc, char *argv[])
{
	if (argc < 2)
		return (error_print(EPSARG, EMSG_EPSARG));
	if (argument_checker(argc, argv) == 1)
		return (error_print(EPSAOE, EMSG_EPSAOE));
	return (0);
}

int	main(int argc, char *argv[])
{
	if (error_handler(argc, argv) == 1)
		return (1);
	ft_printf("Success!!");
	return (0);
}