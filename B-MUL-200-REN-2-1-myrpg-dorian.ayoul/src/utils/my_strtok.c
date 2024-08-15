/*
** EPITECH PROJECT, 2021
** my_strtok.c
** File description:
** strtok but like.. mine
*/

#include <stdlib.h>

static size_t count_tokens(char *str, char c)
{
    size_t count = 0;
    size_t itr;

    if (str == NULL)
        return (0);
    for (itr = 0; str[itr]; ++itr)
        if (c == str[itr])
            ++count;
    return (count + 1);
}

static char *select_token(char *str, size_t ptr, size_t end)
{
    size_t relative = 0;
    char *token;

    if (ptr > end || ptr == end)
        return (NULL);
    token = malloc(sizeof(char) * (end - ptr + 2));
    if (!token)
        return (NULL);
    for (size_t itr = ptr; itr < end; ++itr) {
        token[relative] = str[itr];
        ++relative;
    }
    token[relative] = '\0';
    return (token);
}

char **my_strtok(char *str, char c)
{
    size_t id = 0;
    size_t ptr = 0;
    size_t itr;
    size_t count = count_tokens(str, c);
    char **tokens = NULL;
    if (count == 0 || !str)
        return (NULL);
    tokens = malloc(sizeof(char *) * (count + 1));
    if (!tokens)
        return (NULL);
    for (itr = 0; str[itr]; ++itr) {
        if (str[itr] != c)
            continue;
        tokens[id++] = select_token(str, ptr, itr);
        ptr = itr + 1;
    }
    if (itr > ptr)
        tokens[id++] = select_token(str, ptr, itr);
    tokens[id] = NULL;
    return (tokens);
}