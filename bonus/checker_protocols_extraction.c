/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_protocols_extraction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:31:18 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:15:59 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*trim_and_dup(char *str)
{
	char	*content;
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	content = ft_strdup(str);
	if (content == NULL)
		return (NULL);
	return (content);
}

int	protocols_extraction_ext(t_ps_stack *checker)
{
	t_list	*node;
	char	*content;
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		content = trim_and_dup(line);
		if (content == NULL)
		{
			free(line);
			return (ERR_MALLOC_FAILED);
		}
		node = ft_lstnew(content);
		if (node == NULL)
			return (ERR_MALLOC_FAILED);
		if (checker->head == NULL)
			checker->head = node;
		else
			ft_lstadd_back(&checker->head, node);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	protocols_extraction(t_ps_hub *data)
{
	t_ps_stack	*checker;

	if (struct_init((void **)&data->checker, sizeof(t_ps_stack)) != 0)
		return (ERR_MALLOC_FAILED);
	checker = data->checker;
	if (protocols_extraction_ext(checker) != 0)
		return (ERR_MALLOC_FAILED);
	checker->tail = ft_lstlast(checker->head);
	checker->count = ft_lstsize(checker->head);
	return (0);
}
