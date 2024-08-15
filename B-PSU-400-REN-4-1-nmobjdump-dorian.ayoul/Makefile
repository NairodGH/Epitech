##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NM_SRCS	= src/nm.c

DUMP_SRCS =	src/objdump.c

NM_OBJS	= $(NM_SRCS:.c=.o)

DUMP_OBJS = $(DUMP_SRCS:.c=.o)

CFLAGS = -g -W -Wall -Wextra -I ./include

all: nm objdump

nm: $(NM_OBJS)
	gcc $(NM_OBJS) -g -o my_nm

objdump: $(DUMP_OBJS)
	gcc $(DUMP_OBJS) -g -o my_objdump

clean:
	rm -f ./my_nm
	rm -f ./my_objdump

fclean: clean
	rm -f $(NM_OBJS)
	rm -f $(DUMP_OBJS)

re: fclean all

.PHONY: all nm objdump clean fclean