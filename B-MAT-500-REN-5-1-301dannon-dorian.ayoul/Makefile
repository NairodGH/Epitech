##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = 301dannon.cpp

OBJ = $(SRC:.cpp=.o)

NAME = 301dannon

CPPFLAGS = -g -lm

all: $(OBJ)
	g++ -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all