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

sfVector2f get_item_position(unsigned int slot)
{
    unsigned int line = 0;
    sfVector2f pos = {311, 108};

    for (; slot >= 7; ++line)
        slot -= 7;
    pos.x += 53 * slot;
    pos.y += 52 * line;
    return (pos);
}

void render_inventory_item(game_t *game, itemstack_t *is, unsigned int slot)
{
    sfVector2f pos = get_item_position(slot);
    obj_t *obj;

    (void) slot;
    if (!is || !is->item || !is->item->obj_gui)
        return;
    obj = is->item->obj_gui;
    obj->pos = pos;
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setScale(obj->sprite, (sfVector2f) {1.4f, 1.4f});
    sfRenderWindow_drawSprite(get_window(game->engine), obj->sprite, NULL);
    set_obj_child(obj, is);
    draw_item_tooltip(game->engine, obj, pos, false);
}

void render_inventory_items(game_t *game, panel_t *panel)
{
    list_t *inventory = get_inventory(game);
    itemstack_t *itemstack;
    unsigned int current = get_current_page(panel);
    unsigned int off = (current - 1) * 42;
    unsigned int curr = 0;

    if (!inventory)
        return;
    list_foreach(inventory, node) {
        if (curr < off) {
            ++curr;
            continue;
        }
        if (curr > off + 41)
            break;
        itemstack = (itemstack_t *) node->value;
        render_inventory_item(game, itemstack, curr - off);
        ++curr;
    }
}