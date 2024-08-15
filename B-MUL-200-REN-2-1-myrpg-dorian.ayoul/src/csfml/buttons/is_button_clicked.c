/*
** EPITECH PROJECT, 2021
** get_button_clicked.c
** File description:
** Is button clicked ?
*/

#include <engine.h>
#include <buttons.h>
#include <cmath.h>
#include <window.h>

double safe_scale(double pos, double scale)
{
    if (scale == 0.0f)
        return (pos);
    return (pos * (1.f / scale));
}

bool get_button_clicked(button_t *button, sfMouseButtonEvent ev)
{
    sfIntRect rect;
    sfVector2f from;
    sfVector2f to;

    if (button == NULL)
        return (NULL);
    rect = button->rect;
    from = button->pos;
    to = (sfVector2f){button->pos.x + rect.width, button->pos.y + rect.height};
    return is_in_square(from, to, (sfVector2f){ev.x, ev.y});
}

bool get_button_hovered(engine_t *eng, button_t *button, sfVector2i v2i)
{
    sfIntRect rect;
    sfVector2f from;
    sfVector2f to;
    sfVector2f mouse;
    sfVector2f scale;

    if (button == NULL || !button->is_visible)
        return (false);
    rect = button->rect;
    from = button->pos;
    to = (sfVector2f){button->pos.x + rect.width, button->pos.y + rect.height};
    scale = get_window_scale(eng);
    mouse.x = safe_scale(v2i.x * 1.f, scale.x);
    mouse.y = safe_scale(v2i.y * 1.f, scale.y);
    return is_in_square(from, to, mouse);
}