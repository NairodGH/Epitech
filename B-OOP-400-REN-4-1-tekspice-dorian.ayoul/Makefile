##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/Main.cpp				\
	  src/Parser.cpp			\
	  src/Circuit.cpp			\
	  src/Component.cpp			\
	  src/Error.cpp				\
	  src/Gate.cpp				\
	  src/Pin.cpp				\
	  src/Chipsets/C2716.cpp	\
	  src/Chipsets/C4001.cpp	\
	  src/Chipsets/C4008.cpp	\
	  src/Chipsets/C4011.cpp	\
	  src/Chipsets/C4013.cpp	\
	  src/Chipsets/C4017.cpp	\
	  src/Chipsets/C4030.cpp	\
	  src/Chipsets/C4040.cpp	\
	  src/Chipsets/C4069.cpp	\
	  src/Chipsets/C4071.cpp	\
	  src/Chipsets/C4081.cpp	\
	  src/Chipsets/C4094.cpp	\
	  src/Chipsets/C4512.cpp	\
	  src/Chipsets/C4514.cpp	\
	  src/Chipsets/C4801.cpp	\
	  src/Chipsets/Logger.cpp	\
	  src/Chipsets/Input.cpp	\
	  src/Chipsets/Clock.cpp	\
	  src/Chipsets/True.cpp		\
	  src/Chipsets/False.cpp	\
	  src/Chipsets/Output.cpp	\
	  src/Factory.cpp			\

OBJ = $(SRC:.cpp=.o)

NAME = nanotekspice

CPPFLAGS = -W -Wall -Wextra -I ./include -I ./include/Chipsets

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all