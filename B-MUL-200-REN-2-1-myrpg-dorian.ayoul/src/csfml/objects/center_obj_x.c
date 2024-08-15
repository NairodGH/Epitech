/*
** EPITECH PROJECT, 2021
** center_obj_x.c
** File description:
** Center a game object in x axis on the screen
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <engine.h>
#include <objects.h>
#include <engine.h>

void center_obj_x(engine_t *engine, obj_t *obj)
{
    sfVector2f win_size;
    sfVector2f pos;
    sfIntRect rect;

    if (engine == NULL || obj == NULL)
        return;
    rect = obj->rect;
    win_size = get_window_size(engine);
    if (win_size.x == 0 || win_size.y == 0)
        return;
    pos = obj->pos;
    pos.x = win_size.x / 2.f - rect.width / 2.f;
    set_obj_pos(obj, pos);
}