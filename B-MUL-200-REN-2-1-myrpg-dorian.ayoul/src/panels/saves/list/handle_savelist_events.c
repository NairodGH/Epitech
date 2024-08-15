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
#include <sounds.h>
#include <rpg/rpg.h>

void on_save_load(ENGPANEL, button_t *btn)
{
    button_t *bt;
    int id = 0;

    if (panel->buttons == NULL)
        return;
    list_foreach(panel->buttons, btn_node) {
        bt = (button_t *) btn_node->value;
        if (bt->id != BTN_SAVE_LOAD)
            continue;
        if (bt == btn)
            break;
        ++id;
    }
    game->player = init_player(game->saves[id]);
    give_player_skills(game, game->player);
    game->first_game = false;
    close_panel_by_id(engine, game, SAVE_LIST);
    show_panel_by_id(engine, game, GAME);
    game->paused = false;
}

void on_save_create(ENGPANEL, button_t *btn)
{
    (void) btn;
    if (get_current_save_count(game) >= 9) {
        play_seffect(game, engine, "assets/sounds/click-err.ogg");
        return;
    }
    close_panel_by_id(engine, game, SAVE_LIST);
    show_panel_by_id(engine, game, SAVE_CREATE);
}

void init_buttons_saves(game_t *game, panel_t *panel)
{
    int x = 230;
    int y = 120;

    if (game == NULL || game->saves == NULL)
        return;
    for (int count = 0; game->saves[count] && count < 9; ++count) {
        init_save_name(panel, game->saves[count], x, y);
        x += 150;
        if (x > 600) {
            x = 230;
            y += 80;
        }
    }
}