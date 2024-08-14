/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:53:30 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:37:41 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FREE_H
# define PUSH_SWAP_FREE_H

void	free_int_array(int **array);
void	free_array(char ***array, int x);
void	free_stack_list(t_ps_stack **stack);
void	free_series(t_ps_series **series);
int		free_all(t_ps_hub **data, int status);
void	free_node(void *content);
void	free_others(t_ps_hub **data);
int		free_data(t_ps_hub **data);

#endif