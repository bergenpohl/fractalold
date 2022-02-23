#ifndef FRACTAL_H
#define FRACTAL_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include <OpenGL/gl.h>

#include "mlx.h"
#include "libft.h"

#define BMP_FILE_HEADER_SIZE 14
#define BMP_INFO_HEADER_SIZE 40

#define ITERATIONS 256

typedef struct		s_input
{
	int				only_save;
	long			image_width;
	long			image_height;
	long double		view_x;
	long double		view_y;
	long double		view_width;
	long double		view_height;
}					t_input;

typedef struct		s_fractal
{
	long double		x;
	long double		y;
	long double		width;
	long double		height;
}					t_fractal;

typedef	struct		s_image
{
	void			*ptr;
	long			x;
	long			y;
	long			width;
	long			height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*mem;
	int				*values;
	unsigned int	coloring[ITERATIONS];
}					t_image;

typedef	struct		s_window
{
	void			*ptr;
	long			width;
	long			height;
}					t_window;

typedef	struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_session
{
	t_mlx			mlx;
	t_window		win;
	t_image			img;
	t_fractal		fractal;
	int				is_open;
}					t_session;

int					fractal(t_session *s);
int					julia(long double a, long double b);
int					mandelbrot(long double c, long double di);

int					handle_commandline_args(t_input *i, int argc, char **argv);
int					arg_id(int rem, char *arg);
int					config_set(t_input *i, char *path);
int					manual_set(t_input *i, char **argv);

int					init_t_session(t_session *s, t_input *i);
int					init_t_window(t_session *s, long width, long height);
int					init_t_image(t_session *s, long width, long height);
int					init_t_fractal(t_session *s, t_input *i);
int					init_t_input(t_input *input, int argc, char **argv);

int					loop_hook(t_session *s);
int					key_hook(int keycode, t_session *s);

int					gray(int i);
int					draw_image(t_session *s);

int					destroy_t_image(t_session *s);
int					destroy_t_window(t_session *s);

int					save_to_bitmap_file(t_session *s);
int					bitmap_file_header(t_session *s, int padding_size, int fd);
int					bitmap_info_header(t_session *s, int fd);
int					bitmap_pixel_data(t_session *s, int padding_size, int fd);

int					program_exit(t_session *s);

#endif
