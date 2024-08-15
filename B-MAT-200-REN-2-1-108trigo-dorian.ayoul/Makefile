##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = src/108trigo.c

OBJ = $(SRC:.c=.o)

NAME = 108trigo

all: $(NAME)

$(NAME):
	make -C lib/my
	gcc -g -lm -o $(NAME) $(SRC) -L lib/my/ -lmy -I lib/my/

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all