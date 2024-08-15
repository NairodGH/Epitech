/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init rain panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE sfVector2f generate_rain_texture(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_RAIN);
    sfVector2f ws = get_window_size(engine);
    sfVector2u txt;

    if (!obj)
        return (ws);
    txt = sfTexture_getSize(obj->texture);
    if ((unsigned int) ws.x != txt.x || (unsigned int) ws.y != txt.y) {
        obj->texture = sfTexture_create(ws.x, ws.y);
    }
    return (ws);
}

void update_rain_panel(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_RAIN);
    panel_t *panel_game = get_panel_by_id(engine, GAME);
    map_t *map = game->stage != NULL ? game->stage->map : NULL;
    obj_t *player = get_player(panel_game);
    sfVector2i relpos = get_player_tile_pos(map, player);
    sfVector2f ws = generate_rain_texture(engine, game, panel);

    if (!obj)
        return;
    if (relpos.y > 340)
        set_obj_visibility(obj, false);
    else
        set_obj_visibility(obj, true);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->statef += sfTime_asSeconds(sfClock_restart(obj->clock));
    sfShader_setFloatUniform(get_obj_shader(obj), "time", obj->statef);
    sfShader_setVector2Parameter(get_obj_shader(obj), "resolution", ws);
}

void on_rain_panel_start(ENGPANEL)
{
    obj_t *obj = create_shader("assets/shader/rain.frag");

    if (!obj)
        return;
    obj->texture = sfTexture_create(game->window->base_size.x,
    game->window->base_size.y);
    set_obj_type(obj, OBJ_RAIN);
    register_object(panel, obj);
}

void init_rain_panel(engine_t *engine, game_t *game UNUSED)
{
    panel_t *panel = create_panel(RAIN_PANEL);

    set_panel_initializer(panel, &on_rain_panel_start, NULL);
    set_panel_updater(panel, &update_rain_panel, NULL);
    panel->visibility = false;
    register_panel(engine, panel);
}