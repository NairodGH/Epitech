/*
** EPITECH PROJECT, 2021
** set_button_visible.c
** File description:
** Set button visible
*/

#include <buttons.h>

void set_button_visible(button_t *button, bool is_visible)
{
    if (button == NULL)
        return;
    button->is_visible = is_visible;
}