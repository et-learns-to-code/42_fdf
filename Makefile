NAME = fdf

SRC = $(addprefix src/, \
	bresenham.c controls.c draw.c elevation_color.c error_handling.c \
	gradient_color.c init.c inverted_color.c main.c parse_line.c \
	parse_map_utils.c parse_map.c projection.c view.c)

OBJ_DIR = obj

# src/bresenham.c -> obj/bresenham.o
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

MLX_DIR = mlx_linux/

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Iinc -I$(MLX_DIR)

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

all: $(NAME)

# Create the obj directory if it doesn't exist
# -p (parents) flag will create parent directories if
# necessary and won't throw an error even if the directory
# already exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBRARIES) -o $(NAME)

# | $(OBJ_DIR) part ensures that the directory is created before
# the compilation happens.
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
