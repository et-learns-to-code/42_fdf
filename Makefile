NAME = fdf

SRCS = $(addprefix srcs/, \
	bresenham.c controls.c draw.c elevation_color.c error_handling.c\
	gradient_color.c init.c main.c parse_map_utils.c parse_map.c \
	projection.c view.c)

OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx_linux/

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)

# Operating system detection.
# This calls an instance of the shell and assigns the result of the
# uname command to the OS variable.
# ':=' is for simple assignment, meaning the command is evaluated once
# at the time the Makefile is read. '=' is recursive assignment
# and is evaluated every time the variable is used.
OS := $(shell uname)

ifeq ($(OS),Darwin)
# MacOS (Darwin) libraries and frameworks are set only when the OS is detected.
# OpenGL: graphics API for rendering 2D and 3D vector graphics
# AppKit: macOS framework for building GUIs
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -framework OpenGL -framework AppKit
else
# Linux libraries are assumed for the default compilation.
# lmlx = libmlx.a (mlx library)
# lm = libm.a (math library)
# lft = libft.a (libft library)
# lX11, lXext (X11 Extension) and -lz (zlib) are MiniLibX dependency
# libraries on Linux systems.
LIBRARIES = -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lX11 -lXext -lz -lm -lft
endif

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC)  $(OBJS) $(LIBRARIES) -o $(NAME)

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
