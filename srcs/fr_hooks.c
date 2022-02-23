#include "fractal.h"
#include <stdio.h>

int	loop_hook(t_session *s)
{
	if (!(s->is_open))
	{
		program_exit(s);
	}
	return (1);
}

int key_hook(int keycode, t_session *s)
{
//	esc (for exit)
	if (keycode == 53)
		s->is_open = 0;
//	s (for save)
	if (keycode == 1)
	{
		ft_printf("Saving to file...");
		save_to_bitmap_file(s);
		ft_printf(" Done.\n");
	}
//	left (for redraw left)
	if (keycode == 123)
	{
		s->fractal.x -= s->fractal.width / 10;
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	right (for redraw right)
	if (keycode == 124)
	{
		s->fractal.x += s->fractal.width / 10;
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	down (for redraw down)
	if (keycode == 125)
	{
		s->fractal.y += s->fractal.height / 10;
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	up (for redraw up)
	if (keycode == 126)
	{
		s->fractal.y -= s->fractal.height / 10;
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	=/+ (for zoom in)
	if (keycode == 24)
	{
		s->fractal.x += s->fractal.width / 10;
		s->fractal.y += s->fractal.height / 10;
		s->fractal.width -= (s->fractal.width / 5);
		s->fractal.height -= (s->fractal.height / 5);
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	-/_ (for zoom out)
	if (keycode == 27)
	{
		s->fractal.width = (s->fractal.width * 1.25);
		s->fractal.height = (s->fractal.height * 1.25);
		s->fractal.x -= s->fractal.width / 10;
		s->fractal.y -= s->fractal.height / 10;
		fractal(s);
		draw_image(s);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	}
//	p (for print coords)
	if (keycode == 35)
	{
		printf("%.12Lf %.12Lf %.12Lf %.12Lf\n", s->fractal.x, s->fractal.y, s->fractal.width, s->fractal.height);
	}
	return (1);
}
