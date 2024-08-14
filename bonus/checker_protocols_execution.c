/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_protocols_execution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:34:32 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:14:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	(*single_function(char *content, int len))(t_ps_stack *stack)
{
	if (rotate_protocol(content, len) == 1)
		return (rotate);
	else if (reverse_rotate_protocol(content, len) == 1)
		return (reverse_rotate);
	else if (swap_protocol(content, len) == 1)
		return (swap);
	return (NULL);
}

void	(*double_function(char *content,
	int len))(t_ps_stack *stack1, t_ps_stack *stack2)
{
	if (push_protocol(content, len) == 1)
		return (push);
	return (NULL);
}

void	execute_protocols(t_ps_hub *data, t_ps_stack *stack1, char *content)
{
	void		(*f_single)(t_ps_stack *);
	void		(*f_double)(t_ps_stack *, t_ps_stack *);
	t_ps_stack	*stack2;
	int			len;

	stack2 = data->a;
	if (stack1 == data->a)
		stack2 = data->b;
	len = ft_strlen(content);
	f_single = single_function(content, len);
	f_double = double_function(content, len);
	if (content[len - 1] == 'r' || content[len - 1] == 's')
		both_protocol(stack1, stack2, f_single);
	else if (f_single == NULL && f_double != NULL)
		f_double(stack2, stack1);
	else if (f_double == NULL)
		f_single(stack1);
}

int	protocols_execution(t_ps_hub *data)
{
	t_ps_stack	*stack;
	t_list		*current;
	char		*content;
	int			len;

	current = data->checker->head;
	while (current != NULL)
	{
		content = (char *)current->content;
		if (content == NULL)
			return (ERR_INVALID_PROTOCOL);
		len = ft_strlen(content);
		stack = data->a;
		if (content[len - 1] == 'b')
			stack = data->b;
		execute_protocols(data, stack, content);
		current = current->next;
	}
	return (0);
}
