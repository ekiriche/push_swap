# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 15:34:15 by ekiriche          #+#    #+#              #
#    Updated: 2018/04/20 13:04:36 by ekiriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
$(NAME): all

all:
	gcc -g main.c ft_printf/libftprintf.a -o $(NAME1)
	gcc -g checker.c ft_printf/libftprintf.a -o $(NAME2)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
