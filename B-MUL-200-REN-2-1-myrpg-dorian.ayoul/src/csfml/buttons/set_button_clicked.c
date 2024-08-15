/*
** EPITECH PROJECT, 2021
** set_button_clicked.c
** File description:
** Set button clicked
*/

#include <buttons.h>

void set_button_clicked(button_t *button, bool is_clicked)
{
    if (button == NULL)
        return;
    button->is_clicked = is_clicked;
}