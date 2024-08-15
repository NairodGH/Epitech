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

int get_player_foot(panel_t *pan, game_t *game, int movement)
{
    player_t *player;
    float time;

    if (game == NULL || game->player == NULL)
        return (0);
    player = game->player;
    time = sfClock_getElapsedTime(player->last_movement).microseconds;
    if (movement != player->last_view) {
        player->last_view_id = -1;
        player->last_view = movement;
        return (-1);
    }
    if (time / 10000 < 12.f)
        return (player->last_view_id);
    player->last_view = movement;
    play_footsteps(pan, game, player);
    player->last_view_id = !player->last_view_id;
    sfClock_restart(player->last_movement);
    return (player->last_view_id);
}

void change_player_asset(panel_t *pan, game_t *game, int movement, bool mov)
{
    int player_id;
    int foot_id;
    sfVector2f sheetpos;
    sfIntRect player_rect;
    obj_t *obj_player = get_player(pan);

    if (game == NULL || pan == NULL)
        return;
    if (game->settings == NULL || obj_player == NULL)
        return;
    player_id = game->settings->player;
    player_rect = sfSprite_getTextureRect(obj_player->sprite);
    foot_id = mov ? get_player_foot(pan, game, movement) : -1;
    sheetpos = get_player_pos(player_id, movement, foot_id);
    player_rect.left = sheetpos.x;
    player_rect.top = sheetpos.y;
    sfSprite_setTextureRect(obj_player->sprite, player_rect);
}

void set_player_movement_asset(panel_t *pan, game_t *game, sfKeyCode code)
{
    if (!is_movement_key(game))
        return;
    handle_food_decrease(game->player);
    if (code == game->settings->key_up)
        change_player_asset(pan, game, 0, true);
    if (code == game->settings->key_down)
        change_player_asset(pan, game, 1, true);
    if (code == game->settings->key_left)
        change_player_asset(pan, game, 2, true);
    if (code == game->settings->key_right)
        change_player_asset(pan, game, 3, true);
}