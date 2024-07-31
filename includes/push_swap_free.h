/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:53:30 by npentini          #+#    #+#             */
/*   Updated: 2024/07/30 14:07:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FREE_H
# define PUSH_SWAP_FREE_H

void	free_node(void *content);
void	free_int_array(int **array);
void	free_array(char ***arr, int x);
void	free_data_11(t_ps_hub **data, int x);
int		free_data(t_ps_hub **data, int which_to_free, int x);
void	free_data_0(t_ps_hub **data, int x);

#endif