##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = z.c \

OBJ = $(SRC:.c=.o)

NAME = z

all: $(NAME)

$(NAME):
	gcc -g -std=gnu17 -Wall -Wextra -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all