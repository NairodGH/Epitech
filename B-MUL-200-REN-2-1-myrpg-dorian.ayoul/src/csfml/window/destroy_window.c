/*
** EPITECH PROJECT, 2021
** destroy_window.c
** File description:
** Destroy a window
*/

#include <engine.h>
#include <window.h>
#include <nep/nstring.h>

void destroy_window(window_t *window)
{
    if (window == NULL)
        return;
    if (window->window == NULL)
        return;
    sfRenderWindow_close(window->window);
    window->destroyed = true;
}