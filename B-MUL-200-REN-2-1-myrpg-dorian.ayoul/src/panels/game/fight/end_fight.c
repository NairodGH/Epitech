/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init fight panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void hide_fight_panel(engine_t *engine, game_t *game)
{
    close_panel_by_id(engine, game, GAME_FIGHT);
    show_panel_by_id(engine, game, GAME);
    show_panel_by_id(engine, game, SNOW_PANEL);
    show_panel_by_id(engine, game, FOG_PANEL);
    show_panel_by_id(engine, game, RAIN_PANEL);
    show_panel_by_id(engine, game, HUD);
}

void end_fight(engine_t *engine, game_t *game)
{
    game->curr_fight = NULL;
    hide_fight_panel(engine, game);
}

void won_fight(engine_t *engine, game_t *game)
{
    panel_t *pan = get_panel_by_id(engine, GAME);

    end_fight(engine, game);
    if (!pan)
        return;
    add_player_xp(game, 122);
    set_action_bar(engine, pan, "You won the fight.");
}

void lost_fight(engine_t *engine, game_t *game)
{
    panel_t *pan = get_panel_by_id(engine, GAME);

    end_fight(engine, game);
    if (game && game->player)
        game->player->health = 100;
    if (!pan)
        return;
    set_action_bar(engine, pan, "You lost the fight.");
}