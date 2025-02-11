# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 12:22:28 by claghrab          #+#    #+#              #
#    Updated: 2025/02/11 17:53:51 by claghrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME = so_long
BNAME = so_long_bonus
SRCS = Mandatory/main.c	Mandatory/parsing.c	Mandatory/error.c	Mandatory/window.c
BSRCS = Bonus/main.c	Bonus/parsing.c	Bonus/error.c	Bonus/window.c
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
