/*
** EPITECH PROJECT, 2021
** center_window.c
** File description:
** Center the window
*/

#include <window.h>
#include <nep/nmem.h>
#include <nep/nctype.h>

void center_window(window_t *window)
{
    sfVideoMode mode;
    sfVector2u window_size;
    sfVector2i window_pos;

    if (window == NULL || window->window == NULL)
        return;
    mode = sfVideoMode_getDesktopMode();
    window_size = sfRenderWindow_getSize(window->window);
    window_pos = (sfVector2i) {0, 0};
    window_pos.x = mode.width / 2 - window_size.x / 2;
    window_pos.y = mode.height / 2 - window_size.y / 2;
    sfRenderWindow_setPosition(window->window, window_pos);
}