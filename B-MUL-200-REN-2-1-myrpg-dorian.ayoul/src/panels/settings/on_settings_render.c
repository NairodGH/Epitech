/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** On settings render
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_settings_render(engine_t *eng, game_t *game, panel_t *panel)
{
    (void) eng;
    if (game == NULL || panel == NULL)
        return;
    update_key_texts(game, panel);
    update_settings_fps_text(game, panel);
    update_settings_volume_text(game, panel);
}
