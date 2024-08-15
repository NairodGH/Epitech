##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/ftrace.c									\
					src/ftrace_loop.c								\
					src/syscall_table.c								\
					src/handle_syscall.c							\
					src/handle_call.c								\
					src/handle_signal.c								\
					src/file_handler/get_maps_file.c				\
					src/file_handler/get_func_name.c				\
					src/file_handler/parse_maps_file.c				\
					src/file_handler/utils.c						\
					src/file_handler/elf_handler/get_section_hdr.c	\
					src/file_handler/elf_handler/elf_reader.c		\
					src/file_handler/read_file.c					\
					src/enter_func.c								\
					src/linked_list/manage_node.c					\
					src/linked_list/manage_list.c					\
					src/all_returns.c								\
					src/handle_ftrace_struct.c						\
					src/calls_list/call_e8.c						\
					src/calls_list/call_ff.c						\

SRC				+=	./src/main.c

SRC_TEST		=


#################### NAMES ######################
NAME			=	ftrace

NAME_TEST		=	unit_tests


##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)


##################### FLAGS #####################
CFLAGS			=	-I include -Wall -Wextra -W -lelf

CFLAGS_TEST		=	--coverage -lcriterion

CFLAGS_DEBUG	=	-g


################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@rm -f $(NAME)
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
	@$(ECHO) $(CLEAR)

unit_tests:	$(OBJ_TEST)
	gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)
	./$(NAME_TEST)

tests_run:	clean unit_tests

gcovr:	tests_run
	@gcovr --exclude tests
	@gcovr --exclude tests --branch

gen_html:	unit_tests
	@(mkdir -p tests/coverage) > /dev/null
	@(lcov -c -d . --output-file tests/coverage/lcov) > /dev/null
	@(genhtml tests/coverage/lcov --output-directory tests/coverage) > /dev/null

html_run:	gen_html
	@(firefox tests/coverage/index.html) > /dev/null
