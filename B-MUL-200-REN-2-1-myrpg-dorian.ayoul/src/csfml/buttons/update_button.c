/*
** EPITECH PROJECT, 2021
** update_button.c
** File description:
** Update a button
*/

#include <buttons.h>

void update_button(button_t *button)
{
    if (button == NULL || button->path == NULL)
        return;
    button->texture = sfTexture_createFromFile(button->path, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->pos);
}