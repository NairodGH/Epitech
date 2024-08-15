/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Scroll credits
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>
#include <file_utils.h>

void credits_events(engine_t *eng, game_t *game, panel_t *pan, sfEvent ev)
{
    if (ev.type != sfEvtKeyPressed)
        return;
    if (!eng || !game || !pan)
        return;
    close_panel_by_id(eng, game, CREDITS);
    show_panel_by_id(eng, game, START);
}