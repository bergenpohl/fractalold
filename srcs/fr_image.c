#include "fractal.h"

int		gray(int i)
{
	return (i + (i << 8) + (i << 16));
}

//	Examle:
//	add your own function header in ../includes/fractal.h
//	change from gray() to your_function() in `init_t_image` inorder to change color

/*
int		color_rain(int i)
{
	int rv;
	
	if (i == 256)
		return (0);
	if (i % 24 < 8)
	{
		rv = ((i % 8) * 32) << 16;
		rv += (207 + (i % 16) * 3) << 8;
		rv += 204;
	}
	else if (i % 24 < 16)
	{
		rv = ((i % 16) * 16) << 16;
		rv += (220 + (i % 16) * 3);
		rv += 190 << 8;
	}
	else
	{
		rv = ((i % 16) * 16);
		rv += (207 + (i % 16) * 3) << 16;
		rv += 120 << 8;
	}
	return (rv);
}
*/

int		draw_image(t_session *s)
{
	int				i;
	unsigned int	*mem;
	unsigned int	*coloring;
	int				*values;

	mem = (unsigned int *)s->img.mem;
	coloring = (unsigned int *)&s->img.coloring;
	values = (int *)s->img.values;
	i = 0;
	while (i < s->img.width * s->img.height)
	{
		mem[i] = coloring[values[i]];
		++i;
	}
	return (0);
}
