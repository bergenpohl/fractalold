/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:22 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/10 14:49:50 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_xtoa(unsigned int x, int is_cap)
{
	char			*s;
	unsigned int	x_cpy;
	unsigned int	len;

	x_cpy = x;
	len = 1;
	while (x_cpy > 15)
	{
		x_cpy /= 16;
		++len;
	}
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	while (len)
	{
		x_cpy = x % 16;
		x /= 16;
		s[--len] = x_cpy < 10 ? '0' + x_cpy : 'a' + (x_cpy - 10) + is_cap;
	}
	return (s);
}

void		pf_display_x(t_profile *profile, unsigned int x, int is_cap)
{
	char *s;

	s = pf_xtoa(x, is_cap);
	s = pf_display_num(profile, s);
	free(s);
}
