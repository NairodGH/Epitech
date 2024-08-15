/*
** EPITECH PROJECT, 2021
** Get nearest NPC
** File description:
** get nearest npc
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

entity_t *get_nearest_npc(ENGPANEL)
{
    entity_t *ent;

    if (game == NULL || game->entities == NULL)
        return (NULL);
    for (unsigned int itr = 0; game->entities[itr]; ++itr) {
        ent = game->entities[itr];
        if (ent == NULL || ent->obj == NULL)
            continue;
        if (get_entity_distance(panel, game, ent->obj->pos) <= 4)
            return (ent);
        ent->state = WAITING_FOR_ACTION;
    }
    return (NULL);
}