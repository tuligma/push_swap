/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:17:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/07 18:46:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../includes/get_next_line_bonus.h"

#include "get_next_line_bonus.h"

void	reset_list_b(t_gnl_blist **list)
{
	t_gnl_blist	*clean_node;
	t_gnl_blist	*last_node;
	char		*new_line;
	int			i;
	int			x;

	last_node = ft_lstlast_b(*list);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	new_line = malloc((BUFFER_SIZE - i) + 1);
	clean_node = malloc(sizeof(t_gnl_blist));
	if (!new_line || !clean_node)
		return ;
	x = 0;
	while (last_node->content[i] && last_node->content[++i])
		new_line[x++] = last_node->content[i];
	new_line[x] = '\0';
	clean_node->content = new_line;
	clean_node->next = NULL;
	ft_lstclear_b(list, clean_node, new_line);
}

void	ft_lstnewadd_back_b(t_gnl_blist **list, char *s, int fd)
{
	t_gnl_blist	*new_node;

	new_node = malloc(sizeof(t_gnl_blist));
	if (!new_node)
		return ;
	new_node->content = s;
	new_node->next = NULL;
	if (!list[fd])
		list[fd] = new_node;
	else
		ft_lstlast_b(list[fd])->next = new_node;
}

void	fetching_b(t_gnl_blist **list, int fd)
{
	char	*dest;
	int		state;

	while (!newline_tracker_b(list[fd]))
	{
		dest = malloc(BUFFER_SIZE + 1);
		if (!dest)
			return ;
		state = read(fd, dest, BUFFER_SIZE);
		if (state <= 0)
		{
			free(dest);
			if (state == -1)
				ft_lstclear_b(&list[fd], NULL, NULL);
			return ;
		}
		dest[state] = '\0';
		ft_lstnewadd_back_b(list, dest, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_blist	*list[4096];
	char				*str;

	if (BUFFER_SIZE < 0 || fd < 0 || fd > 4096)
		return (NULL);
	fetching_b(list, fd);
	if (!list[fd])
		return (NULL);
	str = malloc(consolidation_len_b(list[fd]) + 1);
	if (!str)
		return (NULL);
	str = transfer_str_b(list[fd], str);
	if (!str)
		return (NULL);
	reset_list_b(&list[fd]);
	return (str);
}
