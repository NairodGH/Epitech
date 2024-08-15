/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

char *add_newline(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 2));

    if (!new_str)
        return NULL;
    strcat(strcpy(new_str, str), "\n");
    return (new_str);
}

char *get_one_word(char *str)
{
    char *word = NULL;
    size_t i = 0;
    size_t n = 0;
    size_t len = 0;
    size_t s = 0;

    if (!str)
        return NULL;
    for (; str[i] == ' '; i++);
    for (n = i; str[n] != '\0' && str[n] != ' ' && str[n] != '\n'; n++, len++);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (; str[i] != '\0' && str[i] != ' ' && str[i] != '\n'; i++, s++)
        word[s] = str[i];
    word[s] = '\0';
    return word;
}

char *go_next_chr(char *str, char chr)
{
    if (str[0] == chr)
        (char *)((size_t)(str)++);
    str = strchr(str, chr);
    return str;
}

char *get_cell(char *tab)
{
    char *content = NULL;
    size_t i = 0;
    size_t n = 0;
    size_t j = 0;

    if (!tab)
        return NULL;
    tab[0] == '[' ? (char *)((size_t)tab++) : tab;
    for (; tab[i] == ',' && tab[i] == '[' && tab[i] != '\0'; i++);
    for (j = i; tab[j] != ',' && tab[j] != ']' && tab[j] != '\0'; n++, j++);
    if (!(content = malloc(sizeof(char) * (n + 1)))) {
        fprintf(stderr, "%s[ERROR]%s can't malloc", R, W);
        return NULL;
    }
    for (j = i, n = 0; tab[j] != ',' && tab[j] != ']' && tab[j] != '\0'; j++) {
        content[n] = tab[j];
        n++;
    }
    content[n] = '\0';
    return content;
}
