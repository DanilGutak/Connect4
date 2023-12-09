CFLAGS=-g -Wall -Wextra -Werror

CC=cc

DEPS=libft.h

___OBJ=ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o
__OBJ=$(___OBJ) ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o
_OBJ=$(__OBJ) ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o
OBJ=$(_OBJ) ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_itoa.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strjoin.o ft_strtrim.o ft_substr.o ft_striteri.o ft_strmapi.o get_next_line.o get_next_line_utils.o

NAME=libft.a


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
