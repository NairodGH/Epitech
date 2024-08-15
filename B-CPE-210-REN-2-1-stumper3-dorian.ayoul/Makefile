##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = 	src/main.c\
	src/utils.c\
	src/pile.c\

OBJ = $(SRC:.c=.o)

NAME = sandpile

all: $(NAME)

$(NAME):
	gcc -I ./include -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
