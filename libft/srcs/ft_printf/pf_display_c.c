/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:28:07 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/06 21:28:46 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_display_c(t_profile *profile, char c)
{
	char padding;

	padding = ' ';
	if (profile->parsed->pad_dir < 0)
	{
		if (profile->parsed->zeros)
			padding = '0';
		pf_pad(profile, profile->parsed->pad, 1, padding);
		write(profile->fd, &c, 1);
	}
	else
	{
		write(profile->fd, &c, 1);
		if (profile->parsed->pad_dir)
			pf_pad(profile, profile->parsed->pad, 1, ' ');
	}
	++profile->rv;
}
