/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Load game map
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE void load_some(ENGPANEL)
{
    show_panel_by_id(engine, game, HUD);
    init_inventory_bar(panel);
    init_action_bar(engine, panel);
    show_panel_by_id(engine, game, SNOW_PANEL);
    show_panel_by_id(engine, game, RAIN_PANEL);
    show_panel_by_id(engine, game, FOG_PANEL);
    load_first_game(engine, game, panel);
}

bool load_after(engine_t *engine)
{
    panel_t *panel = get_panel_by_id(engine, GAME);
    game_t *game = engine->game;

    if (!game || !panel)
        return (false);
    remove_pickitems(game);
    register_player(engine, game, panel);
    init_npc_panel(engine, game, panel);
    register_achievement_objects(game, panel);
    init_pickup(panel);
    register_object(panel, game->statics->push_quest);
    load_some(engine, game, panel);
    set_panel_bgsound(engine, panel, "assets/music/game_music.ogg");
    return (true);
}

void on_load_gthread(engine_t *engine)
{
    obj_t *loadobj = NULL;
    obj_t *loadshader = NULL;
    panel_t *panel = get_panel_by_id(engine, GAME);

    if (engine == NULL || engine->game == NULL)
        return;
    set_panel_bgsound(engine, panel, NULL);
    stage_init(engine->game);
    loadobj = get_obj_by_id(panel, OBJ_GAME_LOADING);
    loadshader = get_obj_by_id(panel, OBJ_GAME_LOADING_SHADER);
    if (loadobj)
        set_obj_visibility(loadobj, false);
    if (loadshader)
        set_obj_visibility(loadshader, false);
    engine->game->load_after = true;
}

void load_game(engine_t *engine, game_t *game, panel_t *panel)
{
    sfThread *th;

    game->loaded = false;
    game->load_after = false;
    play_seffect(game, engine, "assets/music/loading_sound.ogg");
    start_game_load(engine, game, panel);
    th = sfThread_create((void (*)(void *)) &on_load_gthread, engine);
    sfThread_launch(th);
}
