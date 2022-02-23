/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:32 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:19:42 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst,
					const char *src,
					size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dlen;

	d = dst;
	s = src;
	dlen = ft_strlen(d);
	if (dlen > dstsize)
		dlen = dstsize;
	dstsize -= dlen;
	if (dstsize == 0)
		return (dlen + ft_strlen(s));
	d += dlen;
	while (*s != '\0')
	{
		if (dstsize != 1)
		{
			*d++ = *s;
			dstsize--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
