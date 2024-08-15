/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui buttons
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void on_close_playergui(ENGPANEL, button_t *button UNUSED)
{
    close_panel_by_id(engine, game, GAME_PLAYERGUI);
}

PRIVATE void init_playergui_btn_close(ENGPANEL)
{
    char *asset_quit = "assets/btns/quit_x40.png";
    sfIntRect bi = {0, 0, 40, 40};
    sfVector2f bp = (sfVector2f){430, 382};
    button_t *qbutton = create_button(asset_quit, bi, bp, 1);

    set_button_id(qbutton, OBJ_INVENTORY_CLOSE);
    set_button_events(qbutton, &on_close_playergui);
    register_button(panel, qbutton);
}

void init_playergui_buttons(ENGPANEL)
{
    init_playergui_btn_close(engine, game, panel);
}