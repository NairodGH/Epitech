/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Update fps
*/

#include <rpg/rpg.h>
#include <rpg/args.h>
#include <engine.h>

bool update_fps(settings_t *settings, char *fps)
{
    int ifps;

    if (!fps)
        return (true);
    if (!nstr_isdigit(fps))
        return (false);
    ifps = natoi(fps);
    if (ifps < 10 || ifps > 120) {
        return (false);
    }
    settings->fps = ifps;
    return (true);
}