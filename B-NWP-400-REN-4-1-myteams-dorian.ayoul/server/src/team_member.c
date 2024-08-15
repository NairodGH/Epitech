/*
** EPITECH PROJECT, 2022
** server.c
** File description:
** server
*/

#include "server.h"

char *generate_id(void)
{
    uuid_t binuuid;
    char *id = malloc(UUID_STR_LEN);

    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, id);
    return id;
}

static char **fill_member(char **member, char *buff, size_t *i)
{
    size_t s = 0;
    char temp[4096];
    size_t n = 0;

    for (s = 0; buff[*i] != ']' && buff[*i] != '\0'; s++) {
        for (; buff[*i] != '{' && buff[*i] != '\0'; (*i)++);
        if (buff[*i] == '\0')
            return NULL;
        (*i)++;
        for (n = 0; buff[*i] != '}' && buff[*i] != '\0'; n++, (*i)++)
            temp[n] = buff[*i];
        temp[n] = '\0';
        if (buff[*i] != '\0')
            (*i)++;
        member[s] = strdup(temp);
        memset(temp, 0, 4096);
    }
    member[s] = NULL;
    return member;
}

char **get_list_member(char *buff, size_t *i)
{
    char **member = NULL;
    size_t len = 0;

    for (size_t s = *i; buff[s] != ']' && buff[s] != '\n' && buff[s] != 0; s++)
        if (buff[s] == '{')
            len++;
    if (len == 0)
        return NULL;
    member = malloc(sizeof(char *) * (len + 1));
    if (!member)
        return NULL;
    return (fill_member(member, buff, i));
}
