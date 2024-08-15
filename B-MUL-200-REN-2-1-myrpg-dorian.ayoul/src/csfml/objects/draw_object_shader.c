/*
** EPITECH PROJECT, 2021
** draw_object_shader.c
** File description:
** Draw a game object with shader
*/

#include <panel.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

#include <rpg/rpg.h>

void draw_object_shader(engine_t *engine, obj_t *obj)
{
    sfRenderWindow *win;
    sfVector2u sz;

    if (engine == NULL || obj == NULL || obj->render.shader == NULL)
        return;
    if (!obj->visibility)
        return;
    win = get_window(engine);
    if (win == NULL)
        return;
    sz = sfTexture_getSize(obj->texture);
    sfVector2f ws = get_window_size(engine);
    if ((unsigned int) ws.x != sz.x || (unsigned int) ws.y != sz.y) {
        return;
    }
    sfTexture_updateFromRenderWindow(obj->texture, get_window(engine), 0, 0);
    sfRenderWindow_drawSprite(win, obj->sprite, &obj->render);
}
