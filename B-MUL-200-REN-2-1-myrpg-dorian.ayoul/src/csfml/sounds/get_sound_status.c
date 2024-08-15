/*
** EPITECH PROJECT, 2021
** get_sound_status.c
** File description:
** Get sound status
*/

#include <engine.h>
#include <sounds.h>

sfsoundstatus_t get_sound_status(sound_t *sound)
{
    return (sound->status);
}