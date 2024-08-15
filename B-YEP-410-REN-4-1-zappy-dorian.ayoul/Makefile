##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_LIBS		=	./libs/

PATH_AI			=	./ai/

PATH_SERVER		=	./server/

PATH_GUI		=	./gui/


################# COMPILATION #################

all: libs_all
	make -C	$(PATH_AI)
	make -C	$(PATH_SERVER)

libs_all:
	make -C	$(PATH_LIBS)

re:	fclean all graphic

graphic: install-raylib libs_all
	make -C	$(PATH_GUI)

clean:
	@(make clean -C $(PATH_LIBS)) > /dev/null
	@(make clean -C $(PATH_AI)) > /dev/null
	@(make clean -C $(PATH_SERVER)) > /dev/null
	@(make clean -C $(PATH_GUI)) > /dev/null

fclean:	clean clean-raylib
	@(make fclean -C $(PATH_LIBS)) > /dev/null
	@(make fclean -C $(PATH_AI)) > /dev/null
	@(make fclean -C $(PATH_SERVER)) > /dev/null
	@(make fclean -C $(PATH_GUI)) > /dev/null

debug: install-raylib
	@(make -C $(PATH_LIBS)) > /dev/null
	@(make debug -C $(PATH_AI)) > /dev/null
	@(make debug -C $(PATH_SERVER)) > /dev/null
	@(make debug -C $(PATH_GUI)) > /dev/null

unit-tests: all
	./utils/run_tests.sh

install-raylib:
	./utils/install_raylib.sh

clean-raylib:
	@(rm -rf include/raylib.h) > /dev/null
