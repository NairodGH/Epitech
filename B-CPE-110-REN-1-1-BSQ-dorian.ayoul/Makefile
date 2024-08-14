##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = bsq

all:
	gcc -o $(NAME) $(SRC) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all