/*
** EPITECH PROJECT, 2021
** handle buttons credits
** File description:
** handle buttons
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_credits_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, START);
    show_panel_by_id(eng, gm, CREDITS);
}