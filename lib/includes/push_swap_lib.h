/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:01:18 by npentini          #+#    #+#             */
/*   Updated: 2024/07/28 06:12:58 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <stdlib.h>
# include "../../includes/push_swap.h"

int     ft_isdigit(char c);
int     ft_isspace(char c);
int		ft_issign(char c);
void    *ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif