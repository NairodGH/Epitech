##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/Menu.cpp 		\
	  src/entryPoint.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = arcade_menu.so

CPPFLAGS = -fno-gnu-unique -W -Wall -Wextra -fPIC -rdynamic -I ./include -I ../../include

all: $(OBJ)
	g++ -o ../../lib/$(NAME) $(OBJ) -shared -lncurses

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re