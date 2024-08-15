/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Update volume
*/

#include <rpg/rpg.h>
#include <rpg/args.h>
#include <engine.h>

bool update_volume(settings_t *settings, char *vol)
{
    int ivol;

    if (!vol)
        return (true);
    if (!nstr_isdigit(vol))
        return (false);
    ivol = natoi(vol);
    if (ivol < 0 || ivol > 100) {
        return (false);
    }
    settings->volume = ivol;
    return (true);
}