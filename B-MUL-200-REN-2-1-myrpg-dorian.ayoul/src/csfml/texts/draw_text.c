/*
** EPITECH PROJECT, 2021
** draw_text.c
** File description:
** Draw a text
*/

#include <texts.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void draw_text(engine_t *engine, txt_t *txt)
{
    sfRenderWindow *win;

    if (engine == NULL || txt == NULL || !txt->visibility)
        return;
    win = get_window(engine);
    if (win == NULL)
        return;
    sfRenderWindow_drawText(win, txt->text, NULL);
}