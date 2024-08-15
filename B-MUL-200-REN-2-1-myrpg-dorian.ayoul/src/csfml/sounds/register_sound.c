/*
** EPITECH PROJECT, 2021
** register_sonud.c
** File description:
** Register a sound
*/

#include <panel.h>
#include <sounds.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void register_sound(engine_t *eng, sound_t *sound)
{
    if (eng == NULL || sound == NULL)
        return;
    if (eng->sounds == NULL)
        eng->sounds = list_create();
    list_add(eng->sounds, sound);
}