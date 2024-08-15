/*
** EPITECH PROJECT, 2021
** set_button_size.c
** File description:
** Set button size
*/

#include <buttons.h>

void set_button_size(button_t *button, sfVector2u size)
{
    if (button == NULL)
        return;
    button->size = size;
}