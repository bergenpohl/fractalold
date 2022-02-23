#include "fractal.h"

int	main(int argc, char *argv[])
{
	t_input		i;
	t_session	s;
	
	if (init_t_input(&i, argc, argv))
	{
		if (!init_t_session(&s, &i))
			return (1);
		fractal(&s);
		draw_image(&s);
		if (i.only_save)
		{
			save_to_bitmap_file(&s);
			program_exit(&s);
		}
		mlx_put_image_to_window(s.mlx.ptr, s.win.ptr, s.img.ptr, 0, 0);
		mlx_key_hook(s.win.ptr, &key_hook, &s);
		mlx_loop_hook(s.mlx.ptr, &loop_hook, &s);
		mlx_loop(s.mlx.ptr);
	}
	// Not yet written: "Usage: --config [path] --manual [2Int] [4Double]\n"
	ft_printf("Usage: --manual <imgw> <imgh> <viewx> <viewy> <vieww> <viewh>, --onlysave\n");
	return (0);
}
