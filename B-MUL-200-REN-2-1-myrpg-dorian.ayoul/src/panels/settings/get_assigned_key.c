/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get assigned key
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <rpg/rpg.h>

PRIVATE char *get_assigned_keymov(settings_t *st, gkey_t gkey)
{
    if (gkey.id == MOVE_UP)
        return (convert_key_char(st->key_up));
    if (gkey.id == MOVE_DOWN)
        return (convert_key_char(st->key_down));
    if (gkey.id == MOVE_LEFT)
        return (convert_key_char(st->key_left));
    if (gkey.id == MOVE_RIGHT)
        return (convert_key_char(st->key_right));
    return (NULL);
}

char *get_assigned_key(game_t *game, gkey_t gkey)
{
    settings_t *settings = game->settings;
    char *keymov = get_assigned_keymov(settings, gkey);

    if (keymov != NULL)
        return (keymov);
    if (gkey.id == KEY_INV)
        return (convert_key_char(settings->key_inv));
    if (gkey.id == KEY_PLAYER)
        return (convert_key_char(settings->key_player));
    if (gkey.id == KEY_ACH)
        return (convert_key_char(settings->key_ach));
    if (gkey.id == KEY_QUEST)
        return (convert_key_char(settings->key_quest));
    if (gkey.id == KEY_PICKUP)
        return (convert_key_char(settings->key_pickup));
    return ("");
}