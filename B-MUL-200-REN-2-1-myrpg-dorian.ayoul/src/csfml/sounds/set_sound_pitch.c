/*
** EPITECH PROJECT, 2021
** set_sound_pitch.c
** File description:
** Set sound pitch
*/

#include <sounds.h>

void set_sound_pitch(sound_t *sound, float pitch)
{
    if (sound == NULL)
        return;
    sound->pitch = pitch;
    update_sound(sound);
}