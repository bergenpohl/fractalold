/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:21:20 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:22:56 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s,
					unsigned int start,
					size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	new[len] = '\0';
	s += start;
	while (len--)
		new[len] = s[len];
	return (new);
}
