/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_saves
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void parse_pickitem(list_t *inv, char *xml)
{
    char *x;
    char *y;
    posint_t *pos;

    if (!xml)
        return;
    x = xml_get_attribute(xml, "x");
    y = xml_get_attribute(xml, "y");
    if (!nstr_isdigit(x) || !nstr_isdigit(y))
        return;
    pos = ncalloc(1, sizeof(posint_t));
    if (!pos)
        return;
    pos->x = natoi(x);
    pos->y = natoi(y);
    list_add(inv, pos);
}

save_t *read_pickitems(save_t *save, char *xml)
{
    char *mapobj;
    char **objs;

    if (!save || !xml)
        return (save);
    mapobj = xml_balcontent(xml, "map-objects");
    save->pickitems = list_create();
    if (!mapobj || !save->pickitems)
        return (save);
    objs = xml_get_balises(mapobj, "obj");
    for (uint itr = 0; objs && objs[itr]; ++itr)
        parse_pickitem(save->pickitems, objs[itr]);
    return (save);
}