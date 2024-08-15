/*
** EPITECH PROJECT, 2021
** set_button_color.c
** File description:
** Set button color
*/

#include <buttons.h>

void set_button_color(button_t *button, sfColor color)
{
    if (button == NULL)
        return;
    button->color = color;
    if (!button->sprite)
        return;
    sfSprite_setColor(button->sprite, color);
}