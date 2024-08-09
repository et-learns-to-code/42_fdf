NAME = libft.a

# Source files
LIBFT_SRCS = $(addprefix libft/, \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

FT_PRINTF_SRCS = $(addprefix ft_printf/, \
		ft_print_char.c \
		ft_print_hex.c \
		ft_print_int.c \
		ft_print_pointer.c \
		ft_print_string.c \
		ft_print_unsigned.c \
		ft_printf.c \
		ft_putnbr_base.c \
		ft_strlen.c)

GNL_SRCS = $(addprefix get_next_line/, \
		get_next_line_utils.c \
		get_next_line.c)

# Object files
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Archive and remove commands
AR = ar -rc
RM = rm -f

# Targets
all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@$(AR) $(NAME) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
