/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:24:27 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/15 08:55:37 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parse_format(t_profile *profile)
{
	size_t	last_index;

	last_index = 0;
	while (profile->format[profile->index] != '\0')
	{
		if (profile->format[profile->index] == '%')
		{
			profile->rv += profile->index - last_index;
			write(profile->fd, profile->format + last_index, profile->index - last_index);
			++profile->index;
			last_index = pf_parse_conversion(profile);
		}
		else
			++profile->index;
	}
	profile->rv += profile->index - last_index;
	write(profile->fd, profile->format + last_index, profile->index - last_index);
	return (0);
}

size_t	pf_parse_conversion(t_profile *profile)
{
	pf_clear_parsed(profile);
	while (profile->format[profile->index] == '0')
		++profile->index;
	if (profile->format[profile->index - 1] == '0')
		profile->parsed->zeros = 1;
	if (ft_isdigit(profile->format[profile->index]) ||
		profile->format[profile->index] == '*')
		pf_find_pad(profile, -1);
	while (ft_strchr("0123456789*-.", profile->format[profile->index])
			&& profile->format[profile->index] != '\0')
	{
		++profile->index;
		if (profile->format[profile->index - 1] == '-')
			pf_find_pad(profile, 1);
		else if (profile->format[profile->index - 1] == '.')
			pf_find_cut(profile);
	}
	pf_format(profile);
	if (profile->format[profile->index] != '\0')
		++profile->index;
	return (profile->index);
}

void	pf_find_pad(t_profile *profile, int dir)
{
	int pad;
	int neg;

	pad = pf_calc_input(profile);
	neg = pad < 0 ? -1 : 1;
	if (neg == -1 && dir == -1)
		profile->parsed->zeros = 0;
	profile->parsed->pad_dir = dir > 0 ? dir : dir * neg;
	if (pad != 0)
		profile->parsed->pad = pad * neg;
}

void	pf_find_cut(t_profile *profile)
{
	profile->parsed->cut = pf_calc_input(profile);
	profile->parsed->cut_bool = 1;
}

int		pf_calc_input(t_profile *profile)
{
	int calc;

	calc = 0;
	while (profile->format[profile->index] == '0')
		++profile->index;
	while (ft_isdigit(profile->format[profile->index]) ||
			profile->format[profile->index] == '*')
	{
		calc *= 10;
		if (profile->format[profile->index] == '*')
		{
			++profile->index;
			if (!ft_isdigit(profile->format[profile->index]))
				return ((int)va_arg(profile->args, int));
			calc = 0;
		}
		calc += (profile->format[profile->index++] - 48);
	}
	return (calc);
}
