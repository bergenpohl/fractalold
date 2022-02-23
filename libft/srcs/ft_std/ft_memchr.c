/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:18:54 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 17:57:19 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	chr;
	size_t			i;

	s = (unsigned char *)src;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == chr)
			return (s + i);
		++i;
	}
	return (NULL);
}
