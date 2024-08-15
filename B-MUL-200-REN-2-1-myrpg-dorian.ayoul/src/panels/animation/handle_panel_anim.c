/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init anim panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void animate_background(obj_t *obj)
{
    sfColor color = sfSprite_getColor(obj->sprite);
    sfClock *c = obj->clock;
    sfInt64 time = sfClock_getElapsedTime(c).microseconds;

    if (time / 10000 < 6.f)
        return;
    if (color.a < 255)
        color.a += ((time / 10000) / 16.f) * 7;
    sfSprite_setColor(obj->sprite, color);
    sfClock_restart(c);
}

void skip_anim(engine_t *eng, game_t *gm)
{
    hide_panel(eng, START_ANIM);
    show_panel_by_id(eng, gm, START);
}

void animate_pacman(engine_t *eng, game_t *gm, obj_t *obj)
{
    sfIntRect rct = sfSprite_getTextureRect(obj->sprite);
    sfColor color = sfSprite_getColor(obj->sprite);
    float time = sfClock_getElapsedTime(obj->clock).microseconds;

    if (obj->type == -2) {
        skip_anim(eng, gm);
        return;
    }
    if (time / 10000 < 6.f)
        return;
    rct.left += 200;
    if (rct.left > 6000) {
        rct.left = 0;
        ++obj->type;
    }
    if (color.a < 255)
        color.a += ((time / 10000) / 16.f) * 7;
    sfSprite_setTextureRect(obj->sprite, rct);
    sfSprite_setColor(obj->sprite, color);
    sfClock_restart(obj->clock);
}