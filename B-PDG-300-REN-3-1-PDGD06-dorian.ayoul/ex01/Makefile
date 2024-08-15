##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = my_convert_temp

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(SRC) -o $(NAME) -g -std=c++20 -Wall -Wextra -Werror

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all