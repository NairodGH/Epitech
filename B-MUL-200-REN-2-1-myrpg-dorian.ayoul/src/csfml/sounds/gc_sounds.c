/*
** EPITECH PROJECT, 2021
** gc_sounds.c
** File description:
** Clear unused sound
*/

#include <panel.h>
#include <sounds.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void gc_sound(list_t *list, list_node_t *nd, sound_t *sound, bool force)
{
    bool ended = force;

    if (sound == NULL)
        return;
    if (sound->sound != NULL && sfSound_getStatus(sound->sound) == sfStopped)
        ended = true;
    if (!ended || !sound->sound)
        return;
    sfSound_stop(sound->sound);
    list_remove(list, nd);
    delete_sound(sound);
}

void gc_sounds(engine_t *engine, bool force)
{
    sound_t *sound;

    if (engine->sounds == NULL)
        return;
    list_foreach(engine->sounds, sound_node) {
        sound = (sound_t *) sound_node->value;
        gc_sound(engine->sounds, sound_node, sound, force);
    }
}