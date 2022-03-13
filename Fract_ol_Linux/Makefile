# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 02:08:07 by yhwang            #+#    #+#              #
#    Updated: 2022/03/02 00:11:44 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = fractol_utils \
	mandelbrot \
	julia \
	burning_ship \
	main \

MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm -lz

HEADER_DIR = ./

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS) $(HEADER_DIR)$ fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ -I$(HEADER_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
