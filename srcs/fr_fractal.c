#include "fractal.h"
#include <stdio.h>

int		fractal(t_session *s)
{
	int			a, b;
	long double	x, y;
	long double	ix, iy;

	y = s->fractal.y;
	ix = s->fractal.width / s->img.width;
	iy = s->fractal.height / s->img.height;

	a = 0;
	while (a < s->img.height)
	{
		b = 0;
		x = s->fractal.x;
		while (b < s->img.width)
		{
			s->img.values[a * s->img.width + b] = mandelbrot(x, y);
			x += ix;
			++b;
		}
		y += iy;
		++a;
	}
	return (1);
}

int		julia(long double a, long double b)
{
	int			res;
	long double	temp;

	res = 0;
	while (a < 2 && res < 64)
	{
		temp = a;
		a = ((a * a) + ((b * b) * -1)) + 0;
		b = ((temp * b) * 2) + 0;
		++res;
	}
	return (res);
}

//	power 2
int		mandelbrot(long double c, long double di) {
	int			res;
	long double	a, bi;
	long double	tmp;

	a = 0;
	bi = 0;
	res = 0;
	while (a < 2 && res < 256) {
		tmp = a;
		a = a * a + bi * bi * -1 + c;
		bi = tmp * bi * 2 + di;
		++res;
	}
	return (res);
}


//	power 3
/*
int		mandelbrot(long double c, long double d)
{
	int			res;
	long double	a, b;
	long double	at;

	res = 0;
	a = 0;
	b = 0;
	while (a < 2 && res < 256)
	{
		at = a;
		a = a * a * a + 3 * a * b * b * -1 + c;
		b = at * at * 3 * b + b * b * b * -1 + d;
		++res;
	}
	return (res);
}
*/

//	power x
/*
int		mandelbrot(long double c, long double di) {
	long double	a, bi;
	long double	tmp;
	int res;
	int	i;
	
	a = 0;
	bi = 0;
	res = 0;
	while (a < 2 && res < 256) {
		i = 0;
		while (i < 4) {
			tmp = a;
			a = a * a + bi * bi * -1;
			bi = tmp * bi * 2;
			++i;
		}
		a += c;
		bi += di;
		++res;
	}
	return (res);
}
*/
