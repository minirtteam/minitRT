# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:57:28 by hyunghki          #+#    #+#              #
#    Updated: 2023/07/17 14:54:30 by hyunghki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= miniRT
CFLAGS= -Wall -Werror -Wextra
DEBUG_FLAGS= -g3 -fsanitize=address
INCLUDE= \
-Iincludes
SRC_DIR	=./srcs/
SRCS	= $(SRC_DIR)get_next_line/get_next_line.c \
		  $(SRC_DIR)get_next_line/get_next_line_utils.c \
		  $(SRC_DIR)utils/lst.c \
		  $(SRC_DIR)utils/memmory.c \
		  $(SRC_DIR)utils/number.c \
		  $(SRC_DIR)utils/print.c \
		  $(SRC_DIR)utils/split.c \
		  $(SRC_DIR)utils/str.c \
		  $(SRC_DIR)parse/interface.c \
		  $(SRC_DIR)main.c
OBJS	= $(SRCS:.c=.o)

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
	$(CC) -o $@ $^ $(DEBUG_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(DEBUG_FLAGS)
