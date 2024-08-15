/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Render game load
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void render_game_load(engine_t *engine UNUSED, game_t *game, panel_t *panel)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_GAME_LOADING_SHADER);
    obj_t *objload = get_obj_by_id(panel, OBJ_GAME_LOADING);
    static float time_elapsed = 0;
    sfVector2f sp = game->window->base_size;

    if (!obj || !obj->visibility)
        return;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    time_elapsed += sfTime_asSeconds(sfClock_restart(obj->clock));
    sfShader_setFloatUniform(get_obj_shader(obj), "time", time_elapsed);
    sfShader_setVector2Parameter(get_obj_shader(obj), "resolution", sp);
    draw_object(engine, obj);
    if (objload)
        draw_object(engine, objload);
}

void start_game_load(engine_t *engine, game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    sfVector2f pos = {130, 90};
    sfVector2f pl = {game->window->base_size.x, game->window->base_size.y};
    obj_t *shader = create_shader("assets/shader/loader.frag");
    obj_t *obj = create_object("assets/game/loading.png", rct, pos);

    if (!shader)
        return;
    shader->texture = sfTexture_create(pl.x, pl.y);
    set_obj_type(shader, OBJ_GAME_LOADING_SHADER);
    set_obj_type(obj, OBJ_GAME_LOADING);
    register_object(panel, shader);
    register_object(panel, obj);
    sfRenderWindow_clear(get_window(engine), sfBlack);
    draw_object(engine, shader);
    draw_object(engine, obj);
    sfRenderWindow_display(get_window(engine));
}