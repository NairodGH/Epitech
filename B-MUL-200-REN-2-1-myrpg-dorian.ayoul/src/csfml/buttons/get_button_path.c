/*
** EPITECH PROJECT, 2021
** get_button_path.c
** File description:
** Get button path
*/

#include <buttons.h>

char *get_button_path(button_t *button)
{
    if (button == NULL || button->path == NULL)
        return (NULL);
    return (button->path);
}