##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = strlen_tests.c\
	  strchr_tests.c\
	  strrchr_tests.c\
	  memset_tests.c\
	  memcpy_tests.c\
	  strcmp_tests.c\
	  memmove_tests.c\
	  strncmp_tests.c\
	  strcasecmp_tests.c\
	  strstr_tests.c\
	  strpbrk_tests.c\
	  strcspn_tests.c\

OBJ = $(SRC:.c=.o)

NAME = unit_tests

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc -o $(NAME) $(OBJ) --coverage -lcriterion -ldl
	@./$(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(SRC:.c=.gcno)

re : fclean all