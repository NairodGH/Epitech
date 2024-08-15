/*
** EPITECH PROJECT, 2021
** get_button_color.c
** File description:
** Get button color
*/

#include <buttons.h>

sfColor get_button_color(button_t *button)
{
    if (button == NULL)
        return (sfBlack);
    return (button->color);
}