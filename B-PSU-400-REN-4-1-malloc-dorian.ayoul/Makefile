##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= src/malloc.c \
	  src/others.c

OBJS = $(SRC:.c=.o)

NAME = libmy_malloc.so

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -fPIC -shared

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all