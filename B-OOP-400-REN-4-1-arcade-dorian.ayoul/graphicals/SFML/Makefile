##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/SFML.cpp \
	  src/entryPoint.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_sfml.so

CPPFLAGS = -fno-gnu-unique -W -Wall -Wextra -fPIC -rdynamic -I ./include -I ../../include

all: $(OBJ)
	g++ -o ../../lib/$(NAME) $(OBJ) -shared -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re