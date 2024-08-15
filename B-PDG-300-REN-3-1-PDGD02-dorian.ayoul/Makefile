##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compiles the haskell
##

SRC = DoOp.hs

NAME = doop

all: $(NAME)

$(NAME):
	@(ghc $(SRC) -o $(NAME)) > /dev/null

clean:
	@find . -name "*.hi" -delete
	@find . -name "*.o" -delete

fclean: clean
	@find . -name $(NAME) -delete

re: fclean all