#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 14:33:02 by dtomchys          #+#    #+#              #
#    Updated: 2017/11/10 20:27:12 by dtomchys         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
HDDIRS = -I libft.h
SRC =ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c\
ft_memdel.c\
ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c\
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
ft_strcmp.c ft_strncmp.c ft_atoi.c\
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_toupper.c ft_tolower.c\
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
ft_strtrim.c ft_strsplit.c\
ft_itoa.c\
ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
get_next_line.c ft_dec_wstr.c ft_wchar_len.c ft_wstr_bytelen.c ft_wstrlen.c\
ft_itoa_base.c\
./ft_printf/ft_printf.c ./ft_printf/ft_buf.c ./ft_printf/ft_reset_arg.c\
./ft_printf/ft_set_mod.c ./ft_printf/ft_set_pre.c ./ft_printf/ft_set_wid.c\
./ft_printf/ft_set_sign.c ./ft_printf/ft_set_sharp.c ./ft_printf/ft_handle_ch.c\
./ft_printf/ft_handle_num.c ./ft_printf/ft_handle_num_base.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c ./libft.h
	$(CC) $(CFLAGS) -c $< -o $@ $(HDDIRS)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) libft.a

re: fclean all

.PHONY: clean fclean
