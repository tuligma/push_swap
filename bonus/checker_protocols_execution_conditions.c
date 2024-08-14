/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_protocols_execution_conditions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:41:38 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:15:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_protocol(char *content, int len)
{
	return (ft_strncmp(content, STR_RA, len) == 0
		|| ft_strncmp(content, STR_RB, len) == 0
		|| ft_strncmp(content, STR_RR, len) == 0);
}

int	reverse_rotate_protocol(char *content, int len)
{
	return (ft_strncmp(content, STR_RRA, len) == 0
		|| ft_strncmp(content, STR_RRB, len) == 0
		|| ft_strncmp(content, STR_RRR, len) == 0);
}

int	swap_protocol(char *content, int len)
{
	return (ft_strncmp(content, STR_SA, len) == 0
		|| ft_strncmp(content, STR_SB, len) == 0
		|| ft_strncmp(content, STR_SS, len) == 0);
}

int	push_protocol(char *content, int len)
{
	return (ft_strncmp(content, STR_PA, len) == 0
		|| ft_strncmp(content, STR_PB, len) == 0);
}
