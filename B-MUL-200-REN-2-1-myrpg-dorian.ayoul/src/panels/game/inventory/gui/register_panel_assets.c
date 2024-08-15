/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init inventory panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void register_inventory_arrows(ENGPANEL)
{
    char *asset_left = "assets/btns/arrow_left.png";
    char *asset_right = "assets/btns/arrow_right.png";
    sfIntRect bi = {0, 0, 32, 41};
    sfVector2f bp = (sfVector2f){620, 416};
    button_t *right = create_button(asset_right, bi, bp, 1);
    button_t *left;
    bi = (sfIntRect) {0, 0, 32, 41};
    bp = (sfVector2f){305, 416};
    left = create_button(asset_left, bi, bp, 1);

    set_button_id(left, OBJ_INVENTORY_ARROWLEFT);
    set_button_id(right, OBJ_INVENTORY_ARROWRIGHT);
    set_button_events(left, &on_left_inventory);
    set_button_events(right, &on_right_inventory);
    register_button(panel, left);
    register_button(panel, right);
}

PRIVATE void register_inventory_closebtn(ENGPANEL)
{
    char *asset_quit = "assets/btns/quit_x40.png";
    sfIntRect bi = {0, 0, 40, 40};
    sfVector2f bp = (sfVector2f){455, 416};
    button_t *qbutton = create_button(asset_quit, bi, bp, 1);

    set_button_id(qbutton, OBJ_INVENTORY_CLOSE);
    set_button_events(qbutton, &on_close_inventory);
    register_button(panel, qbutton);
}

PRIVATE void register_inventory_background(ENGPANEL)
{
    char *bgasset = "assets/minventory/bg.png";
    sfIntRect rct = {0, 0, 400, 449};
    sfVector2f pos = (sfVector2f){275, 20};
    obj_t *b = create_object(bgasset, rct, pos);

    set_obj_type(b, OBJ_INVENTORY_BACKGROUND);
    register_object(panel, b);
}

void start_inventory_panel(ENGPANEL)
{
    register_inventory_background(engine, game, panel);
    register_inventory_arrows(engine, game, panel);
    register_inventory_closebtn(engine, game, panel);
}