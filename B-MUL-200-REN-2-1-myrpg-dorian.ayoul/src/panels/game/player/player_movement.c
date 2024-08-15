/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

sfkeycode_t get_movement_key(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->settings->key_up))
        return (game->settings->key_up);
    if (sfKeyboard_isKeyPressed(game->settings->key_down))
        return (game->settings->key_down);
    if (sfKeyboard_isKeyPressed(game->settings->key_left))
        return (game->settings->key_left);
    if (sfKeyboard_isKeyPressed(game->settings->key_right))
        return (game->settings->key_right);
    if (sfKeyboard_isKeyPressed(sfKeyF))
        return (sfKeyF);
    return (sfKeyUnknown);
}

PRIVATE void move_map(sfKeyCode key, engine_t *eng, panel_t *pan, int ch)
{
    game_t *game = eng->game;
    settings_t *set = game->settings;
    double scroll_x = game->stage->map->sroll.x;
    double scroll_y = game->stage->map->sroll.y;
    sfVector2f msize = game->stage->map->size;
    float b = ch * .14f;

    scroll_y += key == set->key_down ? b : key == set->key_up ? -b : 0;
    scroll_x += key == set->key_right ? b : key == set->key_left ? -b : 0;
    if (scroll_x < 0 || scroll_y < 0 || scroll_y >= (int) msize.y - 5 ||
    scroll_x >= (int) msize.x - 10)
        return;
    if (player_collides(pan, game->stage->map, scroll_x, scroll_y))
        return;
    game->stage->map->sroll.x = scroll_x;
    game->stage->map->sroll.y = scroll_y;
    game->player->pos_x = (int) scroll_x;
    game->player->pos_y = (int) scroll_y;
}

void handle_map_movement(sfKeyCode key, ENGPANEL)
{
    sfClock *c = game->player->last_pos_change;
    sfInt64 time = sfClock_getElapsedTime(c).microseconds / 1000;
    int change;

    if (time < 16)
        return;
    change = (time > 300 ? 1 : (int) (time / 16));
    move_map(key, engine, panel, change);
    sfClock_restart(c);
}

PRIVATE bool cant_move_player(engine_t *engine)
{
    panel_t *paninv = get_panel_by_id(engine, GAME_INVENTORY);
    panel_t *panquest = get_panel_by_id(engine, GAME_QUESTS);
    panel_t *panach = get_panel_by_id(engine, GAME_ACHIEVEMENTS);

    if (engine && engine->game && engine->game->cutscene) {
        if (engine->game->cutscene->in_cutscene)
            return (true);
    }
    if (paninv != NULL && paninv->visibility)
        return (true);
    if (panquest != NULL && panquest->visibility)
        return (true);
    if (panach != NULL && panach->visibility)
        return (true);
    return (false);
}

void move_player(engine_t *eng, panel_t *pan, game_t *game)
{
    sfKeyCode key;

    if (!is_movement_key(game)) {
        sfClock_restart(game->player->last_pos_change);
        change_player_asset(pan, game, game->player->last_view, false);
        return;
    }
    if (cant_move_player(eng))
        return;
    key = get_movement_key(game);
    set_player_movement_asset(pan, game, key);
    handle_map_movement(key, eng, game, pan);
}