##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	make -C ./menu
	make -C ./nibbler
	make -C ./pacman

clean:
	make clean -C ./menu
	make clean -C ./nibbler
	make clean -C ./pacman

fclean: clean
	make fclean -C ./menu
	make fclean -C ./nibbler
	make fclean -C ./pacman

re: fclean all

.PHONY: all clean fclean re