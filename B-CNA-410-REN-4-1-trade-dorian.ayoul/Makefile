##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/main.cpp 			\
	  src/Settings.cpp		\
	  src/Calculator.cpp	\

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -g -I ./include

NAME = trade

all: $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re