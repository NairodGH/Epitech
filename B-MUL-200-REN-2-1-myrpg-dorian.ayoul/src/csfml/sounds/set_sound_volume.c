/*
** EPITECH PROJECT, 2021
** set_sound_volume.c
** File description:
** Set sound volume
*/

#include <sounds.h>

void set_sound_volume(sound_t *sound, float volume)
{
    if (sound == NULL)
        return;
    sound->volume = volume;
    update_sound(sound);
}