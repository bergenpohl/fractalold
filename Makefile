NAME			=	Fractal

PATH_SRCS		=	./srcs/
PATH_INCLUDES	=	./includes/

PATH_LIBFT		=	./libft/
PATH_OPENGL		=	./minilibx_opengl/
LIB_USED		=	$(PATH_OPENGL)

FILES_RAW		=	main		\
					fr_hooks	\
					fr_init		\
					fr_exit		\
					fr_dest		\
					fr_fractal	\
					fr_image	\
					fr_file		\
					fr_input

FILES_SRCS		= 	$(addsuffix ".c", $(addprefix $(PATH_SRCS), $(FILES_RAW)))

LIBRARIES		=	-I $(PATH_LIBFT)/includes -L $(PATH_LIBFT) -l ft -I $(LIB_USED) -L $(LIB_USED) -l mlx
FRAMEWORKS		=	-framework OpenGL -framework AppKit

.PHONY: all libs clean fclean re

all: $(NAME)

$(NAME): libs
	gcc $(FILES_SRCS) -I $(PATH_INCLUDES) $(LIBRARIES) $(FRAMEWORKS) -o $(NAME)

libs: $(LIBFT) $(MMS) $(OPENGL)
	make -C $(PATH_LIBFT)
	make -C $(LIB_USED)

clean:
	rm -rf $(NAME)

fclean: clean $(LIBFT) $(MMS) $(OPENGL)
	make clean -C $(PATH_LIBFT)
	make clean -C $(LIB_USED)
	
re: fclean all
