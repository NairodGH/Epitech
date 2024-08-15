/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ON item click
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void on_item_click(ENGPANEL, obj_t *obj)
{
    itemstack_t *stack;

    if (!obj)
        return;
    if (!game || obj->child == NULL)
        return;
    stack = (itemstack_t *) obj->child;
    if (!stack || !stack->item || !stack->item->consumptions)
        return;
    if (remove_itemstack(game, stack, 1)) {
        consume_itemstack(game, stack);
        return;
    }
}
