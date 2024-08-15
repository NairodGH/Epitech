/*
** EPITECH PROJECT, 2021
** set_sound_path.c
** File description:
** Set sound path
*/

#include <sounds.h>

void set_sound_path(sound_t *sound, char *path)
{
    if (sound == NULL || path == NULL)
        return;
    sound->path = path;
    update_sound(sound);
}