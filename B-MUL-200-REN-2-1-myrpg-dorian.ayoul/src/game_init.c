/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_init
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <engine.h>

PRIVATE void register_subpanels(engine_t *engine, game_t *game)
{
    init_panel_quest(engine, game);
    init_snow_panel(engine, game);
    init_rain_panel(engine, game);
    init_fog_panel(engine, game);
    init_panel_inventory(engine, game);
    init_panel_achievement(engine, game);
    init_panel_credits(engine, game);
    init_panel_player(engine, game);
    init_panel_fight(engine, game);
    init_panel_end(engine, game);
}

PRIVATE void register_panels(engine_t *engine, game_t *game)
{
    init_panel_anim(engine, game);
    init_panel_game(engine, game);
    init_panel_start(engine, game);
    init_panel_settings(engine, game);
    init_panel_cusplayer(engine, game);
    init_panel_exit(engine, game);
    init_panel_pause(engine, game);
    init_panel_savelist(engine, game);
    init_panel_savecreate(engine, game);
    init_panel_hwp(engine, game);
    init_panel_hud(engine, game);
    register_subpanels(engine, game);
}

PRIVATE game_t *prepare_game(game_t *game, list_t *args UNUSED)
{
    game->entities = parse_entities();
    game->achievements = parse_achievements();
    game->saves = load_saves(game);
    game->engine = create_engine(game->window, game, NULL);
    register_tileset(game);
    if (game->window == NULL) {
        game_exit(game, "Window == NULL\n");
        return (game);
    }
    game->stage = NULL;
    register_panels(game->engine, game);
    start_engine(game->engine, game);
    return (game);
}

void game_init(game_t *game, list_t *args)
{
    nmemset(game, 0, sizeof(game_t));
    game->is_waiting = false;
    game->window = create_window(540, 960, "RPG", 60);
    game->settings = read_settings(args);
    game->paused = false;
    game->statics = init_statics();
    game->items = load_items();
    game->skills = load_skills();
    game->player = NULL;
    game->loaded = false;
    game->load_after = false;
    game->curr_fps = 0;
    game->first_game = false;
    game->fps = 0;
    game->cutscene = parse_cutscene();
    start_fps(game);
    game = prepare_game(game, args);
}