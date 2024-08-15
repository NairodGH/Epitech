/*
** EPITECH PROJECT, 2021
** set_button_pos.c
** File description:
** Set button pos
*/

#include <buttons.h>

void set_button_pos(button_t *button, sfVector2f pos)
{
    if (button == NULL)
        return;
    button->pos = pos;
    sfSprite_setPosition(button->sprite, button->pos);
}