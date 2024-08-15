##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= src/panoramix.c

OBJS = $(SRC:.c=.o)

NAME = panoramix

CPPFLAGS = -I ./include -lpthread -g

all: $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
