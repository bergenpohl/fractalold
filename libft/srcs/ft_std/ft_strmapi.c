/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:20:52 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 18:20:22 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s,
					char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(new = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = (*f)(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
