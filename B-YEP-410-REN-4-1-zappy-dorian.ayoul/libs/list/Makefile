##
## EPITECH PROJECT, 2022
## Blib
## File description:
## Makefile
##

SRC		=	src/push_node.c				\
			src/manage_list.c			\
			src/manage_node.c			\
			src/remove_node.c			\
			src/print_list.c			\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I include -W -Wall -Wextra -shared -g -fPIC

NAME	=	liblist.so

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@cp -r include/ ../../
	@cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
