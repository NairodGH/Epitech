/*
** EPITECH PROJECT, 2021
** get_sound_path.c
** File description:
** Get sound path
*/

#include <sounds.h>

char *get_sound_path(sound_t *sound)
{
    if (sound == NULL || sound->path == NULL)
        return (NULL);
    return (sound->path);
}