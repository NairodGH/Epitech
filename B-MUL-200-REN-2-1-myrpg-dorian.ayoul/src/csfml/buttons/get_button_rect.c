/*
** EPITECH PROJECT, 2021
** get_button_rect.c
** File description:
** Get button rect
*/

#include <buttons.h>

sfIntRect get_button_rect(button_t *button)
{
    return (button->rect);
}