/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:06 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:12:50 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		protect(char **split, size_t i)
{
	while (i--)
	{
		if (!split[i])
		{
			while (i--)
				free(split[i]);
			free(split);
			return (1);
		}
	}
	return (0);
}

static size_t	ft_splitlen(char const *s, char c)
{
	size_t splits;

	splits = 0;
	while (*s == c)
		++s;
	while (*s != '\0')
	{
		++splits;
		while (*s != c && *s != '\0')
			++s;
		if (*s == c)
			while (*s == c)
				++s;
	}
	return (splits);
}

char			**ft_split(char const *s, char c)
{
	size_t	splits;
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	splits = ft_splitlen(s, c);
	split = (char **)malloc(sizeof(char *) * (splits + 1));
	i = 0;
	if (!split)
		return (NULL);
	while (i < splits)
	{
		while (*s == c)
			++s;
		if (!(split[splits] = ft_strchr(s, c)))
			split[splits] = (char *)s + ft_strlen(s);
		split[i] = (char *)malloc(split[splits] - s + 1);
		if (protect(split, i))
			return (NULL);
		ft_strlcpy(split[i++], s, split[splits] - s + 1);
		s = ft_strchr(s, c);
	}
	split[i] = NULL;
	return (split);
}
