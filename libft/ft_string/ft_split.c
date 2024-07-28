/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:50:23 by npentini          #+#    #+#             */
/*   Updated: 2024/07/06 21:08:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_word(char const *s, char c)
{
	int	count_word;
	int	i;

	count_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count_word);
}

static char	*ft_range(char const *s, size_t start, size_t end)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * ((end - start) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (start < end)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

static char	**free_me(char **dest, char const *s, char c)
{
	int	k;

	k = 0;
	while (k < count_word(s, c))
	{
		if (dest[k])
			free(dest[k]);
		k++;
	}
	free(dest);
	return (NULL);
}

static char	**splitter(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			dest[j] = ft_range(s, start, i);
			if (dest[j] == NULL)
				return (free_me(dest, s, c));
			j++;
		}
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = ft_calloc(count_word(s, c), sizeof(char *));
	if (!dest)
		return (NULL);
	return (splitter(dest, s, c));
}
