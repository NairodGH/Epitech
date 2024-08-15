/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Parse settings keys
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <file_utils.h>

bool set_setting_key(sfKeyCode *code, char *val)
{
    sfKeyCode c = get_key_code(val);

    if (c == -1)
        return (false);
    *code = c;
    return (true);
}

static bool parse_settings_mvk(settings_t *settings, char *key, char *value)
{
    if (!nstrcmp(key, "KEY_UP"))
        return (set_setting_key(&settings->key_up, value));
    if (!nstrcmp(key, "KEY_DOWN"))
        return (set_setting_key(&settings->key_down, value));
    if (!nstrcmp(key, "KEY_LEFT"))
        return (set_setting_key(&settings->key_left, value));
    if (!nstrcmp(key, "KEY_RIGHT"))
        return (set_setting_key(&settings->key_right, value));
    return (false);
}

PRIVATE bool parse_settings_key(settings_t *settings, char *key)
{
    char *type = xml_get_attribute(key, "type");
    char *value = xml_get_attribute(key, "value");

    if (!type || !value)
        return (false);
    if (parse_settings_mvk(settings, type, value))
        return (true);
    if (!nstrcmp(type, "KEY_INV"))
        return (set_setting_key(&settings->key_inv, value));
    if (!nstrcmp(type, "KEY_PLAYER"))
        return (set_setting_key(&settings->key_player, value));
    if (!nstrcmp(type, "KEY_ACH"))
        return (set_setting_key(&settings->key_ach, value));
    if (!nstrcmp(type, "KEY_QUEST"))
        return (set_setting_key(&settings->key_quest, value));
    if (!nstrcmp(type, "KEY_PICKUP"))
        return (set_setting_key(&settings->key_pickup, value));
    return (false);
}

bool parse_settings_keys(settings_t *settings, char *xml)
{
    char *balkey = xml_balcontent(xml, "keys");
    char **keys;

    if (!balkey)
        return (false);
    keys = xml_get_balises(balkey, "key");
    if (!keys)
        return (false);
    for (unsigned int itr = 0; keys[itr]; ++itr)
        parse_settings_key(settings, keys[itr]);
    return (true);
}