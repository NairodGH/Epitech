/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <file_utils.h>

PRIVATE enum consumption_type get_consumption_type(char *str)
{
    if (str == NULL)
        return (UNKNOWN_CONSUMPTION);
    if (!nstrcmp(str, "HEALTH"))
        return (CONSUMPTION_HEALTH);
    if (!nstrcmp(str, "FOOD"))
        return (CONSUMPTION_FOOD);
    return (UNKNOWN_CONSUMPTION);
}

PRIVATE consumption_t *parse_consumable(char *xml)
{
    consumption_t *consumption;
    char *raw_type = NULL;

    if (!xml)
        return (NULL);
    consumption = ncalloc(1, sizeof(consumption_t));
    if (!consumption)
        return (NULL);
    raw_type = xml_get_attribute(xml, "type");
    consumption->type = get_consumption_type(raw_type);
    consumption->value = natoi(xml_get_attribute(xml, "value"));
    consumption->message = xml_get_attribute(xml, "message");
    consumption->sound = xml_get_attribute(xml, "sound");
    return (consumption);
}

item_t *parse_item_consumable(item_t *item, char *xml)
{
    char *consumptions = xml_balcontent(xml, "consumptions");
    char **list = NULL;

    if (!xml || !item || !consumptions) {
        item->consumptions = NULL;
        return (item);
    }
    list = xml_get_balises(consumptions, "consumption");
    if (!list) {
        item->consumptions = NULL;
        return (item);
    }
    item->consumptions = list_create();
    if (!item->consumptions)
        return (item);
    for (unsigned int itr = 0; list[0] && list[itr]; ++itr)
        list_add(item->consumptions, parse_consumable(list[itr]));
    return (item);
}