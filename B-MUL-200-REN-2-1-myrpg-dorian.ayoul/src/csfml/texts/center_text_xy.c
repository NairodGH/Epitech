/*
** EPITECH PROJECT, 2021
** center_text_xy.c
** File description:
** Center a text in x & y axis on the screen
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>
#include <engine.h>

void center_text_xy(engine_t *engine, txt_t *txt)
{
    if (engine == NULL || txt == NULL || txt->text == NULL)
        return;

    center_text_x(engine, txt);
    center_text_y(engine, txt);
}