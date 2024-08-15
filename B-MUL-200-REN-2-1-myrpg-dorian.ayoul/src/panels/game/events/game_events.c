/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Game events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void handkeys(engine_t *eng, game_t *game, panel_t *pan, sfEvent ev)
{
    if (game->cutscene && game->cutscene->in_cutscene) {
        skip_cutscene(game);
        return;
    }
    if (ev.key.code == game->settings->key_quest)
        handle_panel_quests_events(eng, game, pan);
    if (ev.key.code == game->settings->key_ach)
        handle_panel_achievements_events(eng, game, pan);
    if (ev.key.code == game->settings->key_inv)
        handle_panel_inventory_events(eng, game, pan);
    if (ev.key.code == game->settings->key_player)
        handle_playergui_events(eng, game, pan);
    if (ev.key.code == game->settings->key_pickup)
        pickup_item(pan, game);
}

void game_event(engine_t *eng, game_t *game, panel_t *panel, sfEvent ev)
{
    if (!game->loaded)
        return;
    if (ev.type == sfEvtKeyPressed) {
        game_event_escape(eng, game, ev);
    }
    if (ev.type == sfEvtKeyReleased)
        handkeys(eng, game, panel, ev);
    if (ev.type == sfEvtMouseWheelScrolled)
        zoom_map(eng, ev);
}

PRIVATE void game_subrender(engine_t *eng, game_t *game, panel_t *panel)
{
    draw_map(game, game->stage->map);
    display_entities(panel, game);
    save_player_clock(game->player);
    if (game->paused)
        return;
    handle_health(eng, game, panel);
    handle_cutscene(eng, game, panel);
    move_player(eng, panel, game);
    display_achievements(game);
    display_quest_card(panel);
    check_npc_panel(eng, game, panel);
    handle_item_pick(panel, game);
    update_action_bar(panel);
}

void game_render(engine_t *eng, game_t *game, panel_t *panel)
{
    if (game->load_after) {
        load_after(eng);
        game->load_after = false;
        game->loaded = true;
    }
    if (!game->loaded) {
        render_game_load(eng, game, panel);
        return;
    }
    if (handle_game_end(eng, game, panel))
        return;
    game_subrender(eng, game, panel);
}

void game_tick(engine_t *eng, game_t *game, panel_t *panel)
{
    if (!game->loaded)
        return;
    (void) eng;
    update_inventory_bar(eng, game, panel);
}