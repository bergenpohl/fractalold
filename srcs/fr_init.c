#include "fractal.h"

int init_t_input(t_input *i, int argc, char **argv)
{
	int rv;
	
	rv = handle_commandline_args(i, argc, argv);
	if (rv)
	{
		if (i->image_width == 0 || i->image_height == 0 || i->view_width == 0 || i->view_height == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	init_t_session(t_session *s, t_input *i)
{
	char		*p;
	
	s->win.ptr = NULL;
	s->mlx.ptr = mlx_init();
	if (s->mlx.ptr == NULL)
		return (0);
	if (i->only_save == 0)
		if (!init_t_window(s, i->image_width, i->image_height))
			return (0);
	if (!init_t_image(s, i->image_width, i->image_height))
		return (0);
	if (!init_t_fractal(s, i))
		return (0);
	return (1);
}

int				init_t_window(t_session *s, long width, long height)
{
	s->win.ptr = mlx_new_window(s->mlx.ptr, width, height, "Fractal2D");
	if (s->win.ptr == NULL)
		return (0);
	s->win.width = width;
	s->win.height = height;
	return (1);
}

int				init_t_image(t_session *s, long width, long height)
{
	size_t i;
	
	s->img.ptr = NULL;
	s->img.ptr = mlx_new_image(s->mlx.ptr, width, height);
	if (s->img.ptr == NULL)
		return (0);
	s->img.x = 0;
	s->img.y = 0;
	s->img.width = width;
	s->img.height = height;
	s->img.mem = NULL;
	s->img.mem = mlx_get_data_addr(s->img.ptr, &s->img.bits_per_pixel, &s->img.size_line, &s->img.endian);
	s->img.values = NULL;
	s->img.values = (int *)malloc(sizeof(int) * width * height);
	if (s->img.values == NULL)
		return (0);
	i = 0;
	while (i < ITERATIONS)
	{
		s->img.coloring[i] = gray(i);
		++i;
	}
	return (1);
}

int	init_t_fractal(t_session *s, t_input *i)
{
	s->fractal.x = i->view_x;
	s->fractal.y = i->view_y;
	s->fractal.width = i->view_width;
	s->fractal.height = i->view_height;
	if (s->fractal.width == 0 || s->fractal.height == 0)
		return (0);
	s->is_open = 1;
	return (1);
}
