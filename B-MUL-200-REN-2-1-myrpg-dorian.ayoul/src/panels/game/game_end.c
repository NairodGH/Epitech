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

PRIVATE void close_end_panels(ENGPANEL)
{
    close_panel_by_id(engine, game, GAME);
    close_panel_by_id(engine, game, SNOW_PANEL);
    close_panel_by_id(engine, game, FOG_PANEL);
    close_panel_by_id(engine, game, RAIN_PANEL);
    close_panel_by_id(engine, game, HUD);
    close_panel_by_id(engine, game, GAME_QUESTS);
    close_panel_by_id(engine, game, GAME_PLAYERGUI);
    close_panel_by_id(engine, game, GAME_ACHIEVEMENTS);
    close_panel_by_id(engine, game, GAME_INVENTORY);
}

bool handle_game_end(ENGPANEL)
{
    if (!game || !game->player)
        return (false);
    if (game->player->level < 5)
        return (false);
    close_end_panels(engine, game, panel);
    show_panel_by_id(engine, game, GAME_END);
    return (true);
}