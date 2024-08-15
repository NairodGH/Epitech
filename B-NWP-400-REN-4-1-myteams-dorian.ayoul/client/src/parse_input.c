/*
** EPITECH PROJECT, 2022
** parse_input.c
** File description:
** parse_input
*/

#include "client.h"

bool get_one_word(char *message, char *arg, size_t *i, size_t *s)
{
    while (message[*i] != '\n' && message[*i] != '\0' && message[*i] != '"') {
        arg[*s] = message[*i];
        (*i)++;
        (*s)++;
    }
    if (message[*i] == '\n' || message[*i] == '\0')
        return false;
    (*i)++;
    arg[*s] = ']';
    (*s)++;
    arg[*s] = '[';
    (*s)++;
    return true;
}

char *get_inputs(char **current, bool *first)
{
    char buffer[4096];
    int ret = read(0, buffer, 4096);

    if (ret <= 0) {
        printf("error\n");
        return NULL;
    }
    if (buffer[ret - 1] == '\n')
        buffer[ret - 1] = '\0';
    else
        buffer[ret] = '\0';
    if (buffer[0] == '/') {
        *first = true;
        free(*current);
        *current = NULL;
    }
    return (strdup(buffer));
}
