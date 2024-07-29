/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:29:57 by npentini          #+#    #+#             */
/*   Updated: 2024/07/29 04:01:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ERROR_H
# define PUSH_SWAP_ERROR_H

int	dup_checker(t_ps_hub *data);
int	sort_checker(t_ps_hub *data);
int	error_print(int error_code, char *error_message, char ***arr);
int	other_element_checker(char *str, int (*fsign)(int), int (*fdigit)(int));
int	is_valid_number(char *str);
int	error_checker(int argc, char *argv[]);

#endif