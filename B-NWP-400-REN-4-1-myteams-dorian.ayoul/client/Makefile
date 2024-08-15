##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCS =  src/main.c				\
		src/gest_message.c		\
		src/loop_client.c		\
		src/parse_input.c 		\
		src/split_client.c 		\
		src/parse_ret.c 		\
		src/get_arg.c 			\
		src/utils.c 			\
		src/my_itoa.c 			\
		src/command/login.c 	\
		src/command/create.c 	\
		src/command/use.c 		\
		src/command/error.c 	\

OBJS = $(SRCS:.c=.o)

CWARN = -W -Wall -Wextra

CFLAGS  = -L ../nlib/ -lmy -I ../include -I ../libs/myteams/ -g $(CWARN) -luuid

LFLAGS = -L ../libs/myteams -lmyteams

CDEBUG = -g

NAME = myteams_cli

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
