#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 12:48:23 by gmelisan          #+#    #+#              #
#    Updated: 2018/11/25 19:33:23 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

include sources.mk

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f test_exe

re: fclean all

test:
	@rm -f test_exe
	@gcc test.c -L. -lft -o test_exe
	./test_exe

test_dbg: test_clean
	@gcc -g test.c -L. -lft -o test_exe
	lldb test_exe

test_clean:
	@rm -f test_exe
	@rm -rf test_exe.dSYM/
