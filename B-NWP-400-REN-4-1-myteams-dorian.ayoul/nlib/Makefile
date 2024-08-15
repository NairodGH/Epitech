##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	socket/create_socket.c				\
			socket/init_socket.c				\
			socket/destroy_socket.c				\
			socket/read_socket.c				\
			select/select.c						\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I ./include -W

NAME	=	libmy.a

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp -r include/* ../include
	@cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
