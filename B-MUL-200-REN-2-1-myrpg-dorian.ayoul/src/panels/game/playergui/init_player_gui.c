/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void register_playergui_attributes(ENGPANEL)
{
    init_playergui_health(engine, game, panel);
    init_playergui_hunger(engine, game, panel);
    init_playergui_level(engine, game, panel);
    init_playergui_xp(engine, game, panel);
    init_playergui_ach(engine, game, panel);
    init_playergui_quest(engine, game, panel);
    init_playergui_igtime(engine, game, panel);
}

void start_panel_player(ENGPANEL)
{
    init_playergui_bg(engine, game, panel);
    init_playergui_char(engine, game, panel);
    init_playergui_name(engine, game, panel);
    register_playergui_attributes(engine, game, panel);
    init_playergui_buttons(engine, game, panel);
}

void init_panel_player(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME_PLAYERGUI);
    set_panel_initializer(panel, &start_panel_player, NULL);

    register_panel(eng, panel);
}