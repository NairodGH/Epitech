/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils gui
*/

#include "zappy_gui.h"

char *create_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(UUID_STR_LEN);

    if (!uuid)
        return NULL;
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}

char *go_next_space(char *str)
{
    while (str[0] == ' ') {
        (char *)((size_t)(str)++);
    }
    str = strchr(str, ' ');
    return str;
}

char *go_next_command(char *save, char *research)
{
    size_t i = 0;

    if (strncmp(&save[i], research, strlen(research)) == 0)
        i++;
    while (save[i] != '\0'
        && strncmp(&save[i], research, strlen(research)) != 0)
        i++;
    if (save[i] == '\0')
        return NULL;
    return &save[i];
}

char *move_str(char *str)
{
    size_t i = 0;

    while (str[i] == ' ')
        i++;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
        i++;
    return &str[i];
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
