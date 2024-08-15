/*
** EPITECH PROJECT, 2021
** destroy_buttons.c
** File description:
** Destroy buttons
*/

#include <buttons.h>
#include <stdlib.h>

void destroy_buttons(list_t *list)
{
    button_t *btn;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        btn = (button_t *) node->value;
        destroy_button(btn);
    }
}