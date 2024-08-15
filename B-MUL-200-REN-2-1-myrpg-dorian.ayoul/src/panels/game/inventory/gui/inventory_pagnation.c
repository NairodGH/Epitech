/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Get inventory page count
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

unsigned int get_current_page(panel_t *panel)
{
    obj_t *obj;

    if (panel == NULL)
        return (1);
    obj = get_obj_by_id(panel, OBJ_INVENTORY_BACKGROUND);
    if (obj == NULL)
        return (1);
    if (obj->state < 1)
        obj->state = 1;
    return (obj->state);
}

unsigned int get_inventory_pagecount(game_t *game)
{
    unsigned int items = get_inventory_count(game);
    unsigned int pages = 0;

    while (items >= 42) {
        items -= 42;
        ++pages;
    }
    if (items > 0)
        ++pages;
    if (pages == 0)
        return (1);
    return (pages == 0 ? 1 : pages);
}

bool navigate_inventory(panel_t *panel, int relative_page)
{
    obj_t *obj;

    if (panel == NULL)
        return (false);
    obj = get_obj_by_id(panel, OBJ_INVENTORY_BACKGROUND);
    if (obj == NULL)
        return (false);
    obj->state += relative_page;
    if (obj->state < 1)
        obj->state = 1;
    return (true);
}