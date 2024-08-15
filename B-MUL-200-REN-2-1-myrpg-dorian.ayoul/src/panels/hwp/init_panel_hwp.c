/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init how to play panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_hwp_menu(engine_t *eng, game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    obj_t *b = create_object("assets/mhwp/bg.png", rct, (sfVector2f){0, 0});

    register_object(panel, b);
    init_buttons_hwp_back(panel);
    set_panel_visibility(panel, true);
    init_texts_hwp(eng, game, panel);
}

void init_panel_hwp(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(HOW_TO_PLAY);
    set_panel_initializer(panel, &init_hwp_menu, NULL);

    (void) game;
    register_panel(eng, panel);
}