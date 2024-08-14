##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = infin_add

all: $(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -L lib/ -lmy -I /include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all