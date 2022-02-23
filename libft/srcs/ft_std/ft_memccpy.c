/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:18:50 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/20 09:55:16 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
					const void *restrict src,
					int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	unsigned char	stop;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	stop = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)s[i];
		if (s[i] == stop)
			return ((d += i + 1));
		++i;
	}
	return (NULL);
}
