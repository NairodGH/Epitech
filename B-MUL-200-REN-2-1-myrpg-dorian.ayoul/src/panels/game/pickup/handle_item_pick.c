/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle item pick
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_pickup(panel_t *panel)
{
    tooltip_t *tool = create_tooltip("Press E to pickup");

    if (tool == NULL)
        return;
    set_tooltip_id(tool, 1);
    register_tooltip(panel, tool);
}

void pickup_item(panel_t *panel, game_t *game)
{
    map_t *map = game->stage->map;
    map_tile_t *near = get_item_nearest(panel, map);
    item_t *item = NULL;

    if (map == NULL || near == NULL)
        return;
    item = get_item_from_tile_id(game, near->tile_id);
    if (item == NULL) {
        nprintf("Unknown pickup item: %d\n", near->tile_id);
        return;
    }
    add_inventory_item(game, item, 1);
    add_pick_item(game, near, map->active_tile_pos);
    play_seffect(game, game->engine, "assets/sounds/pickup-item.ogg");
}

void handle_item_pick(panel_t *panel, game_t *game)
{
    map_t *map = game->stage->map;
    map_tile_t *near = get_item_nearest(panel, map);
    tooltip_t *tool = get_tooltip_by_id(panel, 1);

    if (near == NULL)
        return;
    display_tooltip(game->engine, map->active_item_pos, tool);
}