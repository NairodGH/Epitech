##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/env/cp_env.c										\
					src/env/create_env.c									\
					src/env/destroy_env.c									\
					src/env/minimal_env/get_min_env.c						\
					src/env/minimal_env/minimal_env.c						\
					src/env/print_env.c										\
					src/env/find_var.c										\
					src/env/env_to_array.c									\
					src/main_loop.c											\
					src/parsing/parser.c									\
					src/parsing/get_pos.c									\
					src/parsing/create_elem_parsing.c						\
					src/parsing/destroy_elem_parsing.c						\
					src/parsing/err_case.c									\
					src/parsing/over_parser.c								\
					src/parsing/parsing_utils.c								\
					src/resolver/resolver.c									\
					src/resolver/resolv_function/r_and.c					\
					src/resolver/resolv_function/r_double_left.c			\
					src/resolver/resolv_function/r_double_right.c			\
					src/resolver/resolv_function/r_left.c					\
					src/resolver/resolv_function/r_or.c						\
					src/resolver/resolv_function/r_pipe.c					\
					src/resolver/resolv_function/r_right.c					\
					src/resolver/resolv_function/r_sep.c					\
					src/resolver/print_fd.c									\
					src/executer/exec_func/env_func.c						\
					src/executer/exec_func/exit_func.c						\
					src/executer/exec_func/cd_func.c						\
					src/executer/exec_func/setenv_func.c					\
					src/executer/exec_func/unsetenv_func.c					\
					src/executer/exec_func/echo_func.c						\
					src/executer/exec_func/set_func.c						\
					src/executer/exec_func/unset_func.c						\
					src/executer/executer.c									\
					src/executer/child_command.c							\
					src/executer/child_error.c								\
					src/executer/exec_func/exec_utils.c						\
					src/executer/exec_func/set_utils.c						\
					src/variable/create_variable.c							\
					src/variable/destroy_variable.c							\
					src/variable/print_variable.c							\
					src/variable/get_var_value.c							\
					src/variable/check_var_buf.c							\
					src/variable/var_utils.c								\
					src/variable/minimal_var/get_min_value.c				\
					src/variable/minimal_var/minimal_var.c					\
					src/error_handling/error_with_command.c					\
					src/verif_block/verif_block.c							\
					src/verif_block/resolv_function/verif_and.c				\
					src/verif_block/resolv_function/verif_left.c			\
					src/verif_block/resolv_function/verif_or.c				\
					src/verif_block/resolv_function/verif_pipe.c			\
					src/verif_block/resolv_function/verif_right.c			\
					src/destroy_all.c										\

SRC				+=	main.c

SRC_TEST		=


#################### NAMES ######################
NAME			=	42sh

NAME_TEST		=	unit_tests


##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)


##################### FLAGS #####################
CFLAGS			=	-I include -L lib/ -lblib -llinked_list -Wall -Wextra -W

CFLAGS_TEST		=	--coverage -lcriterion

CFLAGS_DEBUG	=	-g


################## COMPILATION ##################
$(NAME):	$(OBJ)
	@make -C lib/blib
	@make -C lib/linked_list
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(make clean -C lib/blib) > /dev/null
	@(make clean -C lib/linked_list) > /dev/null
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(make fclean -C lib/blib) > /dev/null
	@(make fclean -C lib/linked_list) > /dev/null
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
