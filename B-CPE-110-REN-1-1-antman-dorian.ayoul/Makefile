##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all:
	make -C antman/
	make -C giantman/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all