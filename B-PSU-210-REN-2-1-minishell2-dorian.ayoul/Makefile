##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = src/main.c \
	  src/builtins.c \
	  src/setenv.c \
	  src/cd.c \
	  src/exec.c \
	  src/pipe.c \

OBJ = $(SRC:.c=.o)

NAME = mysh

W_FLAGS = -W -Wall -Wextra -Werror

all: $(OBJ)
	@make -C lib/my
	@gcc -g -o $(NAME) $(SRC) -L lib/my -lmy -I lib/my

clean:
	@make clean -C lib/my
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: clean all