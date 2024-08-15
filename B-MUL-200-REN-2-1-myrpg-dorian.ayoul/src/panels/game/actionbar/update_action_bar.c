/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Update action bar
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE void slide_actionbar_up(txt_t *txt, sfColor color)
{
    if (txt->state != 0)
        return;
    if (color.a + 2 < 255) {
        color.a += 2;
        set_text_color(txt, color);
        return;
    }
    txt->state = 1;
}

PRIVATE void slide_actionbar_down(txt_t *txt, sfColor color)
{
    if (txt->state != 1)
        return;
    if (color.a < 4) {
        color.a = 0;
        txt->state = 2;
        set_text_color(txt, color);
        return;
    }
    color.a -= 1;
    set_text_color(txt, color);
}

void update_action_bar(panel_t *panel)
{
    txt_t *txt = get_text_by_type(panel, TXT_ACTION_BAR);
    sfColor color;

    if (txt == NULL)
        return;
    color = txt->color;
    if (txt->state == 2)
        return;
    slide_actionbar_up(txt, color);
    slide_actionbar_down(txt, color);
}