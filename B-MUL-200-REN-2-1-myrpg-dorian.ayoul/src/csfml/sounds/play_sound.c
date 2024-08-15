/*
** EPITECH PROJECT, 2021
** play_sound.c
** File description:
** Plays a sound
*/

#include <sounds.h>
#include <stdio.h>

void play_sound(sound_t *sound)
{
    if (sound == NULL)
        return;
    sound->status = sfPlaying;
    update_sound(sound);
}