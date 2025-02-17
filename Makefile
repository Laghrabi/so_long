# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 12:22:28 by claghrab          #+#    #+#              #
#    Updated: 2025/02/17 15:05:31 by claghrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME = so_long
BNAME = so_long_bonus
SRCS = Mandatory/main.c	Mandatory/parsing1.c	Mandatory/error.c	Mandatory/window.c	Mandatory/rendering.c	Mandatory/parsing2.c	Mandatory/parsing3.c	Mandatory/parsing4.c
BSRCS = Bonus/main.c	Bonus/parsing1.c	Bonus/error.c	Bonus/window.c	Bonus/parsing2.c	Bonus/parsing3.c	Bonus/parsing4.c	Bonus/player.c	Bonus/rendering.c	Bonus/enemy.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) Libft/libft.a

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(MLX_FLAGS) -o $(BNAME) Libft/libft.a

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all
