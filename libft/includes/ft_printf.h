/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:15:56 by bpohl             #+#    #+#             */
/*   Updated: 2020/07/10 14:44:07 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_parsed
{
	int			zeros;
	int			pad;
	int			pad_dir;
	int			cut;
	int			cut_bool;
}				t_parsed;

typedef struct	s_profile
{
	const char	*format;
	size_t		index;
	va_list		args;
	t_parsed	*parsed;
	size_t		rv;
	int			fd;
}				t_profile;

t_profile		*pf_init_profile(const char **format,
								 const int fd);
void			pf_clear_parsed(t_profile *profile);
int				pf_parse_format(t_profile *profile);
size_t			pf_parse_conversion(t_profile *profile);
void			pf_find_pad(t_profile *profile, int dir);
void			pf_find_cut(t_profile *profile);
int				pf_calc_input(t_profile *profile);
void			pf_format(t_profile *profile);
void			pf_pad(t_profile *profile, size_t len,
				size_t cut, char padding);
char			*zero_pad(char *s, size_t pad);
char			*pf_display_num(t_profile *profile, char *s);
void			pf_display_c(t_profile *profile, char c);
void			pf_display_s(t_profile *profile, char *s);
void			pf_display_p(t_profile *profile, void *p);
void			pf_display_d(t_profile *profile, int d);
void			pf_display_u(t_profile *profile, unsigned int u);
void			pf_display_x(t_profile *profile, unsigned int x, int is_cap);

#endif
