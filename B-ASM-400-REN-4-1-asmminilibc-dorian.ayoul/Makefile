##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/strlen.asm\
	  src/strchr.asm\
	  src/strrchr.asm\
	  src/memset.asm\
	  src/memcpy.asm\
	  src/strcmp.asm\
	  src/memmove.asm\
	  src/strncmp.asm\
	  src/strcasecmp.asm\
	  src/strstr.asm\
	  src/strpbrk.asm\
	  src/strcspn.asm\

OBJ = $(SRC:.asm=.o)

NAME = libasm.so

all : $(NAME)

$(NAME) : $(OBJ)
	@ld  -o $(NAME) $(OBJ) -shared

%.o: %.asm
	@nasm -f elf64 $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@(make fclean -C test/) > /dev/null

re : fclean all

unit_tests: re
	@(make re -C test/) > /dev/null