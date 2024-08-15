/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save list panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

unsigned int get_current_save_count(game_t *game)
{
    unsigned int count = 0;

    if (!game || !game->saves)
        return (count);
    for (; game->saves[count]; ++count);
    return (count);
}

void render_savelist(ENGPANEL)
{
    button_t *button = NULL;

    if (!panel || !game)
        return;
    button = get_button_by_id(panel, BTN_SAVE_LISTCREATE);
    if (!button)
        return;
    if (get_current_save_count(game) < 9) {
        set_button_color(button, sfTransparent);
        return;
    }
    set_button_color(button, (sfColor) {120, 120, 120, 255});
}