# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 15:34:15 by ekiriche          #+#    #+#              #
#    Updated: 2018/04/23 13:58:33 by ekiriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC1 = main.c \
	  basic_ops.c \
	  create_and_destroy_structs.c \
	  errors_handler.c \
	  file_handler.c \
	  finders.c \
	  one_arg_handler.c \
	  ops_a.c \
	  ops_b.c \
	  ops_both.c \
	  push_to_ab.c \
	  sorts.c \
	  ultimate_printer.c \
	  usefull_funcs.c \

SRC2 = checker.c \
	   basic_ops.c \
	   create_and_destroy_structs.c \
	   errors_handler.c \
	  file_handler.c \
	  finders.c \
	  one_arg_handler.c \
	  ops_a.c \
	  ops_b.c \
	  ops_both.c \
	  push_to_ab.c \
	  sorts.c \
	  ultimate_printer.c \
	  usefull_funcs.c \

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME1)

$(NAME1): $(OBJ1)
	make -C ./ft_printf/ all
	gcc -g $(OBJ1) -o $(NAME1) ./ft_printf/libftprintf.a

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make -C ./ft_printf/ clean
	rm -f $(OBJ1)

fclean: clean
	make -C ./ft_printf/ fclean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
