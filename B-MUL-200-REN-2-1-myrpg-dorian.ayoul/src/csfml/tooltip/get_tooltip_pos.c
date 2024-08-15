/*
** EPITECH PROJECT, 2021
** get_tooltip_pos.c
** File description:
** Get tooltip pos
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <texts.h>
#include <rpg/rpg.h>

static sfVector2f get_pos_margin(sfVector2f mouse)
{
    mouse.x += 20;
    mouse.y += 10;
    return (mouse);
}

static sfVector2f compute_last_pos(sfFloatRect rect, sfVector2f mouse)
{
    sfVector2f pos = {rect.width + mouse.x, rect.height + mouse.y};

    return (pos);
}

static sfVector2f compute_left_pos(sfFloatRect rect, sfVector2f mouse)
{
    sfVector2f pos = {mouse.x - rect.width, mouse.y - rect.height};
    pos.x -= 25;
    pos.y += 25;
    return (pos);
}

sfVector2f get_tooltip_pos(tooltip_t *tool, sfVector2f mouse)
{
    sfFloatRect size = get_tooltip_size(tool);
    mouse = get_pos_margin(mouse);
    sfVector2f bright = compute_last_pos(size, mouse);

    if (bright.x < WINDOW_X && bright.y < WINDOW_Y)
        return (mouse);
    return (compute_left_pos(size, mouse));
}

sfVector2f get_tooltip_text_pos(sfVector2f newpos)
{
    return ((sfVector2f) {newpos.x + 25, newpos.y + 3});
}