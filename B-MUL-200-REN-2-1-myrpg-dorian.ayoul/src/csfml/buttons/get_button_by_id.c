/*
** EPITECH PROJECT, 2021
** get_button_by_id.c
** File description:
** Get button by id
*/

#include <engine.h>
#include <buttons.h>
#include <panel.h>

button_t *get_button_by_id(panel_t *panel, int id)
{
    button_t *btn = NULL;

    if (panel == NULL || panel->buttons == NULL)
        return (btn);
    list_foreach(panel->buttons, node) {
        btn = (button_t *) node->value;
        if (btn->id == id)
            return (btn);
    }
    return (NULL);
}