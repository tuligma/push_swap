/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:26:59 by npentini          #+#    #+#             */
/*   Updated: 2024/07/06 21:09:46 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		len = -1;
		while (++len < size - 1 && src[len] != '\0')
			dest[len] = src[len];
		dest[len] = '\0';
	}
	return (src_len);
}
