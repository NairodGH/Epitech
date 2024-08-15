/*
** EPITECH PROJECT, 2021
** get_window_size.c
** File description:
** Get the current window size
*/

#include <engine.h>
#include <window.h>
#include <nep/nmem.h>
#include <nep/nctype.h>

sfVector2f get_window_size(engine_t *engine)
{
    sfVector2u usize;
    sfVector2f size;
    sfRenderWindow *window = get_window(engine);

    if (window == NULL)
        return ((sfVector2f) {0, 0});
    usize = sfRenderWindow_getSize(window);
    size = (sfVector2f) {usize.x * 1.f, usize.y * 1.f};
    return (size);
}