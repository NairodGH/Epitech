##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	./src/stdin.c				\
					./src/create_client.c		\
					./src/loop_client.c			\
					./src/parse_ret.c			\
					./src/send_message.c		\
					./src/utils.c 				\
					./src/loop_command.c 		\
					./src/print_info.c 			\
					./src/free_player.c 		\
					./src/get_command.c 		\
					./src/handle_clock.c 		\
					./src/command_gui/bct.c		\
					./src/command_gui/mct.c		\
					./src/command_gui/msz.c		\
					./src/command_gui/pnw.c		\
					./src/command_gui/ppo.c		\
					./src/command_gui/pdi.c		\
					./src/command_gui/pin.c		\
					./src/command_gui/tna.c		\
					./src/command_gui/sgt.c 	\
					./src/command_gui/pic.c		\
					./src/command_gui/pie.c		\
					./src/command_gui/seg.c		\
					./src/graphics/draw.c		\
					./src/graphics/utils.c		\
					./src/graphics/draw_items.c	\
					./src/graphics/utils_font.c	\

SRC				+=	./src/main.c

#################### NAMES ######################
NAME			=	zappy_gui

##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib -luuid	-l:libraylib.so.4.0.0	\
					-Wl,-rpath=$(shell readlink -f "../libs/")				\

CFLAGS			=	$(INCLUDES) $(LIBS) -Wall -Wextra -W -fPIC -lm

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
