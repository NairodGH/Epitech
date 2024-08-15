/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init achievements panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE void quit_achievement_panel(ENGPANEL, button_t *btn)
{
    (void) btn;
    close_panel_by_id(engine, game, GAME_ACHIEVEMENTS);
}

PRIVATE void register_achievement_background(ENGPANEL)
{
    sfIntRect rct = {0, 0, 960, 540};
    sfVector2f pos = (sfVector2f){200, 75};
    sfIntRect bi = {0, 0, 120, 62};
    sfVector2f bp = (sfVector2f){410, 440};
    obj_t *b = create_object("assets/machievements/bg.png", rct, pos);
    button_t *button = create_button("assets/btns/close.png", bi, bp, 1);

    set_button_events(button, &quit_achievement_panel);
    register_button(panel, button);
    register_object(panel, b);
}

void start_achievement_panel(ENGPANEL)
{
    register_achievement_background(engine, game, panel);
    register_achievement_cards(engine, game, panel);
}

void init_panel_achievement(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME_ACHIEVEMENTS);
    set_panel_initializer(panel, &start_achievement_panel, NULL);

    register_panel(eng, panel);
}