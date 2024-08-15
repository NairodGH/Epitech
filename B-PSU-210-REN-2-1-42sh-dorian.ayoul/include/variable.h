/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct {
    char *var;
    char *value;
    char **alias;
    bool read_only;
} variable_t;

typedef struct {
    char *var;
    variable_t *(*get_minimal_value)(void);
} minimal_var_t;

variable_t *create_variable(char *variable, char *value, bool read_only);

void destroy_variable(void *var);

void print_variable(list_t *variable);
char *get_var_value(list_t *variable, char *var);
variable_t *get_shell_var(list_t *var, char *name);

char *check_var_buf(shell_t *shell, return_t *ret, char *readed);
size_t get_next_pos(char *buffer, size_t adv);
char *dup_no_junk(char *readed, size_t size);

variable_t *get_status(void);
bool minimal_var(list_t *variable);

#endif // VARIABLE_H
