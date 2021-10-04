# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 20:53:57 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/10/01 20:53:57 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_PRINTF = ./include/ft_printf/
P_LIBFT = ./include/libft/

FILES = ./server.c ./client.c
SRC = $(FILES:.c=.o)

PRINTF = $(P_PRINTF)libftprintf.a
LIBFT = $(P_LIBFT)libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: comp server client

server:
	@$(CC) $(CFLAGS) ./server.o $(PRINTF) $(LIBFT) -o server
	@echo Server done.

client:
	@$(CC) $(CFLAGS) ./client.o $(PRINTF) $(LIBFT) -o client
	@echo Client done.

comp: $(SRC)
	@make --no-print-directory -C $(P_PRINTF)
	@make --no-print-directory -C $(P_LIBFT)

%.o: %.c
	@$(CC) -c $< -o $@

bonus: all

clean:
	@make clean --no-print-directory -C $(P_LIBFT)
	@make clean --no-print-directory -C $(P_PRINTF)
	@$(RM) $(SRC)
	@echo All clean dude.

fclean: clean
	@make fclean --no-print-directory -C $(P_LIBFT)
	@make fclean --no-print-directory -C $(P_PRINTF)
	@$(RM) client server

re: fclean all
