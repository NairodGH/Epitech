/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** clear save name
*/

#include <rpg/rpg.h>
#include <envdata.h>
#include <dirent.h>
#include <errno.h>

char *get_pretty_save_name(char *file)
{
    int len;

    if (!str_endswith(file, ".xml"))
        return (file);
    len = nstrlen(file) - 4;
    for (unsigned int itr = len; file[itr]; ++itr)
        file[itr] = '\0';
    return (file);
}