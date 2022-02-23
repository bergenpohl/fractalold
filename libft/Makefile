NAME	=	libft.a

STD_SRC =		ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c
STD_OBJ		=	$(STD_SRC:%.c=%.o)
PF_SRC		=	ft_printf.c			\
				pf_struct.c			\
				pf_parse.c			\
				pf_format.c			\
				pf_display_c.c		\
				pf_display_s.c		\
				pf_display_num.c	\
				pf_display_d.c		\
				pf_display_u.c		\
				pf_display_x.c		\
				pf_display_p.c
PF_OBJ		=	$(PF_SRC:%.c=%.o)

SRCS		=	./srcs/
PF_DIR		=	./srcs/ft_printf/
STD_DIR		=	./srcs/ft_std/
INCLUDES	=	./includes/
OBJECTS		=	./objects/

C_FILES		=	$(addprefix $(STD_DIR), $(STD_SRC))	\
				$(addprefix $(PF_DIR), $(PF_SRC))
O_FILES		=	$(STD_OBJ)	$(PF_OBJ)

FLAGS		=	-Wall -Wextra -Werror -I$(INCLUDES)
COMPILE		=	-c

.PHONY:		all clean flcean re

all: $(NAME)

$(NAME):
	gcc		$(C_FILES)	$(FLAGS)	$(COMPILE)
	ar -rc	$(NAME)		$(O_FILES)
	mv		$(O_FILES)	$(OBJECTS)

clean:
	rm -f	$(addprefix $(OBJECTS), $(STD_OBJ))	\
			$(addprefix $(OBJECTS), $(PF_OBJ))
	
fclean: clean
	rm -f	$(NAME)
	
re: fclean all
