/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Inventory render
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void update_inv_arrow_right(panel_t *panel, bool has_next_page)
{
    button_t *btn;

    if (!panel)
        return;
    btn = get_button_by_id(panel, OBJ_INVENTORY_ARROWRIGHT);
    if (!btn)
        return;
    if (has_next_page) {
        set_button_color(btn, sfTransparent);
        return;
    }
    set_button_color(btn, (sfColor) {120, 120, 120, 255});
}

PRIVATE void update_inv_arrow_left(panel_t *panel, bool has_back_page)
{
    button_t *btn;

    if (!panel)
        return;
    btn = get_button_by_id(panel, OBJ_INVENTORY_ARROWLEFT);
    if (!btn)
        return;
    if (has_back_page) {
        set_button_color(btn, sfTransparent);
        return;
    }
    set_button_color(btn, (sfColor) {120, 120, 120, 255});
}

void tick_inventory_gui(ENGPANEL)
{
    render_inventory_items(game, panel);
}

void render_inventory_gui(ENGPANEL)
{
    unsigned int pages = get_inventory_pagecount(game);
    unsigned int current = get_current_page(panel);

    update_inv_arrow_right(panel, current < pages);
    update_inv_arrow_left(panel, current > 1);
    render_inventory_items(game, panel);
}