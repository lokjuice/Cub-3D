NAME		=	cub3d

SRCS		=	src/main.c \
				src/error/error.c \
				src/liba/liba_1.c \
				src/liba/liba_2.c \
				src/parser/pars.c \
				src/parser/lexer.c \
				src/parser/person.c \
				src/parser/perim.c \
				src/parser/map_reader.c \
				src/raycaster/load_init.c \
				src/raycaster/raycaster.c \
				src/raycaster/ft_dop_ray_textur.c \
				src/raycaster/mk_texture.c \
				src/raycaster/calc_asist.c \
				src/raycaster/key_k_x.c \
				src/raycaster/key_k_ar_x.c \
				src/raycaster/key_press.c \
				src/gnl/get_next_line.c \
				src/gnl/get_next_line_utils.c \

OBJS		= 	$(patsubst %.c,%.o,$(SRCS))

CC			= 	@gcc

CFLAGS		= 	-Wall -Wextra -Werror -I $(INCLUDES)

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	./inc/

RM			= 	rm -rf

all: 			$(NAME)

$(OBJS):		$(INCLUDES)

$(NAME): 		$(OBJS)
				@$(MAKE) -C ./minilibx_mms_20200219
				@cp ./minilibx_mms_20200219/libmlx.dylib .
				$(CC) -g $(CFLAGS) $(MLX) ./libmlx.dylib -o $(NAME) $(OBJS) 
				@echo "\033[30;42m      Program completed      \033[0m"

clean:
				@$(MAKE) clean -C ./minilibx_mms_20200219
				@${RM} $(OBJS)
				@echo "\033[30;43m        files deleted        \033[0m"

fclean:			clean
				@${RM} $(OBJS) $(NAME) ./libmlx.dylib
				@echo "\033[30;43m        files deleted        \033[0m"

re:				fclean all

.PHONY:			all clean fclean re