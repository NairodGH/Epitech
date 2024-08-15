/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Update player id
*/

#include <rpg/rpg.h>
#include <rpg/args.h>
#include <engine.h>

bool update_playerid(settings_t *settings, char *plid)
{
    int iplayerid;

    if (!plid)
        return (true);
    if (!nstr_isdigit(plid))
        return (false);
    iplayerid = natoi(plid);
    if (iplayerid < 0 || iplayerid > 12) {
        return (false);
    }
    settings->player = iplayerid;
    return (true);
}