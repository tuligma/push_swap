/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:17:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/07 18:49:14 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../includes/get_next_line.h"
#include "get_next_line.h"

void	reset_list_m(t_gnl_mlist **list)
{
	t_gnl_mlist	*clean_node;
	t_gnl_mlist	*last_node;
	char		*new_line;
	int			x;
	int			i;

	if (!list || !*list)
		return ;
	last_node = ft_lstlast_m(*list);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	new_line = malloc((BUFFER_SIZE - i) + 1);
	clean_node = malloc(sizeof(t_gnl_mlist));
	if (!new_line || !clean_node)
		return ;
	x = 0;
	while (last_node->content[i] && last_node->content[++i])
		new_line[x++] = last_node->content[i];
	new_line[x] = '\0';
	clean_node->content = new_line;
	clean_node->next = NULL;
	ft_lstclear_m(list, clean_node, new_line);
}

void	ft_lstnewadd_back_m(t_gnl_mlist **list, char *s)
{
	t_gnl_mlist	*new_node;

	if (!s)
		return ;
	new_node = malloc(sizeof(t_gnl_mlist));
	if (!new_node)
		return ;
	new_node->content = s;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
		ft_lstlast_m(*list)->next = new_node;
}

void	fetching_m(t_gnl_mlist **list, int fd)
{
	char	*bucket;
	int		state;

	while (!newline_tracker_m(*list))
	{
		bucket = malloc(BUFFER_SIZE + 1);
		if (!bucket)
			return ;
		state = read(fd, bucket, BUFFER_SIZE);
		if (state <= 0)
		{
			free(bucket);
			if (state == -1)
				ft_lstclear_m(list, NULL, NULL);
			return ;
		}
		bucket[state] = '\0';
		ft_lstnewadd_back_m(list, bucket);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_mlist	*list;
	char				*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	fetching_m(&list, fd);
	if (!list)
		return (NULL);
	str = malloc(consolidation_len_m(list) + 1);
	if (!str)
		return (NULL);
	str = transfer_str_m(list, str);
	if (!str)
		return (NULL);
	reset_list_m(&list);
	return (str);
}
