/*
** EPITECH PROJECT, 2021
** create_window.c
** File description:
** Create the window
*/

#include <window.h>
#include <nep/nmem.h>
#include <nep/nctype.h>

window_t *create_window(int height, int width, char *title, int framerate)
{
    window_t *win = ncalloc(1, sizeof(window_t));
    sfVideoMode video_mode = {width, height, 32};
    sfUint32 style = sfClose | sfResize;

    if (win == NULL || height < 1 || width < 1)
        return (NULL);
    win->window = sfRenderWindow_create(video_mode, title, style, NULL);
    win->base_size = (sfVector2f) {width, height};
    center_window(win);
    set_window_framerate(win, framerate);
    win->destroyed = false;
    return (win);
}