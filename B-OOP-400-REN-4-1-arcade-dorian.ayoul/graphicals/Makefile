##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	make -C ./ncurses
	make -C ./SDL2
	make -C ./SFML

clean:
	make clean -C ./ncurses
	make clean -C ./SDL2
	make clean -C ./SFML

fclean: clean
	make fclean -C ./ncurses
	make fclean -C ./SDL2
	make fclean -C ./SFML

re: fclean all

.PHONY: all clean fclean re