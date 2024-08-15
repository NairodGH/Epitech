/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init pause panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_pause_background(panel_t *panel)
{
    char *bg = "assets/pause/bg.png";
    sfIntRect rct = {0, 0, 302, 410};
    obj_t *b = create_object(bg, rct, (sfVector2f){305, 80});

    register_object(panel, b);
}

void init_pause_menu(engine_t *eng UNUSED, game_t *game UNUSED, panel_t *panel)
{
    init_pause_background(panel);
    init_buttons_pause_resume(panel);
    init_buttons_pause_options(panel);
    init_buttons_pause_start(panel);
    init_buttons_pause_quit(panel);
    set_panel_visibility(panel, true);
}

void init_panel_pause(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(PAUSE);
    set_panel_initializer(panel, &init_pause_menu, NULL);

    (void) game;
    register_panel(eng, panel);
}