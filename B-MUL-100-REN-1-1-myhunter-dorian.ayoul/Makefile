##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all: $(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all