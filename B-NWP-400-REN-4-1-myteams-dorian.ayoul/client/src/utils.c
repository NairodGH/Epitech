/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "client.h"

char *get_user_word(char *str, size_t *i)
{
    char *word = NULL;
    size_t z = (*i);
    size_t n = 0;

    for (;str[z] != '\0' && str[z] != '|'; z++);
    word = malloc(sizeof(char) * (z + 1));
    while (str[*i] != '\0' && str[*i] != '|') {
        if (str[*i] == '\0')
            return word;
        word[n] = str[*i];
        (*i)++;
        n++;
    }
    if (str[*i] != '\0')
        (*i)++;
    word[n] = '\0';
    return word;
}

void free_char(char *buffer, char *message, char *temp, char **arg)
{
    size_t i = 0;

    free(buffer);
    free(message);
    free(temp);
    if (arg != NULL) {
        while (arg[i] != NULL) {
            free(arg[i]);
            i++;
        }
        free(arg);
    }
}

void print_arg(char **arg)
{
    if (!arg) {
        printf("No arg\n");
        return;
    }
    printf("nb arg : %d\n", get_len_arg(arg));
    for (size_t i = 0; arg[i] != NULL; i++) {
        printf("%s\n", arg[i]);
    }
}

int get_len_arg(char **arg)
{
    size_t i = 0;

    if (arg == NULL)
        return 0;
    while (arg[i] != NULL)
        i++;
    return i;
}

bool is_in_list(char *str, const char **list)
{
    for (size_t i = 0; list[i] != NULL; i++)
        if (strlen(str) >= strlen(list[i])
            && strncmp(str, list[i], strlen(list[i])) == 0)
            return true;
    return false;
}
