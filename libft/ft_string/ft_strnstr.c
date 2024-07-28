/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:09:57 by npentini          #+#    #+#             */
/*   Updated: 2024/07/06 21:10:33 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	lil_len;

	b = (char *)big;
	l = (char *)little;
	lil_len = ft_strlen(little);
	if (!lil_len)
		return (b);
	while (*b != '\0' && len >= lil_len)
	{
		if (ft_strncmp(b, l, lil_len) == 0)
			return (b);
		++b;
		--len;
	}
	return (NULL);
}
