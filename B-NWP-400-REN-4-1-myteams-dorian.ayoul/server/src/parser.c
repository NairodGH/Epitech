/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** parser
*/

#include "server.h"

static char *find_word(char *buffer, size_t *i)
{
    size_t save = *i;
    size_t t = 0;
    char *word = NULL;

    while (buffer[(*i)] != '\0' && buffer[(*i)] != ']')
        (*i)++;
    word = malloc(sizeof(char) * ((*i) - save + 1));
    if (!word)
        return NULL;
    while (save != *i) {
        word[t] = buffer[save];
        save++;
        t++;
    }
    word[t] = '\0';
    return word;
}

char **find_arg(char *buffer)
{
    char **arg = NULL;
    size_t size = 1;

    if (strcmp(buffer, "[]") == 0)
        return NULL;
    for (size_t i = 0; buffer[i] != ']' && buffer[i] != '\0'; i++) {
        while (buffer[i] == ' ' || buffer[i] == '[')
            i++;
        if (buffer[i] == '\0')
            return NULL;
        arg = realloc(arg, sizeof(char *) * (size + 1));
        arg[size - 1] = find_word(buffer, &i);
        size++;
    }
    if (arg != NULL)
        arg[size - 1] = NULL;
    return arg;
}

char *get_command(char *str)
{
    size_t s = 1;
    size_t i = 0;
    size_t t = 0;
    char *new_str = NULL;

    while (str[i] != '\0' && str[i] != '>')
        i++;
    new_str = malloc(sizeof(char) * (i));
    while (s != i) {
        new_str[t] = str[s];
        s++;
        t++;
    }
    new_str[t] = '\0';
    return new_str;
}

void manage_client(int fd, lcli_t *list, char *buffer, server_t *serv)
{
    char *clean_str = NULL;
    char **arg = NULL;

    if (strcmp(buffer, "300: <disconnected>") == 0) {
        destroy_client(list, fd);
        FD_CLR(fd, &serv->temp);
        FD_CLR(fd, &serv->writefds);
        return;
    }
    if (buffer[0] != '<') {
        printf("Message From TCP client: %s\n", buffer);
        return;
    }
    clean_str = get_command(buffer);
    arg = find_arg(buffer + strlen(clean_str) + 2);
    for (int i = 0; com[i].cmd != NULL; i++)
        if (strcmp(com[i].cmd, clean_str) == 0)
            com[i].func_ptr(get_client(list, fd), arg);
    free_command(arg, clean_str);
}

void free_command(char **arg, char *clean_str)
{
    free(clean_str);
    if (arg != NULL) {
        for (size_t i = 0; arg[i] != NULL; i++)
            free(arg[i]);
        free(arg);
    }
}
