/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Parse settings attributes
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <file_utils.h>

void parse_settings_attributes(settings_t *settings, char *xml)
{
    char *raw_vol;
    char *raw_fps;
    char *raw_player;

    if (xml == NULL)
        return;
    raw_vol = xml_balcontent(xml, "volume");
    raw_fps = xml_balcontent(xml, "fps");
    raw_player = xml_balcontent(xml, "player");
    update_volume(settings, raw_vol);
    update_fps(settings, raw_fps);
    update_playerid(settings, raw_player);
}