/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:36 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:19:00 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,
					const char *src,
					size_t dstsize)
{
	size_t len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (len + 1 < dstsize)
		ft_memcpy(dst, src, len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len);
}
