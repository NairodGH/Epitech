/*
** EPITECH PROJECT, 2021
** destroy_button.c
** File description:
** Destroys a button
*/

#include <buttons.h>
#include <stdlib.h>

void destroy_button(button_t *button)
{
    if (button == NULL || button->path == NULL)
        return;
    if (button->sprite != NULL) {
        sfSprite_destroy(button->sprite);
        button->sprite = NULL;
    }
    if (button->tooltip != NULL && button->tooltip->sprite) {
        sfSprite_destroy(button->tooltip->sprite);
        button->tooltip->sprite = NULL;
        free(button->tooltip);
    }
    button->tooltip = NULL;
    if (button->texture != NULL) {
        sfTexture_destroy(button->texture);
        button->texture = NULL;
    }
}