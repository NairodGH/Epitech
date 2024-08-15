/*
** EPITECH PROJECT, 2021
** set_text_events.c
** File description:
** Set text events
*/

#include <engine.h>
#include <panel.h>
#include <texts.h>

void set_text_events(txt_t *txt, void (*ev)(ENGPANEL, txt_t *obj))
{
    if (txt == NULL)
        return;
    txt->on_click = ev;
}