##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= src/ftp.c \
	  src/commands.c \
	  src/commands2.c \
	  src/commands3.c

OBJS = $(SRC:.c=.o)

NAME = myftp

CPPFLAGS = -I ./include -g

all: $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all