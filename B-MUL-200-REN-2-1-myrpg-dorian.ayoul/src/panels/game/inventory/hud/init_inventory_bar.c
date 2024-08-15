/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init game panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void update_inventory_bar(engine_t *eng, game_t *game, panel_t *pan)
{
    obj_t *inv = get_obj_by_id(pan, OBJ_INVENTORY_BAR);
    obj_t *minipanel = get_obj_by_id(pan, OBJ_MINIPANEL);
    panel_t *quest = get_panel_by_id(eng, GAME_QUESTS);
    panel_t *ach = get_panel_by_id(eng, GAME_ACHIEVEMENTS);

    bool bar = minipanel == NULL || !minipanel->visibility;
    bar = bar && (quest == NULL || !quest->visibility);
    bar = bar && (ach == NULL || !ach->visibility);
    if (inv == NULL)
        return;
    set_obj_visibility(inv, bar);
    if (bar)
        draw_items(game, pan);
}

void init_inventory_bar(panel_t *pan)
{
    sfIntRect rct = {0, 0, 418, 48};
    sfVector2f pos = {275, 492};
    obj_t *b = create_object("assets/game/inventory_bar.png", rct, pos);

    set_obj_type(b, OBJ_INVENTORY_BAR);
    set_obj_visibility(b, true);
    register_object(pan, b);
}