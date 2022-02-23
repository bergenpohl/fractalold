/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:38:26 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/12 13:54:37 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_profile		*pf_init_profile(const char **format,
								const int fd)
{
	t_profile *profile;

	profile = (t_profile *)malloc(sizeof(t_profile));
	profile->format = *format;
	profile->index = 0;
	profile->parsed = (t_parsed *)malloc(sizeof(t_parsed));
	profile->rv = 0;
	profile->fd = (int)fd;
	return (profile);
}

void			pf_clear_parsed(t_profile *profile)
{
	profile->parsed->zeros = 0;
	profile->parsed->pad = 0;
	profile->parsed->pad_dir = 0;
	profile->parsed->cut = 0;
	profile->parsed->cut_bool = 0;
}
