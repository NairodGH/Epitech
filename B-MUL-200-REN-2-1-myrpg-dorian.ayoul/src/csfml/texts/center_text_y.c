/*
** EPITECH PROJECT, 2021
** center_text_y.c
** File description:
** Center a text in y axis on the screen
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>
#include <engine.h>

void center_text_y(engine_t *engine, txt_t *txt)
{
    sfVector2f win_size;
    sfVector2f pos;
    sfFloatRect rect;

    if (engine == NULL || txt == NULL || txt->text == NULL)
        return;
    rect = sfText_getGlobalBounds(txt->text);
    win_size = get_window_size(engine);
    if (win_size.x == 0 || win_size.y == 0)
        return;
    pos = txt->pos;
    pos.y = win_size.y / 2.f - rect.height / 2.f;
    set_text_pos(txt, pos);
}