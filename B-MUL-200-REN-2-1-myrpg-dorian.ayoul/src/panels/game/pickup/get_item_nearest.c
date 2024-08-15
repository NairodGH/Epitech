/*
** EPITECH PROJECT, 2021
** get_item_from_tile
** File description:
** get_item_from_tile
*/

#include <rpg/rpg.h>
#include <rpg/map.h>

PRIVATE bool is_itnear(obj_t *pl, map_t *m, sfVector2f tilepos)
{
    sfVector2f tile_rpos;
    sfVector2f rel_pos;

    if (!pl || !m)
        return (NULL);
    rel_pos.x = tilepos.x - m->sroll.x;
    rel_pos.y = tilepos.y - m->sroll.y;
    tile_rpos = grid_absolute_pos(m->grid, rel_pos);
    m->active_item_pos = tile_rpos;
    m->active_tile_pos = tilepos;
    return (true);
}

PRIVATE map_tile_t *itnear_x(obj_t *pl, sfVector2i rpos, map_t *m, int ry)
{
    map_tile_t *tmp = NULL;
    sfVector2f pp;

    for (int rx = rpos.x - 3; rx < rpos.x + 3; ++rx) {
        tmp = &m->objects[ry][rx];
        pp = (sfVector2f) {rx, ry};
        if (tmp != NULL && tmp->tile_id != 0 && is_itnear(pl, m, pp))
            return (tmp);
    }
    return (NULL);
}

map_tile_t *get_item_nearest(panel_t *panel, map_t *m UNUSED)
{
    obj_t *player = get_player(panel);
    sfVector2i relpos = get_player_tile_pos(m, player);
    map_tile_t *tmp = NULL;

    if (player == NULL)
        return (NULL);
    for (int ry = relpos.y - 2; ry < relpos.y + 2; ++ry) {
        tmp = itnear_x(player, relpos, m, ry);
        if (tmp != NULL)
            return (tmp);
    }
    return (NULL);
}