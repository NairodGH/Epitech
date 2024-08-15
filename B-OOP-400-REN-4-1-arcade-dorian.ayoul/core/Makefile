##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/core.cpp 			\
	  ../src/main.cpp		\
	  ../src/Error.cpp		\

OBJ = $(SRC:.cpp=.o)

NAME = arcade

CPPFLAGS = -fno-gnu-unique -W -Wall -Wextra -I ./include -I ../graphicals -I ../games -I ../include -ldl -g

all: $(OBJ)
	g++ -o ../$(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re