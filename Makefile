# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 16:13:04 by delhajou          #+#    #+#              #
#    Updated: 2025/04/21 16:14:28 by delhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit 

SRC = srcs/fractol.c\
srcs/main.c\
srcs/render.c\
srcs/utils.c\
srcs/math.c\
srcs/events.c\
srcs/parsing.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re