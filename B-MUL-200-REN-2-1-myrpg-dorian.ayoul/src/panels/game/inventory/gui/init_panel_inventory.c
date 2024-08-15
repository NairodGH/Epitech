/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init inventory panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_panel_inventory(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME_INVENTORY);
    set_panel_initializer(panel, &start_inventory_panel, NULL);
    set_panel_updater(panel, &tick_inventory_gui, &render_inventory_gui);

    register_panel(eng, panel);
}