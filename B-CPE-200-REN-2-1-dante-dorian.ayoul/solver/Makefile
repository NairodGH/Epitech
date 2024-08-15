##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = main.c \

OBJ = $(SRC:.c=.o)

NAME = solver

all: $(OBJ)
	@make -C ../lib/my
	@gcc -g -W -Wall -Wextra -Werror -o $(NAME) $(SRC) -L ../lib/my -lmy -I ../lib/my

clean:
	@make clean -C ../lib/my
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: clean all