/*
** EPITECH PROJECT, 2021
** pause_sound.c
** File description:
** Pauses a sound
*/

#include <sounds.h>
#include <stdio.h>

void pause_sound(sound_t *sound)
{
    if (sound == NULL)
        return;
    sound->status = sfPaused;
    update_sound(sound);
}