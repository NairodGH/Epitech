/*
** EPITECH PROJECT, 2021
** set_sound_loop.c
** File description:
** Set sound loop
*/

#include <sounds.h>

void set_sound_loop(sound_t *sound, bool is_looped)
{
    if (sound == NULL)
        return;
    sound->is_looped = is_looped;
    update_sound(sound);
}