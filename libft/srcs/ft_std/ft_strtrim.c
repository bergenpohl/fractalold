/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:21:14 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:22:30 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	e;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	b = 0;
	while (ft_strchr(set, s1[b]) && s1[b])
		++b;
	e = ft_strlen(s1 + b);
	s1 = s1 + b;
	if (e)
		while (ft_strchr(set, s1[e - 1]))
			e--;
	new = malloc(e + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, e + 1);
	new[e] = '\0';
	return (new);
}
