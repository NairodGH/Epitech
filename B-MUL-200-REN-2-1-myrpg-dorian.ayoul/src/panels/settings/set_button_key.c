/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init settings panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <rpg/rpg.h>

PRIVATE char *set_button_keymovement(settings_t *settings, int btn_id)
{
    if (btn_id == BTN_KEY_UP)
        return (convert_key_char(settings->key_up));
    if (btn_id == BTN_KEY_DOWN)
        return (convert_key_char(settings->key_down));
    if (btn_id == BTN_KEY_LEFT)
        return (convert_key_char(settings->key_left));
    if (btn_id == BTN_KEY_RIGHT)
        return (convert_key_char(settings->key_right));
    return (NULL);
}

char *set_button_key(settings_t *settings, int btn_id)
{
    char *keymove = set_button_keymovement(settings, btn_id);

    if (keymove != NULL)
        return (keymove);
    if (btn_id == BTN_KEY_INV)
        return (convert_key_char(settings->key_inv));
    if (btn_id == BTN_KEY_PLAYER)
        return (convert_key_char(settings->key_player));
    if (btn_id == BTN_KEY_ACH)
        return (convert_key_char(settings->key_ach));
    if (btn_id == BTN_KEY_QUEST)
        return (convert_key_char(settings->key_quest));
    if (btn_id == BTN_KEY_PICKUP)
        return (convert_key_char(settings->key_pickup));
    return ("");
}