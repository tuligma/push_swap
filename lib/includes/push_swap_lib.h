/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:01:18 by npentini          #+#    #+#             */
/*   Updated: 2024/07/27 03:53:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <stdlib.h>
# include "../../includes/push_swap.h"

int     ft_isdigit(int c);
int     ft_isspace(int c);
int		ft_issign(char c);
void    *ft_calloc(size_t nmemb, size_t size);
void    ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);

#endif