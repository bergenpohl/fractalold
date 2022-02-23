/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:21:08 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:22:14 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	chr;
	size_t	i;

	str = (char *)s;
	chr = (char)c;
	i = 0;
	while (str[i] != '\0')
		++i;
	while (str[i] != chr && i)
		--i;
	if (str[i] == chr)
		return (str + i);
	return (NULL);
}
