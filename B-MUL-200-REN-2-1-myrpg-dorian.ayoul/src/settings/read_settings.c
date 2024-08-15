/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** read settings
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <file_utils.h>

settings_t *read_settings(list_t *list)
{
    settings_t *settings = init_settings(list);
    char *content = read_file("config/settings.xml");
    char *bal = NULL;

    if (!settings)
        return (NULL);
    if (content == NULL)
        return (NULL);
    bal = xml_get_balise(content, "settings");
    if (!bal)
        return (settings);
    parse_settings_attributes(settings, bal);
    parse_settings_keys(settings, bal);
    return (settings);
}
