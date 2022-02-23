/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:29 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:13:25 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1;
		++i;
		++s1;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2;
		++i;
		++s2;
	}
	join[i] = '\0';
	return (join);
}
