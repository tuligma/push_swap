/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:31:17 by npentini          #+#    #+#             */
/*   Updated: 2024/07/28 15:21:49 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	error_print(int error_code, char *error_message, char ***arr)
{
	if (error_code != 0)
	{
		if (error_code != EPSARG)
			ft_printf("Error\n");
		ft_printf("%s\n", error_message);
		if (arr != NULL)
			free_array(arr, -1);
	}
	return (1);
}

int	other_element_checker(char *str, int (*fsign)(char), int (*fdigit)(char))
{
	int	x;
	int	sign;
	
	x = -1;
	sign = 0;
	while (str[++x] != '\0')
	{
		if (sign > 1)
			return (1);
		if (fsign(str[x]) == 1)
		{
			sign++;
			continue ;
		}
		if (fdigit(str[x]) == 0)
			return (1);
	}
	if (sign == x)
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	char **arg;
	int	x;
	int	result;

	arg = ft_split(str, ' ');
	if (arg == NULL)
		return (error_print(EPSMAL, EMSG_EPSMAL, NULL));
	x = -1;
	while (arg[++x] != NULL)
	{
		result = other_element_checker(arg[x], ft_issign, ft_isdigit);
		if (result != 0)
			return (error_print(EPSINA, EMSG_EPSINA, &arg));
		if (ft_atol(arg[x]) > INT_MAX || ft_atol(arg[x]) < INT_MIN)
			return (error_print(EPSALM, EMSG_EPSALM, &arg));
	}
	free_array(&arg, -1);
	return (0);
}

int	error_checker(int argc, char *argv[])
{
	int	x;

	if (argc < 3)
		return (error_print(EPSARG, EMSG_EPSARG, NULL));
	x = 0;
	while (++x < argc)
	{
		if (argv[x] == NULL)
			return (1);
		if (is_valid_number(argv[x]) != 0)
			return (1);
	}
	return (0);
}

int	duplicate_checker(int *args, int len)
{
	int	y;
	int	x;

	y = -1;
	while (++y < len - 1)
	{
		x = y;
		while (++x < len)
		{
			if (args[y] == args[x])
				return (error_print(EPSDUP, EMSG_EPSDUP, NULL));
		}
	}
	return (0);
}
