/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:29 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:33:08 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

char	*trim_and_dup(char *str);
int		protocols_extraction_ext(t_ps_stack *checker);
int		protocols_extraction(t_ps_hub *data);
int		rotate_protocol(char *content, int len);
int		reverse_rotate_protocol(char *content, int len);
int		swap_protocol(char *content, int len);
int		push_protocol(char *content, int len);
void	(*single_function(char *content, int len))(t_ps_stack *stack);
void	(*double_function(char *content,
				int len))(t_ps_stack *stack1, t_ps_stack *stack2);
void	execute_protocols(t_ps_hub *data, t_ps_stack *stack1, char *content);
int		protocols_execution(t_ps_hub *data);

#endif