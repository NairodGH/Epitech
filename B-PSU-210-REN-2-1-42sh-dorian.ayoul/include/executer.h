/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef EXECUTER_H
#define EXECUTER_H

#include "shell.h"
#include "return.h"
#include "block.h"

typedef struct {
    char *name;
    void (*func)(shell_t *shell, return_t *ret, block_t *block);
} built_in_t;

void executer(shell_t *shell, return_t *ret, block_t *block);
void executer_fd(shell_t *shell, return_t *ret, block_t *block);
void executer_by_fd(shell_t *shell, return_t *ret, block_t *block, int fd);
void executer_fd_by_fd(shell_t *shell, return_t *ret, block_t *block, int fd);

void cd_func(shell_t *shell, return_t *ret, block_t *block);
void exit_func(shell_t *shell, return_t *ret, block_t *block);
void setenv_func(shell_t *shell, return_t *ret, block_t *block);
void unsetenv_func(shell_t *shell, return_t *ret, block_t *block);
void env_func(shell_t *shell, return_t *ret, block_t *block);
void echo_func(shell_t *shell, return_t *ret, block_t *block);
void unset_func(shell_t *shell, return_t *ret, block_t *block);
void set_func(shell_t *shell, return_t *ret, block_t *block);

// Set func utils
bool contain_equal(char *str);
bool equal_is_next(char *str);
int hook_set_value(char *str, variable_t *to_replace, size_t i);
variable_t *new_var(char **block, size_t *i, bool ronly);
variable_t *switcher(char **block, size_t *i, variable_t *replace, bool ronly);


char *copy_from_to(char *str, char start, char delim);

char *bstrcat_plus(char *word1, char *inter, char *word2);
char **env_to_array(list_t *list);
void get_binary_path(list_t *env, char **env_tab, return_t *ret,
block_t *block);
void child_exec(shell_t *shell, return_t *ret, block_t *block);
void create_child(shell_t *shell, return_t *ret, block_t *block);

void print_child_error(int status);

#endif // EXECUTER_H
