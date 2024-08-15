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
#include <rpg/inventory.h>

char *get_amount(engine_t *eng, int amount)
{
    if (amount > 98)
        return ("");
    if (!eng->game->statics->basic_num)
        return ("");
    return (eng->game->statics->basic_num[amount]);
}

void draw_item_amount(engine_t *eng, panel_t *pan, itemstack_t *stack, int i)
{
    txt_t **texts;
    txt_t *txt;
    char *amount;

    if (!eng || !pan || !stack)
        return;
    if (!eng->game || !eng->game->statics)
        return;
    texts = eng->game->statics->hud_inv_amount;
    if (!texts || !texts[i])
        return;
    txt = texts[i];
    amount = get_amount(eng, stack->count);
    sfText_setString(txt->text, amount);
    sfRenderWindow_drawText(get_window(eng), txt->text, NULL);
}

void draw_item(engine_t *engine, panel_t *panel, itemstack_t *stack, V2F pos)
{
    obj_t *obj;

    (void) panel;
    if (!stack)
        return;
    if (!stack->item || !stack->item->obj)
        return;
    obj = stack->item->obj;
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setScale(obj->sprite, (sfVector2f) {1.4f, 1.4f});
    sfRenderWindow_drawSprite(get_window(engine), obj->sprite, NULL);
    set_obj_child(obj, stack);
    draw_item_tooltip(engine, obj, pos, true);
}

void draw_items(game_t *game, panel_t *panel)
{
    list_t *inv = NULL;
    itemstack_t *stack = NULL;
    int slot_id = 0;
    sfVector2f pos = {294, 507};

    if (!game || !panel || !get_inventory(game))
        return;
    inv = game->player->inventory;
    list_foreach(inv, node) {
        stack = (itemstack_t *) node->value;
        if (slot_id > 9)
            break;
        draw_item(game->engine, panel, stack, pos);
        draw_item_amount(game->engine, panel, stack, slot_id);
        pos.x += 40;
        ++slot_id;
    }
}