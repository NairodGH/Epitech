/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init fog panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE sfVector2f generate_fog_texture(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_FOG);
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

void update_fog_panel(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_FOG);
    sfVector2f ws = generate_fog_texture(engine, game, panel);

    if (!obj)
        return;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->statef += sfTime_asSeconds(sfClock_restart(obj->clock));
    sfShader_setFloatUniform(get_obj_shader(obj), "time", obj->statef);
    sfShader_setVector2Parameter(get_obj_shader(obj), "resolution", ws);
}

void on_fog_panel_start(ENGPANEL)
{
    obj_t *obj = create_shader("assets/shader/fog.frag");
    float elap = 0.f;

    if (!obj)
        return;
    obj->texture = sfTexture_create(game->window->base_size.x,
    game->window->base_size.y);
    obj->child = &elap;
    set_obj_type(obj, OBJ_FOG);
    set_obj_visibility(obj, true);
    register_object(panel, obj);
}

void init_fog_panel(engine_t *engine, game_t *game UNUSED)
{
    panel_t *panel = create_panel(FOG_PANEL);

    set_panel_initializer(panel, &on_fog_panel_start, NULL);
    set_panel_updater(panel, &update_fog_panel, NULL);
    panel->visibility = false;
    register_panel(engine, panel);
}