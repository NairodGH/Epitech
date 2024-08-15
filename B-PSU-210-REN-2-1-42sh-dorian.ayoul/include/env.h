/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef ENV_H
#define ENV_H

#include "tokenizer.h"

typedef struct {
    char *var;
    char *value;
} env_t;

typedef struct {
    char *var;
    env_t *(*get_minimal_value)(void);
} minimal_env_t;

// CP ENV
list_t *cp_env(char **env);

// CREATE ENV
env_t *create_env(char *variable, char *value);
void destroy_env(void *data);

// MINIMAL ENV
env_t *get_path(void);
env_t *get_shlvl(void);
env_t *get_pwd(void);
env_t *get_oldpwd(void);
env_t *get_home(void);
bool minimal_env(list_t *env);

// GET ELEM ENV
char *get_env_value(char *var, list_t *env);
bool replace_env_value(char *var, char *new_value, list_t *env);

// PRINT
void print_env(list_t *env);

#endif // ENV_H
