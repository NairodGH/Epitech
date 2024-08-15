/*
** EPITECH PROJECT, 2021
** set_button_hovered.c
** File description:
** Set button hovered
*/

#include <buttons.h>

void set_button_hovered(button_t *button, bool is_hovered)
{
    if (button == NULL)
        return;
    button->is_hovered = is_hovered;
}