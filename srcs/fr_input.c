#include "fractal.h"

int	handle_commandline_args(t_input *i, int argc, char **argv)
{
	int c;
	int	v;
	
	c = 1;
	i->only_save = 0;
	while (c < argc)
	{
		v = arg_id(argc - c, argv[c]);
		if (v)
		{
			if (v == 1)
				i->only_save = 1;
			else if (v == 2)
			{
				if (!config_set(i, argv[c + 1]))
					return (0);
			}
			else if (v == 7)
				if (!manual_set(i, argv + c + 1))
					return (0);
			c += v;
		}
		else
			return (0);
	}
	return (1);
}

int	arg_id(int rem, char *arg)
{
	if (ft_strcmp("--onlysave", arg) == 0)
		return (1);
//	else if (ft_strcmp("--config", arg) == 0 && rem >= 2)
//		return (2);
	else if (ft_strcmp("--manual", arg) == 0 && rem >= 7)
		return (7);
	return (0);
}

int	config_set(t_input *i, char *path)
{
	int fd;
	
	ft_printf("%s\n", path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	
	fd = close(fd);
	if (fd < 0)
		return (0);
	return (1);
}

int	manual_set(t_input *i, char **argv)
{
	char *p;
	
	if (i != NULL && argv != NULL)
	{
		i->image_width = strtol(argv[0], &p, 10);
		i->image_height = strtol(argv[1], &p, 10);
		i->view_x = strtod(argv[2], &p);
		i->view_y = strtod(argv[3], &p);
		i->view_width = strtod(argv[4], &p);
		i->view_height = strtod(argv[5], &p);
		return (1);
	}
	return (0);
}
