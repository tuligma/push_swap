/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 03:24:43 by npentini          #+#    #+#             */
/*   Updated: 2024/07/06 21:09:29 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		dest[i] = s1[i];
	while (i < s1_len + s2_len)
	{
		dest[i] = s2[i - s1_len];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
