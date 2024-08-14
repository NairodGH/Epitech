##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = do_op.c

OBJ = $(SRC:.c=.o)

NAME = do-op

all: $(NAME)

$(NAME):
		gcc *.c -o $(NAME) -L ../lib -lmy -I ../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
