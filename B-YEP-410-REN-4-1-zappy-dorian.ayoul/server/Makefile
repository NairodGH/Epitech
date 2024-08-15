##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/manage_struct/manage_client.c						\
					src/manage_struct/manage_core.c							\
					src/manage_struct/manage_game.c							\
					src/manage_struct/manage_inventory.c					\
					src/manage_struct/manage_map.c							\
					src/manage_struct/manage_server.c						\
					src/manage_struct/manage_team.c							\
					src/manage_struct/manage_trantorian.c					\
					src/utils/parse_params.c								\
					src/utils/set_fds.c										\
					src/server_handling/server_handling.c					\
					src/server_handling/start_server.c						\
					src/client_handling/client_update.c						\
					src/client_handling/client_def_exec_command.c			\
					src/client_handling/default_commands/forward.c			\
					src/client_handling/default_commands/right.c			\
					src/client_handling/default_commands/left.c				\
					src/client_handling/default_commands/look.c				\
					src/client_handling/default_commands/inventory.c		\
					src/client_handling/default_commands/broadcast.c		\
					src/client_handling/default_commands/connect_nbr.c		\
					src/client_handling/default_commands/fork.c				\
					src/client_handling/default_commands/eject.c			\
					src/client_handling/default_commands/take.c				\
					src/client_handling/default_commands/set.c				\
					src/client_handling/default_commands/incantation.c		\
					src/client_handling/default_commands/death.c			\
					src/utils/command_utils.c								\
					src/utils/is_uuid.c										\
					src/client_handling/client_command_utils.c				\
					src/client_handling/gui_commands/msz.c					\
					src/client_handling/gui_commands/bct.c					\
					src/client_handling/gui_commands/mct.c					\
					src/client_handling/gui_commands/tna.c					\
					src/client_handling/gui_commands/ppo.c					\
					src/client_handling/gui_commands/plv.c					\
					src/client_handling/gui_commands/pin.c					\
					src/client_handling/gui_commands/sgt.c					\
					src/client_handling/gui_commands/sst.c					\
					src/client_handling/gui_commands/pnw.c					\
					src/client_handling/gui_commands/pex.c					\
					src/client_handling/gui_commands/pbc.c					\
					src/client_handling/gui_commands/pic.c					\
					src/client_handling/gui_commands/pie.c					\
					src/client_handling/gui_commands/pfk.c					\
					src/client_handling/gui_commands/pdr.c					\
					src/client_handling/gui_commands/pgt.c					\
					src/client_handling/gui_commands/pdi.c					\
					src/client_handling/gui_commands/enw.c					\
					src/client_handling/gui_commands/eht.c					\
					src/client_handling/gui_commands/ebo.c					\
					src/client_handling/gui_commands/edi.c					\
					src/client_handling/gui_commands/seg.c					\
					src/client_handling/gui_commands/smg.c					\
					src/client_handling/gui_commands/suc.c					\
					src/client_handling/gui_commands/sbp.c					\
					src/client_handling/client_define_type.c				\
					src/client_handling/client_gui_exec_command.c			\
					src/game_handling/game_utils/game_calc.c				\
					src/game_handling/game_utils/game_utils.c				\
					src/game_handling/game_update.c							\
					src/game_handling/game_update_handler.c					\
					src/game_handling/game_update_trantorians.c				\
					src/game_handling/game_utils/game_calc_sound_dir.c		\
					src/game_handling/game_update_map.c						\
					src/game_handling/game_utils/game_map_utils.c			\
					src/game_handling/game_utils/game_look_utils.c			\
					src/game_handling/game_utils/game_look_utils_2.c		\
					src/game_handling/game_utils/trantorian_utils.c			\
					src/client_handling/clients_update_delete.c				\
					src/manage_struct/manage_incantation.c					\
					src/game_handling/game_update_incantations.c			\
					src/utils/parse_params_2.c								\

SRC				+=	./src/main.c

#################### NAMES ######################
NAME			=	zappy_server

##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib -luuid	-lm						\
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
