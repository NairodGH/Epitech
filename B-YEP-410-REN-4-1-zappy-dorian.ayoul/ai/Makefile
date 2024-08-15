##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	./src/loop_client.c				\
					./src/create_client.c			\
					./src/parse_ret.c				\
					./src/stdin.c 					\
					./src/send_message.c 			\
					./src/robot.c 					\
					./src/robot_2.c 				\
					./src/client_push_command.c 	\
					./src/utils.c 					\
					./src/handle_map.c 				\
					./src/path_finding_object.c 	\
					./src/change_direction.c 		\
					./src/print_info.c 				\
					./src/map_utils.c 				\
					./src/evoluate.c 				\
					./src/evoluate2.c 				\
					./src/evoluate3.c 				\
					./src/check_level.c 			\
					./src/check_level2.c 			\
					./src/round_pos_map.c 			\
					./src/broadcast_message.c 		\
					./src/player.c 					\
					./src/command/movement.c 		\
					./src/command/look_around.c 	\
					./src/command/broadcast.c	 	\
					./src/command/connect_nbr.c 	\
					./src/command/eject_player.c 	\
					./src/command/fork_player.c 	\
					./src/command/incantation.c 	\
					./src/command/inventory.c 		\
					./src/command/take_set_object.c \

SRC				+=	./src/main.c

#################### NAMES ######################
NAME			=	zappy_ai

##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib -luuid							\
					-Wl,-rpath=$(shell readlink -f "../libs/")				\

CFLAGS			=	$(INCLUDES) $(LIBS) -Wall -Wextra -W -fPIC

CFLAGS_DEBUG	=	-g


################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null
	@(cp $(NAME) ../)

all:	$(NAME)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete
	@find . -name "*.so" -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@(rm -f $(NAME)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
