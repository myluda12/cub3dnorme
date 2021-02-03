NAME = cub3D


MLX_PATH = /usr/local/lib
MLX_LIB = mlx

SRCS = cub3d.c ft_map_traitement.c ft_map_traitement1.c ft_map_traitement2.c ft_player_mouvement.c ft_ray_cast.c \
		ft_render_wallsprite.c ft_render_wallsprite2.c ft_free_keys.c ft_texture_wall.c ft_design_2d.c ft_start.c \
		ft_normalize_sort.c ft_atoi_h.c ft_atoi_w.c ft_atoi.c ft_bzero.c get_next_line.c get_next_line_utils.c \
		ft_calloc.c ft_file_traitement.c ft_file_traitement2.c ft_file_traitement3.c ft_graphic.c \
		ft_memcpy.c ft_memset.c ft_putstr.c ft_screenshot.c ft_split.c ft_strchr.c ft_strjoin.c ft_substr.c 

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall

ASAN = -g -fsanitize=address

$(NAME) :
	gcc -g $(SRCS) -L $(MLX_PATH) -l$(MLX_LIB)   \
	-lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)


re: fclean all
 .PHONY : all clean fclean re
bounus:
