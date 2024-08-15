/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display_entities
*/

#include <rpg/rpg.h>

void display_entity_on_tile(panel_t *pan, game_t *game, V2F tilepos, V2F pos)
{
    entity_t *ent = NULL;

    (void) pan;
    if (game == NULL || game->entities == NULL)
        return;
    pos = grid_absolute_pos(game->stage->map->grid, pos);
    for (unsigned int itr = 0; game->entities[itr]; ++itr) {
        ent = game->entities[itr];
        if (ent->pos.x != (int) tilepos.x || ent->pos.y != (int) tilepos.y)
            continue;
        set_obj_pos(ent->obj, pos);
        ent->obj->pos = pos;
        draw_object(game->engine, ent->obj);
    }
}

void display_entities(panel_t *pan UNUSED, game_t *game)
{
    map_t *m = game->stage->map;
    double x = 1;
    double y = 0;
    double ry_max = m->sroll.y + 33 > m->size.y ? m->size.y : m->sroll.y + 33;
    double rx_max = m->sroll.x + 60 > m->size.x ? m->size.x : m->sroll.x + 60;

    if (m == NULL)
        return;
    for (double ry = m->sroll.y; ry < ry_max; ry++) {
        for (double rx = m->sroll.x; rx < rx_max; rx++) {
            x -= x == 1 ? (rx - (float) (((int) rx) * 1.f)) : 0;
            y -= y == 1 ? (ry - (float) (((int) ry) * 1.f)) : 0;
            display_entity_on_tile(pan, game, (V2F) {rx, ry}, (V2F) {x, y});
            x += 1;
        }
        x = 1.f;
        y++;
    }
    update_entity_position(game->entities);
}