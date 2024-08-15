/*
** EPITECH PROJECT, 2021
** get_button_pos.c
** File description:
** Get button pos
*/

#include <buttons.h>

sfVector2f get_button_pos(button_t *button)
{
    return (button->pos);
}