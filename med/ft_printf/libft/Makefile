# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:32:10 by dpolosuk          #+#    #+#              #
#    Updated: 2018/03/22 14:51:25 by ekiriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard *.c)
INCLUDE = libft.h
OBJECTS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

.c.o:
	@gcc -c $(CFLAGS) -I $(INCLUDE) $(SRC) $<

.PHONY: clean
clean:
	@/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
