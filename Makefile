NAME				=	cub3d

HEAD				= -I mlx_linux -I srcs/

DIR_SRC			=	srcs

DIR_OBJ			=	obj

SUB_OBJ			=	obj/parser obj/libft obj/image

SRC				=	cub3d.c \
<<<<<<< HEAD
					libft/ft_split.c \
					parser/ft_parsing.c parser/ft_utils.c parser/ft_utils2.c parser/ft_parsing2.c libft/libft.c
=======
					libft/ft_split.c libft/ft_memset.c \
					parser/ft_parsing.c parser/ft_utils.c parser/ft_utils2.c \
					image/init.c image/clear.c
>>>>>>> main

OBJ				=	$(SRC:%.c=$(DIR_OBJ)/%.o)

CC					=	gcc

MLX_FLAGS			=	-lm -lmlx -lXext -lX11

CFLAGS				=	-Wall -Werror -Wextra -g #-fsanitize=address

LD_FLAGS			=	-L mlx_linux

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c Makefile
					mkdir -p $(DIR_OBJ) $(SUB_OBJ)
					$(CC) $(CFLAGS) -MMD -c $< -o $@

${NAME}				:	${OBJ}
					make -C mlx_linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJ} -o ${NAME} ${MLX_FLAGS}

all					:	${NAME}

clean				:
					make clean -C mlx_linux
					@rm -rf ${DIR_OBJ}

fclean				:	clean
					@rm -rf ${NAME}

re					:	fclean all

.PHONY				:	all clean fclean re