/*
** EPITECH PROJECT, 2021
** handle key change
** File description:
** handle key
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

bool check_keyset_movement(settings_t *settings, sfKeyCode code)
{
    if (settings->key_up == code)
        return (true);
    if (settings->key_down == code)
        return (true);
    if (settings->key_left == code)
        return (true);
    if (settings->key_right == code)
        return (true);
    return (false);
}

bool is_key_already_set(settings_t *settings, sfKeyCode code)
{
    if (settings == NULL)
        return (true);
    if (check_keyset_movement(settings, code))
        return (true);
    if (settings->key_inv == code)
        return (true);
    if (settings->key_player == code)
        return (true);
    if (settings->key_ach == code)
        return (true);
    if (settings->key_quest == code)
        return (true);
    if (settings->key_pickup == code)
        return (true);
    return (false);
}