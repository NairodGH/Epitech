/*
** EPITECH PROJECT, 2021
** set_button_rect.c
** File description:
** Set button rect
*/

#include <buttons.h>

void set_button_rect(button_t *button, sfIntRect rect)
{
    if (button == NULL)
        return;
    button->rect = rect;
    sfSprite_setTextureRect(button->sprite, button->rect);
}