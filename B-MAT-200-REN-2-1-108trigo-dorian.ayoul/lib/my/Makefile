##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = src/math/add_square_matrices.c \
	  src/math/copy_square_matrix.c \
	  src/math/div_square_matrix.c \
	  src/math/get_square_matrix.c \
	  src/math/identity_matrix.c \
	  src/math/mul_square_matrices.c \
	  src/math/square_matrices_are_identical.c \
	  src/math/square_matrix_is_null.c \
	  src/math/sub_square_matrices.c \
	  src/math/trigo_square_matrix.c \
	  \
	  src/string/strings_are_identical.c \
	  src/string/str_is_positive_int.c \
	  \
	  src/alloc/alloc_3d.c \
	  src/alloc/alloc_2d.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

.PHONY : all

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: clean all