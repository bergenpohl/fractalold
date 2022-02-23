#include "fractal.h"

int	destroy_t_window(t_session *s)
{
	if (s->win.ptr != NULL)
	{
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
		s->win.ptr = NULL;
		return (1);
	}
	return (0);
}

int destroy_t_image(t_session *s)
{
	int rv;
	
	rv = 1;
	if (s->img.ptr != NULL)
	{
		rv = mlx_destroy_image(s->mlx.ptr, s->img.ptr);
		s->img.ptr = NULL;
	}
	if (s->img.values != NULL)
		free(s->img.values);
	return (rv);
}
