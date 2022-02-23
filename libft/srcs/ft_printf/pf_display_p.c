/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:37:11 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/10 14:37:16 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_ptos(void *p)
{
	char	*s;
	size_t	k;
	size_t	len;

	k = (size_t)p;
	len = 1;
	while (k > 15)
	{
		++len;
		k /= 16;
	}
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	k = (size_t)p;
	while (len)
	{
		s[--len] = k % 16 < 10 ? (k % 16) + '0' : ((k % 16) - 10) + 'a';
		k /= 16;
	}
	return (s);
}

void		pf_display_p(t_profile *profile, void *p)
{
	char	*s;
	size_t	pad;

	s = pf_ptos(p);
	pad = ft_strlen(s);
	if (profile->parsed->cut_bool != 0 &&
		profile->parsed->cut > -1)
	{
		if ((size_t)profile->parsed->cut > pad)
			pad = profile->parsed->cut;
		if (p == NULL && profile->parsed->cut == 0)
		{
			s[0] = '\0';
			pad = 0;
		}
	}
	profile->parsed->cut_bool = 0;
	s = zero_pad(s, pad + 2);
	s[1] = 'x';
	pf_display_s(profile, s);
	free(s);
}
