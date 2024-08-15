/*
** EPITECH PROJECT, 2021
** set_button_id.c
** File description:
** Set button id
*/

#include <buttons.h>

void set_button_id(button_t *button, int id)
{
    if (button == NULL)
        return;
    button->id = id;
}