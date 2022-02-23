/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:18:03 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 17:30:16 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	f1(long i)
{
	unsigned int len;

	len = 1;
	if (i < 0)
	{
		++len;
		i *= -1;
	}
	while ((i /= 10) != 0)
		++len;
	return (len);
}

char				*ft_itoa(int i)
{
	char			*res;
	unsigned int	len;
	long			n;

	n = (long)i;
	len = f1(n);
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[--len] = '0' + n % 10;
	n /= 10;
	while (n != 0)
	{
		res[--len] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}
