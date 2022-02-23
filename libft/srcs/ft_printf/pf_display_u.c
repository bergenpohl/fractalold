/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:31:38 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/10 14:35:38 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_utoa(unsigned int u)
{
	char	*s;
	size_t	u_cpy;
	size_t	len;

	u_cpy = u;
	len = 1;
	while (u_cpy > 9)
	{
		u_cpy /= 10;
		++len;
	}
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	while (len)
	{
		s[--len] = (u % 10) + '0';
		u = u / 10;
	}
	return (s);
}

void		pf_display_u(t_profile *profile, unsigned int u)
{
	char *s;

	s = pf_utoa(u);
	s = pf_display_num(profile, s);
	free(s);
}
