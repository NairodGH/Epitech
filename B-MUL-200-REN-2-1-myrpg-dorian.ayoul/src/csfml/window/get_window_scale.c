/*
** EPITECH PROJECT, 2021
** get_window_scale.c
** File description:
** Window scale
*/

#include <engine.h>
#include <window.h>
#include <nep/nmem.h>
#include <nep/nctype.h>

sfVector2f get_window_scale(engine_t *eng)
{
    window_t *win;

    if (eng == NULL)
        return (sfVector2f){0, 0};
    win = eng->window;
    if (win == NULL)
        return (sfVector2f){0, 0};
    sfVector2f b_size = win->base_size;
    sfVector2u o = sfRenderWindow_getSize(win->window);
    return (sfVector2f){o.x / b_size.x, o.y / b_size.y};
}