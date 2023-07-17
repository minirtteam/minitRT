# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:57:28 by hyunghki          #+#    #+#              #
#    Updated: 2023/07/17 12:47:46 by hyunghki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=
CFLAGS= -Wall -Werror -Wextra
INCLUDE= \
-Iincludes
SRC_DIR= ./srcs/
SRCS= 
OBJS= $(SRCS:.c=.o)

all: $(NAME)

.PHONY: re clean fclean

re:
	make fclean
	make all

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)
