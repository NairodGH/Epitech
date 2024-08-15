/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init start panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE sfVector2f generate_fog_texture(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_BG_STARTMENU);
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

void update_start_panel(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_BG_STARTMENU);
    sfVector2f ws = generate_fog_texture(engine, game, panel);

    if (!obj)
        return;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->statef += sfTime_asSeconds(sfClock_restart(obj->clock));
    sfShader_setFloatUniform(get_obj_shader(obj), "time", obj->statef);
    sfShader_setVector2Parameter(get_obj_shader(obj), "resolution", ws);
}

void init_start_menu(engine_t *eng UNUSED, game_t *game UNUSED, panel_t *panel)
{
    init_start_texts(game, panel);
    init_buttons_start_play(game, panel);
    init_buttons_start_quit(panel);
    init_buttons_start_settings(panel);
    init_buttons_start_custom(panel);
    init_buttons_start_credits(panel);
    set_panel_visibility(panel, true);
}

void init_panel_start(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(START);

    set_panel_initializer(panel, &init_start_menu, NULL);
    set_panel_bgsound(eng, panel, "assets/music/menu_music.ogg");
    set_panel_updater(panel, &update_start_panel, NULL);
    (void) game;
    register_panel(eng, panel);
}