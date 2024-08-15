##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = src/libstring1.c \
	  src/libstring2.c \
	  src/libstring3.c \

OBJ = $(SRC:.c=.o)

NAME = libstring.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

try: re
	gcc $(SRC) -g -std=gnu17 -Wall -Wextra
	./a.out

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all