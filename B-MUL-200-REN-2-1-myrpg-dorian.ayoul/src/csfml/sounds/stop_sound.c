/*
** EPITECH PROJECT, 2021
** stop_sound.c
** File description:
** Stops a sound
*/

#include <sounds.h>
#include <stdio.h>

void stop_sound(sound_t *sound)
{
    if (sound == NULL)
        return;
    sound->status = sfStopped;
    update_sound(sound);
}