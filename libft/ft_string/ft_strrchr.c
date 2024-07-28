/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:58:26 by npentini          #+#    #+#             */
/*   Updated: 2024/07/06 21:10:42 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	n;

	str = (char *)s;
	n = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return (str + n);
	while (0 < n--)
	{
		if (str[n] == (unsigned char)c)
			return (str + n);
	}
	return (NULL);
}
