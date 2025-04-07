# Nom de l'exécutable
NAME = push_swap

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRCS =Ft_printf/ft_printf.c \
	Ft_printf/ft_put_hex.c Ft_printf/ft_put_per.c Ft_printf/ft_putchar.c Ft_printf/ft_putnbr_hex_maj.c Ft_printf/ft_putnbr_hex.c Ft_printf/ft_putnbr_uns.c Ft_printf/ft_putnbr.c Ft_printf/ft_putstr.c push_swap.c algo.c final_rotate.c init.c init2.c move.c parse.c push.c reverse_rotate.c rotate.c swap.c utils.c utils2.c utils3.c sorting_2.c
OBJS = $(SRCS:.c=.o)
# Commandes
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
