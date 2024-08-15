/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

char *go_next_char(char *str, char chr)
{
    while (str[0] == chr) {
        (char *)((size_t)(str)++);
    }
    str = strchr(str, chr);
    if (str && str[0] != '\0')
        (char *)((size_t)(str)++);
    return str;
}

char *get_one_command(char *save)
{
    char *comm = NULL;
    size_t len = 0;

    for (len = 0; save[len] != '\0' && save[len] != '\n'; len++);
    comm = malloc(sizeof(char) * (len + 1));
    if (!comm)
        return NULL;
    for (len = 0; save[len] != '\0' && save[len] != '\n'; len++) {
        comm[len] = save[len];
    }
    comm[len] = '\0';
    if (save[len] == '\0')
        return comm;
    return comm;
}
