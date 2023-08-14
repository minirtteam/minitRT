# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:57:28 by hyunghki          #+#    #+#              #
#    Updated: 2023/08/09 16:57:38 by hyunghki         ###   ########.fr        #
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
-I./bonus/includes \
-Imlx
SRC_DIR=./mandatory/srcs/
BSRC_DIR=./bonus/srcs/
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
	  $(SRC_DIR)calculate/interface.c \
	  $(SRC_DIR)calculate/hit_chk.c \
	  $(SRC_DIR)calculate/hit_chk_utils.c \
	  $(SRC_DIR)calculate/lights.c \
	  $(SRC_DIR)vector/operator.c \
	  $(SRC_DIR)vector/operator2.c \
	  $(SRC_DIR)vector/coord_cal.c \
	  $(SRC_DIR)vector/coord_cal2.c \
	  $(SRC_DIR)main.c
BSRCS= $(BSRC_DIR)get_next_line/get_next_line_bonus.c \
	   $(BSRC_DIR)get_next_line/get_next_line_utils_bonus.c \
	   $(BSRC_DIR)utils/lst_bonus.c \
	   $(BSRC_DIR)utils/memmory_bonus.c \
	   $(BSRC_DIR)utils/number_bonus.c \
	   $(BSRC_DIR)utils/print_bonus.c \
	   $(BSRC_DIR)utils/split_bonus.c \
	   $(BSRC_DIR)utils/str_bonus.c \
	   $(BSRC_DIR)parse/interface_bonus.c \
	   $(BSRC_DIR)parse/utils_bonus.c \
	   $(BSRC_DIR)parse/mk_struct_bonus.c \
	   $(BSRC_DIR)parse/mk_struct2_bonus.c \
	   $(BSRC_DIR)render/interface_bonus.c \
	   $(BSRC_DIR)render/print_image_bonus.c \
	   $(BSRC_DIR)render/get_bump_info_bonus.c \
	   $(BSRC_DIR)calculate/interface_bonus.c \
	   $(BSRC_DIR)calculate/hit_chk_bonus.c \
	   $(BSRC_DIR)calculate/hit_chk2_bonus.c \
	   $(BSRC_DIR)calculate/u_v_color.c \
	   $(BSRC_DIR)calculate/hit_chk_utils_bonus.c \
	   $(BSRC_DIR)calculate/lights_bonus.c \
	   $(BSRC_DIR)vector/operator_bonus.c \
	   $(BSRC_DIR)vector/operator2_bonus.c \
	   $(BSRC_DIR)vector/coord_cal_bonus.c \
	   $(BSRC_DIR)vector/coord_cal2_bonus.c \
	   $(BSRC_DIR)main_bonus.c
OBJS= $(SRCS:.c=.o)
BOBJS= $(BSRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILE = $(BOBJS)
else
	OBJ_FILE = $(OBJS)
endif

all: $(NAME)

.PHONY: re clean fclean bonus

re:
	make fclean
	make all

clean:
	@make clean -C mlx
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean:
	make clean
	rm -f $(NAME)

bonus:
	@make WITH_BONUS=1 all

$(NAME): $(OBJ_FILE)
	@make -C mlx
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG_FLAG)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(DEBUG_FLAG)
