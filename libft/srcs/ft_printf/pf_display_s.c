/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:21:24 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/06 21:22:38 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_display_s(t_profile *profile, char *s)
{
	char	padding;
	size_t	len;

	if (s == NULL)
		s = "(null)";
	padding = ' ';
	len = ft_strlen(s);
	if (profile->parsed->cut_bool &&
		profile->parsed->cut >= 0 &&
		len > (size_t)profile->parsed->cut)
		len = profile->parsed->cut;
	if (profile->parsed->pad_dir < 0)
	{
		if (profile->parsed->zeros)
			padding = '0';
		pf_pad(profile, profile->parsed->pad, len, padding);
		write(profile->fd, s, len);
	}
	else
	{
		write(profile->fd, s, len);
		if (profile->parsed->pad_dir)
			pf_pad(profile, profile->parsed->pad, len, ' ');
	}
	profile->rv += len;
}
