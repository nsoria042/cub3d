NAME 		= cub3D

GCC_FLAG	= -Wall -Werror -Wextra -g

CC			= gcc $(GCC_FLAG)

SRC 		= cub3d.c \
			  ./getnextline/get_next_line.c \
			  ./getnextline/get_next_line_utils.c \
			  ini_param.c \
			  ini_param2.c \
			  error.c \
			  parse.c \
			  checkfile.c \
			  chargevar.c \
			  chargevar2.c \
			  chargemap.c \
			  checkmap.c \
			  checkmap2.c \
			  playerpos.c \
			  printvar.c \
			  screenshot.c \
			  keycontrol.c \
			  raycasting.c \
			  raycasting_ext.c \
			  movement.c \
			  chargesprites.c \
			  sprites.c \

OBJ 		= $(SRC:.c=.o)

all: 		libft $(NAME)

libft:
			make -C libft/
			mv libft/libft.a .

minilibx:
			make -C minilibx/
			mv minilibx/libmlx.a .

$(%.o): 	$(%.c)
			$(CC) -o $@ -c $^

$(NAME): 	$(OBJ)
			$(CC) -g -L. -lmlx -framework OpenGL -framework Appkit -L libft -lft $(OBJ) -o $(NAME)


clean:
			rm -f $(OBJ) libft.a libmlx.a
			make -C libft/ clean
			make -C minilibx/ clean


fclean: 	clean
			rm -f $(NAME)
			make -C libft/ fclean
			make -C minilibx/ clean


re : 		fclean all

.PHONY:		all clean fclean re bonus libft minilibx