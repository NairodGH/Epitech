##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCS =  src/main.c				\
		src/server.c 			\
		src/init_server.c 		\
		src/clients.c			\
		src/save_data.c			\
		src/load_data.c 		\
		src/parser.c 			\
		src/message.c 			\
		src/client_func.c 		\
		src/linked_list.c 		\
		src/message_list.c 		\
		src/my_ltoa.c 			\
		src/init_team.c 		\
		src/team_member.c 		\
		src/remove_member.c 	\
		src/end_server.c 		\
		src/commands/sub.c		\
		src/commands/login.c	\
		src/commands/user.c 	\
		src/commands/help.c		\
		src/commands/create.c 	\
		src/commands/info.c		\
		src/commands/list.c		\
		src/commands/messages.c	\

OBJS = $(SRCS:.c=.o)

CDEBUG = -g

CWARN = -W -Wall -Wextra

CFLAGS  = -L ../nlib/ -lmy -I ../include -I ../libs/myteams/ -g $(CWARN) -luuid

LFLAGS = -L ../libs/myteams -lmyteams

NAME = myteams_server

all : $(NAME)

$(NAME) : $(OBJS)
		make -C ../nlib/
		gcc -o ../$(NAME) $(OBJS) $(CFLAGS) $(LFLAGS)
		make fclean -C ../nlib/

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ../$(NAME)

re : fclean all
