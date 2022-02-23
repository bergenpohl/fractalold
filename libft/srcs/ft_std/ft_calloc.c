/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:17:32 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/20 09:50:43 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *arr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	arr = (unsigned char *)malloc(count * size);
	if (arr)
		ft_bzero(arr, count * size);
	return (arr);
}
