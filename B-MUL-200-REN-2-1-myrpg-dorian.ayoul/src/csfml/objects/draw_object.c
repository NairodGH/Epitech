/*
** EPITECH PROJECT, 2021
** draw_object.c
** File description:
** Draw a game object
*/

#include <panel.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void draw_object(engine_t *engine, obj_t *obj)
{
    sfRenderWindow *win;

    if (engine == NULL || obj == NULL)
        return;
    win = get_window(engine);
    if (win == NULL || !is_obj_visible(obj))
        return;
    if (!obj->sprite)
        return;
    sfRenderWindow_drawSprite(win, obj->sprite, NULL);
}