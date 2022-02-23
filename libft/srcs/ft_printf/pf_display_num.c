/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:29:17 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/06 21:31:07 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_display_num(t_profile *profile, char *s)
{
	if (profile->parsed->cut_bool && profile->parsed->cut > -1)
	{
		if (s[0] == '-')
			++profile->parsed->cut;
		if (s[0] == '0' && profile->parsed->cut == 0)
			s[0] = '\0';
		if (profile->parsed->cut &&
			ft_strlen(s) < (size_t)profile->parsed->cut)
			s = zero_pad(s, (size_t)profile->parsed->cut);
		profile->parsed->cut_bool = 0;
	}
	else if (profile->parsed->zeros)
		if (profile->parsed->pad > 0 &&
			ft_strlen(s) < (size_t)profile->parsed->pad)
			s = zero_pad(s, (size_t)profile->parsed->pad);
	profile->parsed->zeros = 0;
	pf_display_s(profile, s);
	return (s);
}

char	*zero_pad(char *s, size_t pad)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = (char *)malloc(pad + 1);
	if (s[0] == '-')
	{
		new[0] = '-';
		ft_memcpy(new + (pad - len + 1), s + 1, len);
		pad -= len;
		while (pad)
			new[pad--] = '0';
	}
	else
	{
		ft_memcpy(new + (pad - len), s, len + 1);
		pad -= len;
		while (pad)
			new[--pad] = '0';
	}
	free(s);
	return (new);
}
