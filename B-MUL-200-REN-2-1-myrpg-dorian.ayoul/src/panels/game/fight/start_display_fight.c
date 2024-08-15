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

void hide_unfight_panels(ENGPANEL)
{
    hide_panel(engine, GAME);
    hide_panel(engine, SNOW_PANEL);
    hide_panel(engine, FOG_PANEL);
    hide_panel(engine, RAIN_PANEL);
    hide_panel(engine, HUD);
    close_panel_by_id(engine, game, GAME_QUESTS);
    close_panel_by_id(engine, game, GAME_PLAYERGUI);
    close_panel_by_id(engine, game, GAME_ACHIEVEMENTS);
    close_panel_by_id(engine, game, GAME_INVENTORY);
}

void start_display_fight(ENGPANEL, entity_t *entity)
{
    start_fight(game, entity);
    hide_unfight_panels(engine, game, panel);
    show_panel_by_id(engine, game, GAME_FIGHT);
}