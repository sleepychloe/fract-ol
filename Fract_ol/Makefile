# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 02:08:07 by yhwang            #+#    #+#              #
#    Updated: 2022/07/17 20:03:18 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm -lz
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

FILES = fractol_utils \
	mandelbrot \
	julia \
	burning_ship \
	main \

INCS_DIR = ./incs
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(FILES)))

.c.o: $(SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $^ -o $@ -I$(HEADER_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
