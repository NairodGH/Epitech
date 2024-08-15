##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = 201yams.c \

OBJ = $(SRC:.c=.o)

NAME = 201yams

all: $(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all