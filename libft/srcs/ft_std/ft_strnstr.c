/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:59 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:21:55 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
					const char *needle,
					size_t len)
{
	char	*h;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	if (*needle == '\0')
		return (h);
	j = 0;
	while (h[j] != '\0' && j < len)
	{
		i = 0;
		while (h[j + i] == needle[i] && j + i < len)
		{
			if (needle[i + 1] == '\0')
				return (h + j);
			++i;
		}
		++j;
	}
	return (NULL);
}
