# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:57:28 by hyunghki          #+#    #+#              #
#    Updated: 2023/07/19 11:20:47 by hyunghki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= miniRT
CFLAGS= -Wall -Werror -Wextra
DEBUG_FLAGS= -g3 -fsanitize=address
LDFLAGS= \
-Lmlx -lmlx -framework OpenGL -framework Appkit \
-lm
INCLUDE= \
-I./mandatory/includes \
-Imlx
SRC_DIR=./mandatory/srcs/
SRCS= $(SRC_DIR)get_next_line/get_next_line.c \
	  $(SRC_DIR)get_next_line/get_next_line_utils.c \
	  $(SRC_DIR)utils/lst.c \
	  $(SRC_DIR)utils/memmory.c \
	  $(SRC_DIR)utils/number.c \
	  $(SRC_DIR)utils/print.c \
	  $(SRC_DIR)utils/split.c \
	  $(SRC_DIR)utils/str.c \
	  $(SRC_DIR)parse/interface.c \
	  $(SRC_DIR)parse/utils.c \
	  $(SRC_DIR)parse/mk_struct.c \
	  $(SRC_DIR)parse/mk_struct2.c \
	  $(SRC_DIR)render/interface.c \
	  $(SRC_DIR)render/print_image.c \
	  $(SRC_DIR)render/calculate.c \
	  $(SRC_DIR)main.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

.PHONY: re clean fclean

re:
	make fclean
	make all

clean:
	@make clean -C mlx
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

$(NAME): $(OBJS)
	@make -C mlx
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)
