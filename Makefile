# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 13:39:06 by cbolanos          #+#    #+#              #
#    Updated: 2025/02/18 14:57:03 by cbolanos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I.

NAME = main
LIBFT = libft.a

SRC = main.c \
	utils/stack_generator.c \
	utils/ft_stack.c \
	utils/ft_array.c \
	utils/ft_push.c \
	utils/ft_rotate.c \
	utils/ft_reverse_rotate.c \
	utils/ft_swap.c

OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): 
	ar rcs $(LIBFT) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c libft.h push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

