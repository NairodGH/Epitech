##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= src/strace.c

OBJS = $(SRC:.c=.o)

NAME = strace

all: $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
