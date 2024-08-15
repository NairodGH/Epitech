/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw item tooltip
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <cmath.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE sfVector2f get_item_tooltip_pos(sfVector2f ps, bool hd)
{
    if (hd) {
        ps.x -= 30;
        ps.y -= 50;
        return (ps);
    }
    ps.y += 20;
    return (ps);
}

bool is_item_hovered(engine_t *en, obj_t *obj, sfVector2f pos, sfVector2i ms)
{
    sfIntRect rect;
    sfVector2f to;
    sfVector2f scale;

    rect = obj->rect;
    pos.x -= 10;
    pos.y -= 10;
    to = (sfVector2f){pos.x + rect.width + 20, pos.y + rect.height + 20};
    scale = get_window_scale(en);
    ms.x = safe_scale(ms.x * 1.f, scale.x);
    ms.y = safe_scale(ms.y * 1.f, scale.y);
    return is_in_square(pos, to, (sfVector2f){ms.x, ms.y});
}

void draw_item_tooltip(engine_t *eng, obj_t *obj, sfVector2f pos, bool hud)
{
    sfVector2i mouse;
    sfInt64 it;

    if (!eng || !obj)
        return;
    if (!obj->tooltip)
        return;
    mouse = sfMouse_getPositionRenderWindow(eng->window->window);
    if (!is_item_hovered(eng, obj, pos, mouse))
        return;
    pos = get_item_tooltip_pos(pos, hud);
    display_tooltip(eng, pos, obj->tooltip);
    if (sfMouse_isButtonPressed(sfMouseLeft) && obj->on_click != NULL) {
        it = sfClock_getElapsedTime(eng->lastclick).microseconds / 1000;
        if (it < 150)
            return;
        sfClock_restart(eng->lastclick);
        obj->on_click(eng, eng->game, NULL, obj);
    }
}