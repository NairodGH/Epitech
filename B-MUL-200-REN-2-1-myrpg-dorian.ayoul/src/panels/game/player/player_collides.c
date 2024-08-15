/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Player collides
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE bool rectangle_overlap(V2F l1, V2F r1, V2F l2, V2F r2)
{
    if (l1.x < r2.x && r1.x > l2.x && l1.y < r2.y && r1.y > l2.y)
        return true;
    return false;
}

PRIVATE bool layer_collides(obj_t *player, map_tile_t col, sfVector2f tilepos)
{
    sfVector2f p_from;
    sfVector2f p_to;
    sfVector2f tile_to;
    sfIntRect rct;

    if (col.tile_id != 1)
        return false;
    p_from = player->pos;
    rct = player->rect;
    p_to = (sfVector2f) {p_from.x + rct.width, p_from.y + rct.height};
    tile_to = (sfVector2f) {tilepos.x + 16, tilepos.y + 16};
    return (rectangle_overlap(p_from, p_to, tilepos, tile_to));
}

PRIVATE bool check_collides(obj_t *player, map_t *m, float sx, float sy)
{
    double x = 1;
    double y = 0;
    double ry_max = sy + 33 > m->size.y ? m->size.y : sy + 33;
    double rx_max = sx + 60 > m->size.x ? m->size.x : sx + 60;
    bool collides = false;

    for (double ry = sy; ry < ry_max && !collides; ry++) {
        for (double rx = sx; rx < rx_max && !collides; rx++) {
            int tx = rx;
            int ty = ry;
            x -= x == 1 ? (rx - (float) (tx * 1.f)) : 0;
            y -= y == 1 ? (ry - (float) (ty * 1.f)) : 0;
            collides = collides || layer_collides(player, m->info[ty][tx],
            grid_absolute_pos(m->grid, (sfVector2f) {x, y}));
            x += 1;
        }
        x = 1.f;
        y++;
    }
    return collides;
}

bool player_collides(panel_t *panel, map_t *m, float sx, float sy)
{
    obj_t *player = get_player(panel);

    if (player == NULL)
        return false;
    return (check_collides(player, m, sx, sy));
}