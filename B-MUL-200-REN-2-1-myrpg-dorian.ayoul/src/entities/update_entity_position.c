/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update entity position
*/

#include <rpg/rpg.h>

PRIVATE void change_entpos(entity_t *entity, entity_fight_t *fight, int idx)
{
    unsigned int count = 0;
    pos_t *pos;

    for (; fight->pathing[count]; ++count);
    if ((unsigned int) idx > count - 1) {
        fight->path_index = 0;
    }
    pos = fight->pathing[fight->path_index];
    entity->pos = (sfVector2f) {pos->x, pos->y};
}

PRIVATE void update_entpos(entity_t *entity)
{
    entity_fight_t *fight = entity->fight;
    sfClock *c;

    if (!fight || !fight->pathing)
        return;
    c = fight->path_clock;
    if (sfClock_getElapsedTime(c).microseconds / 1000 < fight->pathing_sleep)
        return;
    ++fight->path_index;
    change_entpos(entity, fight, fight->path_index);
    sfClock_restart(c);
}

void update_entity_position(entity_t **entities)
{
    if (!entities)
        return;
    for (unsigned int itr = 0; entities[itr]; ++itr)
        update_entpos(entities[itr]);
}
