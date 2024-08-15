/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const double density[] = {
    0.5,
    0.3,
    0.15,
    0.1,
    0.1,
    0.08,
    0.05
};

static void game_init_map_content(map_t *map, inventory_t *map_content)
{
    for (size_t i = 0; i < RESSOURCES_NBR; i++)
        ((size_t *)map_content)[i] =
            (size_t)((double)(map->width * map->height) * density[i]);
}

static void game_map_add_ressource(list_t *trantorians, map_t *map,
    size_t ressource, size_t tile)
{
    if (game_is_trant_on_tile(trantorians, map, tile) == true)
        return;
    if (((size_t *)(map->map[tile]))[ressource] < UNIT_MAX)
        ((size_t *)(map->map[tile]))[ressource]++;
}

static void game_dispatch(list_t *trantorians, map_t *map, pos_t **map_content,
    inventory_t *nb_ressources)
{
    size_t total = 0;
    int random_idx = 0;
    size_t cells_rem = 0;

    for (size_t ressource = 0; ressource < RESSOURCES_NBR; ressource++) {
        total = ((size_t *)(nb_ressources))[ressource];
        cells_rem = game_fill_map_dup_remaining(map, map_content, ressource);
        for (size_t to_dispatch = 0; to_dispatch < total; to_dispatch++) {
            cells_rem == 0 ?
                cells_rem = game_fill_map_dup(map, map_content) : 0;
            random_idx = rand() % cells_rem;
            game_map_add_ressource(trantorians, map, ressource, GET_COORD(map,
                map_content[random_idx]->x, map_content[random_idx]->y));
            game_map_dup_delete_idx(map_content, random_idx, cells_rem);
            cells_rem--;
        }
        cells_rem = map->width * map->height;
    }
}

void game_dispatch_ressources(list_t *trantorians, map_t *map)
{
    pos_t **map_content = game_init_map_dup(map);
    inventory_t nb_ressources = {0};

    if (map_content == NULL) {
        fprintf(stderr, "[ERROR] Failed to allocate map content\n");
        return;
    }
    game_init_map_content(map, &nb_ressources);
    game_dispatch(trantorians, map, map_content, &nb_ressources);
    game_destroy_map_dup(map, map_content);
}

void game_update_map(list_t *trantorians, map_t *map)
{
    static size_t refresh = 1;

    refresh--;
    if (refresh > 0)
        return;
    refresh = MAP_REFRESH;
    game_dispatch_ressources(trantorians, map);
}
