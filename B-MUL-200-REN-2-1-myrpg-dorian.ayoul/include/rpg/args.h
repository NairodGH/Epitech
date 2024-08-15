/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** args
*/

#ifndef RPG_ARGS_H
#define RPG_ARGS_H

typedef struct args_s {
    char *key;
    char *value;
} args_t;

void parse_arg(list_t *list, char *arg, char *next_arg);

bool has_arg(list_t *args, char *key);

char *get_arg(list_t *args, char *key);

list_t *create_arg_list(int ac, char **av);

#endif