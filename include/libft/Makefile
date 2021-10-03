# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 15:06:48 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/10/01 23:44:38 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_atoi.c ft_putchar_fd.c
SRC = $(FILES:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(SRC)
	@ar -rcs $(NAME) $(SRC)

$(SRC): $(FILES)
	@$(CC) $(FLAGS) -c $(FILES)

clean:
	@$(RM) $(SRC)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
