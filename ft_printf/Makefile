# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerbs <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/30 17:59:12 by jerbs             #+#    #+#              #
#    Updated: 2020/01/03 20:37:59 by jerbs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
.C = *.c
.O = *.o

$(NAME):
	gcc $(FLAGS) -c $(.C)
	ar rcs $(NAME) $(.O) 	


all:	$(NAME)

clean:
	rm -rf $(.O)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re all
