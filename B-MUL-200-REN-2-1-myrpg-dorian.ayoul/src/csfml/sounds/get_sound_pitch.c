/*
** EPITECH PROJECT, 2021
** get_sound_pitch.c
** File description:
** Get sound pitch
*/

#include <sounds.h>

float get_sound_pitch(sound_t *sound)
{
    return (sound->pitch);
}