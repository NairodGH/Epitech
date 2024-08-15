/*
** EPITECH PROJECT, 2021
** set_button_path.c
** File description:
** Set button path
*/

#include <buttons.h>

void set_button_path(button_t *button, char *path)
{
    if (button == NULL || path == NULL)
        return;
    button->path = path;
    update_button(button);
}