/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

bool is_movement_key(game_t *game)
{
    if (game == NULL || game->settings == NULL)
        return (false);
    if (sfKeyboard_isKeyPressed(game->settings->key_up))
        return (true);
    if (sfKeyboard_isKeyPressed(game->settings->key_down))
        return (true);
    if (sfKeyboard_isKeyPressed(game->settings->key_left))
        return (true);
    if (sfKeyboard_isKeyPressed(game->settings->key_right))
        return (true);
    return (false);
}