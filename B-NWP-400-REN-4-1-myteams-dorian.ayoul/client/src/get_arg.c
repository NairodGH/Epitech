/*
** EPITECH PROJECT, 2022
** get_arg.c
** File description:
** get_arg
*/

#include "client.h"

bool recup_arg_split(char *message, size_t *i, char *arg, size_t s)
{
    arg[0] = '[';
    while (message[*i] != '\n' && message[*i] != '\0') {
        while (message[*i] == ' ' || message[*i] == '"')
            (*i)++;
        if (message[*i] == '\n')
            break;
        if (!get_one_word(message, arg, i, &s))
            return false;
    }
    arg[s - 1] = '\0';
    return true;
}

char *recup_arg(char *message, size_t *i)
{
    char *arg = malloc(sizeof(char) * (strlen(message) * 2));
    size_t s = 1;

    if (arg == NULL)
        return NULL;
    if (message[*i] == '\n') {
        strcpy(arg, "[]");
        return arg;
    }
    while (message[*i] == ' ')
        (*i)++;
    if (message[*i] != '"') {
        free(arg);
        return NULL;
    }
    if (!recup_arg_split(message, i, arg, s)) {
        free(arg);
        return NULL;
    }
    return arg;
}

static char *get_one_arg(char *str, size_t i)
{
    char *temp = NULL;
    size_t len = 0;

    while (str[i] != ']' && str[i] != '\0') {
        i++;
        len++;
    }
    temp = malloc(sizeof(char) * (len + 1));
    i = i - len;
    len = 0;
    while (str[i] != ']' && str[i] != '\0') {
        temp[len] = str[i];
        len++;
        i++;
    }
    temp[len] = '\0';
    return temp;
}

static void split_create_arg(char **arg, char *str, size_t *i, size_t *n)
{
    if (str[*i] == '[') {
        arg[(*n)++] = get_one_arg(str, (*i + 1));
        for (; str[*i] != '\0' && str[*i] != ']'; (*i)++);
    }
}

char **create_arg(char *str)
{
    size_t count = 0;
    size_t n = 0;
    char **arg;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '[')
            count++;
    if (!(arg = calloc(count + 1, sizeof(char *))))
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        split_create_arg(arg, str, &i, &n);
    if (n == 0) {
        free(arg);
        return NULL;
    }
    arg[n] = NULL;
    return arg;
}
