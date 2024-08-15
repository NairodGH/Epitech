##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = 307multigrains.cpp

OBJ = $(SRC:.cpp=.o)

NAME = 307multigrains

CPPFLAGS = -g -lm

all: $(OBJ)
	g++ -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all