/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:04:42 by npentini          #+#    #+#             */
/*   Updated: 2024/07/30 01:53:58 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last_node;

	if (!list || !new)
		return ;
	else if (!*list)
	{
		*list = new;
		(*list)->prev = NULL;
		return ;
	}
	last_node = ft_lstlast(*list);
	last_node->next = new;
	new->prev = last_node;
}
