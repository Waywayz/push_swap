FT_PRINTF = ft_printf/libftprintf.a

SRC = push_swap.c check_value.c operation.c algo.c \
      		libft/ft_atoi.c \
      		ft_printf/ft_printf.c \

OBJ = push_swap.o check_value.o operation.o algo.o \
      		libft/ft_atoi.o \
      		ft_printf/ft_printf.o \

HEADER = ./libft/libft.h push_swap.h

NAME = push_swap

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra $(SRC) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $OBJ

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
