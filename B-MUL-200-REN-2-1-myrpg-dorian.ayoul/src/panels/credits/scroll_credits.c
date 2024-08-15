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

void scroll_credits(engine_t *engine, game_t *game, panel_t *panel)
{
    txt_t *txt = NULL;
    sfVector2f pos;

    if (!engine || !game || !panel)
        return;
    txt = get_text_by_type(panel, TXT_CREDITS);
    if (!txt)
        return;
    pos = txt->pos;
    pos.y -= 0.6;
    set_text_pos(txt, pos);
    if (pos.y <= -1570) {
        close_panel_by_id(engine, game, CREDITS);
        show_panel_by_id(engine, game, START);
    }
}