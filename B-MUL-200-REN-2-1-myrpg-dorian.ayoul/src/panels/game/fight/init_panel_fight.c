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

void init_panel_fight(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME_FIGHT);
    set_panel_initializer(panel, &start_fight_panel, NULL);
    set_panel_updater(panel, &tick_fight, &render_fight);

    register_panel(eng, panel);
}