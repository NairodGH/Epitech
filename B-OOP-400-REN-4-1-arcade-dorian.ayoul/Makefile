##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all: core graphicals games

core:
	make -C ./core

graphicals:
	make -C ./graphicals

games:
	make -C ./games

clean:
	make clean -C ./core
	make clean -C ./graphicals
	make clean -C ./games

fclean: clean
	make fclean -C ./core
	make fclean -C ./graphicals
	make fclean -C ./games

re: fclean all

.PHONY: all core graphicals games clean fclean re