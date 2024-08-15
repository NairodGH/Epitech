/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init snow panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE sfVector2f generate_snow_texture(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_SNOW);
    sfVector2u txt;
    sfVector2f ws = get_window_size(engine);

    if (!obj)
        return (ws);
    txt = sfTexture_getSize(obj->texture);
    if ((unsigned int) ws.x != txt.x || (unsigned int) ws.y != txt.y) {
        obj->texture = sfTexture_create(ws.x, ws.y);
    }
    return (ws);
}

void update_snow_panel(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_SNOW);
    panel_t *panel_game = get_panel_by_id(engine, GAME);
    map_t *map = game->stage->map;
    obj_t *player = get_player(panel_game);
    sfVector2i relpos = get_player_tile_pos(map, player);
    sfVector2f ws = generate_snow_texture(engine, game, panel);

    if (!obj)
        return;
    if (relpos.x > 280)
        set_obj_visibility(obj, false);
    else
        set_obj_visibility(obj, true);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->statef += sfTime_asSeconds(sfClock_restart(obj->clock));
    sfShader_setFloatUniform(get_obj_shader(obj), "time", obj->statef);
    sfShader_setVector2Parameter(get_obj_shader(obj), "resolution", ws);
}

void on_snow_panel_start(ENGPANEL)
{
    obj_t *obj = create_shader("assets/shader/snow.frag");
    float elap = 0.f;

    if (!obj)
        return;
    obj->texture = sfTexture_create(game->window->base_size.x,
    game->window->base_size.y);
    obj->child = &elap;
    set_obj_type(obj, OBJ_SNOW);
    register_object(panel, obj);
}

void init_snow_panel(engine_t *engine, game_t *game UNUSED)
{
    panel_t *panel = create_panel(SNOW_PANEL);

    set_panel_initializer(panel, &on_snow_panel_start, NULL);
    set_panel_updater(panel, &update_snow_panel, NULL);
    panel->visibility = false;
    register_panel(engine, panel);
}