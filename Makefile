# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:05:46 by rovillar          #+#    #+#              #
#    Updated: 2022/06/21 16:05:48 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

NAME = push_swap

SRC = push_swap.c check_value.c operation.c operation_2.c operation_3.c algo.c utils.c fill_tab.c \
      		libft/ft_atoi.c libft/ft_split.c libft/ft_strjoin.c libft/ft_calloc.c \

OBJ = $(SRC:.c=.o)

HEADER = ./libft/libft.h push_swap.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) bonus -C./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(HEADER)


clean:
	$(MAKE) clean -C ./libft
	-rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
