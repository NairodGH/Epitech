/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** read settings
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <file_utils.h>

static void save_setting_key(xml_balise_t *keys, char *key, sfKeyCode code)
{
    xml_balise_t *kbalise = xml_add_balise(keys, "key");

    xml_add_attribute(kbalise, "type", key);
    xml_add_attribute(kbalise, "value", convert_key_char(code));
}

static void save_setting_keys(xml_balise_t *keys, settings_t *set)
{
    save_setting_key(keys, "KEY_UP", set->key_up);
    save_setting_key(keys, "KEY_DOWN", set->key_down);
    save_setting_key(keys, "KEY_LEFT", set->key_left);
    save_setting_key(keys, "KEY_RIGHT", set->key_right);
    save_setting_key(keys, "KEY_INV", set->key_inv);
    save_setting_key(keys, "KEY_PLAYER", set->key_player);
    save_setting_key(keys, "KEY_ACH", set->key_ach);
    save_setting_key(keys, "KEY_QUEST", set->key_quest);
    save_setting_key(keys, "KEY_PICKUP", set->key_pickup);
}

void save_settings(settings_t *st)
{
    char *content = NULL;
    xml_balise_t *settings = xml_add_balise(NULL, "settings");
    xml_balise_t *vol = xml_add_balise(settings, "vol");
    xml_balise_t *fps = xml_add_balise(settings, "fps");
    xml_balise_t *playerid = xml_add_balise(settings, "player");
    xml_balise_t *keys = xml_add_balise(settings, "keys");

    xml_set_content(vol, int_to_str(st->volume));
    xml_set_content(fps, int_to_str(st->fps));
    xml_set_content(playerid, int_to_str(st->player));
    save_setting_keys(keys, st);
    content = xml_serialize(settings);
    if (!content)
        return;
    write_file("config/settings.xml", content);
}