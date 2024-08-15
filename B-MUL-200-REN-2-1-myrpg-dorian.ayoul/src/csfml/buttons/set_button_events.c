/*
** EPITECH PROJECT, 2021
** set_button_events.c
** File description:
** Set button events
*/

#include <buttons.h>

void set_button_events(button_t *btn, void (*ev)(ENGPANEL, button_t *btn))
{
    if (btn == NULL)
        return;
    btn->on_click = ev;
}