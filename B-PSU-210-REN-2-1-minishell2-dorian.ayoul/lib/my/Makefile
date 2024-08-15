##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiles the library
##

SRC = src/libc/strings_are_identical.c \
	  src/libc/str_is_positive_int.c \
	  src/libc/string_length.c \
	  src/libc/display_int.c \
	  src/libc/display_char.c \
	  src/libc/get_int.c \
	  src/libc/get_height.c \
	  src/libc/copy_string.c \
	  src/libc/get_unsigned.c \
	  src/libc/copy_2d.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

.PHONY : all

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: clean all