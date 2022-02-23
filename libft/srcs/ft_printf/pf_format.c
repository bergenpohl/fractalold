/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:35:20 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/10 14:39:48 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_format(t_profile *profile)
{
	char c;

	c = profile->format[profile->index];
	if (c == 'c')
		pf_display_c(profile, (char)va_arg(profile->args, int));
	else if (c == 's')
		pf_display_s(profile, (char *)va_arg(profile->args, char *));
	else if (c == 'p')
		pf_display_p(profile, (void *)va_arg(profile->args, void *));
	else if (c == 'd')
		pf_display_d(profile, (int)va_arg(profile->args, int));
	else if (c == 'i')
		pf_display_d(profile, (int)va_arg(profile->args, int));
	else if (c == 'u')
		pf_display_u(profile,
				(unsigned int)va_arg(profile->args, unsigned int));
	else if (c == 'x')
		pf_display_x(profile,
				(unsigned int)va_arg(profile->args, unsigned int), 0);
	else if (c == 'X')
		pf_display_x(profile,
				(unsigned int)va_arg(profile->args, unsigned int), -32);
	else
		pf_display_c(profile, c);
}

void	pf_pad(t_profile *profile, size_t len, size_t cut, char padding)
{
	char *pad;

	len = cut > len ? 0 : len - cut;
	pad = (char *)malloc(len + 1);
	pad[len] = '\0';
	profile->rv += len;
	while (len)
		pad[--len] = padding;
	ft_putstr_fd(pad, profile->fd);
	free(pad);
}
