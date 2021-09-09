# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 18:25:46 by mbueno-g          #+#    #+#              #
#    Updated: 2021/09/09 15:42:54 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LMLX = -lmlx -framework OpenGL -framework AppKit
LMLX_LINUX = -lmlx -lXext -lX11
LMLX_PATH = /usr/lib
IMLX_PATH = /usr/include

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CDEBUG = 
RM = rm -f

LIBFT = Libft/libft.a
SRC_M = main.c map.c game.c init_structs.c error_exit.c enemy.c print_map.c animation.c
SRC_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_M = $(SRC_M:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_GNL) Libft
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ_M) $(OBJ_GNL) $(LIBFT) $(IMLX) $(LMLX) -o $@

$(OBJ_M): $(SRC_M)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $^

$(OBJ_GNL): $(SRC_GNL)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $^
	@mv -f get_next_line.o get_next_line_utils.o get_next_line/

Libft:
	@make all -C Libft/

bonus: all

test: all
	@read -p "Select map number: " map; \
	./so_long maps/map0$${map}.ber

clean:
	@make clean -C Libft/
	@$(RM) $(OBJ_M) $(OBJ_B) $(OBJ_GNL)

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all Libft bonus clean fclean re
