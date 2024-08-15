##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compiles the library
##

SRC = 	src/Protocol.cpp 				\
		src/AI.cpp 						\
		src/main.cpp 					\

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -g -lm -I include -std=c++17 -Ofast

NAME = pbrain-gomoku-ai

NAME_EXE = pbrain-gomoku-ai.exe

all: $(OBJ)
	g++ -o $(NAME) $(SRC) $(CPPFLAGS)

w-exe: $(OBJ)
	x86_64-w64-mingw32-g++ -o $(NAME) $(SRC) $(CPPFLAGS) -static-libgcc -static-libstdc++

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
