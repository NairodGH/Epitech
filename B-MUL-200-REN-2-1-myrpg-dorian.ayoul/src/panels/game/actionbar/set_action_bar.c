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

void set_action_bar(engine_t *eng, panel_t *panel, char *content)
{
    txt_t *txt = get_text_by_type(panel, TXT_ACTION_BAR);
    sfColor color;

    if (txt == NULL)
        return;
    if (content == NULL)
        content = "";
    set_text_content(txt, content);
    color = get_text_color(txt);
    color.a = 0;
    txt->state = 0;
    set_text_color(txt, color);
    center_text_x(eng, txt);
}