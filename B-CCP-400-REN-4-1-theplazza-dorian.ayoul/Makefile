##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = 	src/Cook.cpp \
		src/Error.cpp \
		src/Kitchen.cpp \
		src/main.cpp \
		src/Parser.cpp \
		src/Pizza.cpp \
		src/Reception.cpp \
		src/Stock.cpp \
		src/IPC.cpp \
		src/Mutex.cpp \
		src/Condition.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = plazza

CPPFLAGS = -I ./include -g -lrt -lpthread

all: $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re