/*
** EPITECH PROJECT, 2021
** set_window_framerate.c
** File description:
** Set window frame rate
*/

#include <window.h>
#include <nep/nmem.h>
#include <nep/nctype.h>

void set_window_framerate(window_t *window, int framerate)
{
    if (framerate < 1 || window == NULL || window->window == NULL)
        return;
    window->framerate = framerate;
    sfRenderWindow_setFramerateLimit(window->window, framerate);
}