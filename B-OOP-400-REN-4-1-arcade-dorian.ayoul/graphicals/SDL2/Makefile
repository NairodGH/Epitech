##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/SDL2.cpp \
	  src/entryPoint.cpp

OBJ = $(SRC:.cpp=.o)

NAME = arcade_sdl2.so

CPPFLAGS = -fno-gnu-unique -W -Wall -Wextra -fPIC -rdynamic -I ./include -I ../../include

all: $(OBJ)
	g++ -o ../../lib/$(NAME) $(OBJ) -shared -lSDL2main -lSDL2 -lSDL2_image

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re