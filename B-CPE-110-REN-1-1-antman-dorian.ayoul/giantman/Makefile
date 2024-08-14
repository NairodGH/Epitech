##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all:
	gcc -g -o giantman $(SRC) -I include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all