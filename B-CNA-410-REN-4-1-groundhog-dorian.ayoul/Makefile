##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/main.cpp \
	  src/groundhog.cpp \
	  src/error.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -g -I ./include

NAME = groundhog

all: $(OBJ)
	@g++ -o $(NAME) $(OBJ)

clean:
	@rm -f ./groundhog

fclean: clean
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re