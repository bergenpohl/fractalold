#include "fractal.h"

int	program_exit(t_session *s)
{
	destroy_t_window(s);
	destroy_t_image(s);
	exit(0);
}
