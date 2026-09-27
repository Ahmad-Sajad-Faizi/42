CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ../ex00/ft_putchar.c ../ex00/ft_swap.c ../ex00/ft_putstr.c \
		  ../ex00/ft_strlen.c ../ex00/ft_strcmp.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
