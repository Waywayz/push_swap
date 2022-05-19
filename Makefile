LIBFT = libft/libft.a

NAME = push_swap

SRC = push_swap.c check_value.c operation.c operation_2.c operation_3.c algo.c utils.c \
      		libft/ft_atoi.c libft/ft_split.c libft/ft_strjoin.c libft/ft_calloc.c \

OBJ = $(SRC:.c=.o)

HEADER = ./libft/libft.h push_swap.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C./libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) $(HEADER)


clean:
	$(MAKE) clean -C ./libft
	-rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
