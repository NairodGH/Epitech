##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	make -C ./server
	make -C ./client

server:
	make -C ./server

client:
	make -C ./client

clean:
	make clean -C ./server
	make clean -C ./client

fclean: clean
	make fclean -C ./server
	make fclean -C ./client

re: fclean all
