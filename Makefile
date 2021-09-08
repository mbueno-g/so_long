
SO = $(shell uname -s)

#MacOs
LMLX = -lmlx -framework OpenGL -framework AppKit
LMLX_PATH = /usr/lib
IMLX_PATH = /usr/include

ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2

#Linux
ifeq ($(SO), Linux)
	LMLX = -L$(LMLX_PATH) -lmlx -lXext -lX11
	IMLX = -I$(IMLX_PATH)

	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
endif

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CDEBUG =
RM = rm -f
KEYCODES =  -D $(ESC) -D $(W) -D $(A) -D $(S) -D $(D)

LIBFT = Libft/libft.a
SRC_M = main.c map.c game.c init_structs.c error_exit.c enemy.c print_map.c animation.c
SRC_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_B =

OBJ_M = $(SRC_M:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_GNL) Libft
	$(CC) $(CFLAGS) $(CDEBUG) $(OBJ_M) $(OBJ_GNL) $(LIBFT) $(IMLX) $(LMLX) -o $@

$(OBJ_M): $(SRC_M)
	$(CC) $(CFLAGS) $(CDEBUG) $(KEYCODES) -c $^

$(OBJ_GNL): $(SRC_GNL)
	$(CC) $(CFLAGS) $(CDEBUG) -c $^
	mv -f get_next_line.o get_next_line_utils.o get_next_line/

Libft:
	make all -C Libft/

bonus: $(OBJ_B) $(OBJ_GNL) $(LIBFT)

$(OBJ_B): $(SRC_B)
	$(CC) $(CFLAGS) $(CDEBUG) -c $^

clean:
	make clean -C Libft/
	$(RM) $(OBJ_M) $(OBJ_B) $(OBJ_GNL)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all Libft bonus clean fclean re



