/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stage_init
*/

#include <rpg/rpg.h>
#include <nep/nmem.h>

PRIVATE void load_map(game_t *game, char const *map_path)
{
    tiled_map_t *tiled_map = tiled_parse(map_path);

    if (tiled_map == NULL)
        return;
    map_fill(game->stage->map, tiled_map, game->tilesets);
    tiled_free(tiled_map);
}

void stage_init(game_t *game)
{
    if (game->stage != NULL)
        stage_free(game);
    game->stage = ncalloc(1, sizeof(stage_t));
    game->stage->map = map_create(500, 500);
    load_map(game, "assets/map1.tmx");
}