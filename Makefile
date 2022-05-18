LIBFT = libft/libft.a

NAME = push_swap

SRC = push_swap.c check_value.c operation.c operation_2.c operation_3.c algo.c \
      		libft/ft_atoi.c libft/ft_split.c libft/ft_strjoin.c \

OBJ = push_swap.o check_value.o operation.o operation_2.o operation_3.o algo.o \
      		libft/ft_atoi.o libft/ft_split.o libft/ft_strjoin.o \

HEADER = ./libft/libft.h push_swap.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	-rm -rf $(OBJ)

fclean: clean
	$(MAKE) clean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
