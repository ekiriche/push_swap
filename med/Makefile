# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 15:34:15 by ekiriche          #+#    #+#              #
#    Updated: 2018/03/22 16:20:52 by ekiriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

$(NAME): all

all:
	gcc -g main.c ft_printf/libftprintf.a -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
