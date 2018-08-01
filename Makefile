# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 12:48:40 by dtomchys          #+#    #+#              #
#    Updated: 2018/02/27 12:48:50 by dtomchys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME_P = push_swap
CC = gcc -Wall -Werror -Wextra -g3
RM = rm -f
HD = swap.h
MFLIB = ./libft
SRC = ft_validator.c ft_manage_lst.c ft_swaps.c ft_pushes.c\
ft_rotates.c ft_revr.c ft_quick_sort.c ft_sort_toools.c\
ft_brut_sort.c ft_sort_three.c ft_devides.c ft_bubble_sort.c ft_descending.c\

SRC_C = ft_checker.c
SRC_P = push_swap.c 
OBJ_C = $(SRC_C:.c=.o) $(SRC:.c=.o)
OBJ_P = $(SRC_P:.c=.o) $(SRC:.c=.o)

all: $(NAME_P) $(NAME)

OBJ_C: $(SRC_C) $(SRC) swap.h
	$(CC) $(SRC_C) $(SRC) $(HD) -c

OBJ_P: $(SRC_P) $(SRC) swap.h
	$(CC) $(SRC_P) $(SRC) $(HD) -c

$(NAME_P): $(OBJ_P) $(HD)
	make -C $(MFLIB)
	$(CC) -o $(NAME_P) $(OBJ_P) -I.$(HD) libft/libft.a

$(NAME):  $(OBJ_C) $(HD)
	make -C $(MFLIB)
	$(CC) -o $(NAME) $(OBJ_C) -I.$(HD) libft/libft.a

clean:
	make clean -C $(MFLIB)
	$(RM) $(OBJ_C) $(OBJ_P)

fclean: clean
	$(RM) $(NAME) $(NAME_P) libft.a

re: fclean all

.PHONY: clean fclean
