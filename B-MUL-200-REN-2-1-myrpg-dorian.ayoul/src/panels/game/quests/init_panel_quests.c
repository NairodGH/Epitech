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

PRIVATE void quit_quest_panel(ENGPANEL, button_t *btn)
{
    (void) btn;
    close_panel_by_id(engine, game, GAME_QUESTS);
}

PRIVATE void register_quest_background(ENGPANEL)
{
    sfIntRect rct = {0, 0, 960, 540};
    sfVector2f pos = (sfVector2f){200, 75};
    sfIntRect bi = {0, 0, 120, 62};
    sfVector2f bp = (sfVector2f){410, 440};
    obj_t *b = create_object("assets/mquests/bg.png", rct, pos);
    button_t *button = create_button("assets/btns/close.png", bi, bp, 1);

    set_button_events(button, &quit_quest_panel);
    register_button(panel, button);
    register_object(panel, b);
}

void start_quest_panel(ENGPANEL)
{
    register_quest_background(engine, game, panel);
    register_quest_cards(engine, game, panel);
}

void init_panel_quest(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME_QUESTS);
    set_panel_initializer(panel, &start_quest_panel, NULL);

    register_panel(eng, panel);
}