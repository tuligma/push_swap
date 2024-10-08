/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:50:51 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:38:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INIT_H
# define PUSH_SWAP_INIT_H

void		*print_free_error(t_ps_hub *data, int error_code);
int			struct_init(void **struct_ptr, size_t struct_size);
int			argument_counter(t_ps_hub *data, char **args);
int			argument_strip(t_ps_hub *data, char **args);
int			argument_extraction(t_ps_hub *data, int argc,
				char **argv, int (*f)(t_ps_hub*, char **));
t_ps_hub	*init_handler(int argc, char *argv[]);

#endif