NAME = fdf

SRCS = $(addprefix srcs/, \
	bresenham.c color.c controls.c draw.c error_handling.c \
	init.c main.c parse_map_utils.c parse_map.c projection.c \
	view.c)

OBJS = $(SRCS:.c=.o)

# libft path and library
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = -Iincludes
# lmlx = libmlx.a (mlx library)
# lm = libm.a (math library)
# lft = libft.a (libft library)
# OpenGL: graphics API for rendering 2D and 3D vector graphics
# AppKit: macOS framework for building GUIs
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -g $(LIBRARIES) $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
