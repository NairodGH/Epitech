/*
** EPITECH PROJECT, 2021
** get_sound_volume.c
** File description:
** Get sound volume
*/

#include <sounds.h>

float get_sound_volume(sound_t *sound)
{
    return (sound->volume);
}