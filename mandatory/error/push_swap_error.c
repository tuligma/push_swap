/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:31:17 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 15:21:31 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	error_print(int error_code)
{
	if (error_code != 0)
	{
		if (error_code != EPSARG)
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	return (EXIT_FAILURE);
}

int	other_element_checker(char *str, int (*fsign)(int), int (*fdigit)(int))
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
	char	**arg;
	int		x;
	int		result;

	arg = ft_split(str, ' ');
	if (arg == NULL)
		return (EXIT_FAILURE);
	x = -1;
	while (arg[++x] != NULL)
	{
		result = other_element_checker(arg[x], ft_issign, ft_isdigit);
		if (result != 0)
		{
			free_array(&arg, -1);
			return (ERR_OTHR_EL);
		}
		if (ft_atol(arg[x]) > INT_MAX || ft_atol(arg[x]) < INT_MIN)
		{
			free_array(&arg, -1);
			return (ERR_INT_LIMIT);
		}
	}
	free_array(&arg, -1);
	return (0);
}

int	error_checker(int argc, char *argv[])
{
	int	x;

	if (argc < 2)
		return (2);
	x = 0;
	while (++x < argc)
	{
		if (argv[x] == NULL)
			return (EXIT_FAILURE);
		if (is_valid_number(argv[x]) != 0)
			return (EXIT_FAILURE);
	}
	return (0);
}
