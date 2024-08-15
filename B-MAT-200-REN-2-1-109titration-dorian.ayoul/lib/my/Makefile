##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = src/math/matrix/ope_square_matrices.c \
	  src/math/matrix/copy_square_matrix.c \
	  src/math/matrix/div_square_matrix.c \
	  src/math/matrix/get_square_matrix.c \
	  src/math/matrix/identity_matrix.c \
	  src/math/matrix/square_matrices_are_identical.c \
	  src/math/matrix/square_matrix_is_null.c \
	  src/math/matrix/trigo_square_matrix.c \
	  src/math/algebra/power.c \
	  \
	  src/libc/strings_are_identical.c \
	  src/libc/str_is_positive_int.c \
	  src/libc/string_length.c \
	  src/libc/display_int.c \
	  src/libc/display_char.c \
	  src/libc/get_int.c \
	  src/libc/get_height.c \
	  \
	  src/alloc/alloc_3d.c \
	  src/alloc/alloc_2d.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

.PHONY : all

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: clean all