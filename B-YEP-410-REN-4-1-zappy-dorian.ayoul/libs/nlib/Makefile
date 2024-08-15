##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	socket/manage_socket.c				\
			socket/init_socket.c				\
			socket/read_socket.c				\
			socket/write_socket.c				\
			select/select.c						\
			queue/update_command.c				\
			queue/remove_socket_command.c		\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I include -I ../../include -W -Wall -Wextra			\
			-shared -g -fPIC -L ../ -llist

NAME	=	libnlib.so

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
