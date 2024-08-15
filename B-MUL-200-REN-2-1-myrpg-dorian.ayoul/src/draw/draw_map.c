/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw
*/

#include <rpg/rpg.h>

PRIVATE void draw_map_tile(game_t *game, map_t *map, map_tile_t *tile, \
sfVector2f pos)
{
    if (tile == NULL || tile->sprite == NULL || tile->texture == NULL)
        return;
    sfSprite_setScale(tile->sprite, map->grid->scale);
    sfSprite_setPosition(tile->sprite, pos);
    sfRenderWindow_drawSprite(game->window->window, tile->sprite, NULL);
}

void draw_map_layers(game_t *gm, map_t *m, sfVector2i tpos, V2F pos)
{
    int ty = tpos.y;
    int tx = tpos.x;

    draw_map_tile(gm, m, &m->fondation[ty][tx], \
    grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->houses[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->objects[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->props1[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->props2[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->trees1[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->trees2[ty][tx], grid_absolute_pos(m->grid, pos));
    draw_map_tile(gm, m, &m->trees3[ty][tx], grid_absolute_pos(m->grid, pos));
}

void draw_map(game_t *game, map_t *m)
{
    double x = 1;
    double y = 0;
    double ry_max = m->sroll.y + 33 > m->size.y ? m->size.y : m->sroll.y + 33;
    double rx_max = m->sroll.x + 60 > m->size.x ? m->size.x : m->sroll.x + 60;

    if (m == NULL)
        return;
    for (double ry = m->sroll.y; ry < ry_max; ry++) {
        for (double rx = m->sroll.x; rx < rx_max; rx++) {
            int ty = ry;
            int tx = rx;
            x -= x == 1 ? (rx - (float) (tx * 1.f)) : 0;
            y -= y == 1 ? (ry - (float) (ty * 1.f)) : 0;
            draw_map_layers(game, m, (sfVector2i) {tx, ty}, (V2F) {x, y});
            x += 1;
        }
        x = 1.f;
        y++;
    }
}