/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** finish_achievement
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

PRIVATE void slide_up_achievement_card(achievement_t *achievement, obj_t *obj)
{
    sfVector2f npos = obj->pos;

    if (achievement->animation_state == 2 && obj->pos.y <= -65) {
        achievement->animation_state = 0;
        set_obj_visibility(achievement->obj, false);
    }
    if (achievement->animation_state == 2 && obj->pos.y > -65) {
        npos.y -= 1;
        set_obj_pos(obj, npos);
        obj->pos = npos;
        return;
    }
    if (achievement->animation_state == 1 && obj->pos.y > -65) {
        if (sfClock_getElapsedTime(obj->clock).microseconds / 1000 < 1500)
            return;
        achievement->animation_state = 2;
        sfClock_restart(obj->clock);
    }
}

PRIVATE void move_achievement_card(achievement_t *achievement, obj_t *obj)
{
    sfVector2f npos = obj->pos;
    sfInt64 elapsed = sfClock_getElapsedTime(obj->clock).microseconds / 1000;

    slide_up_achievement_card(achievement, obj);
    if (obj->pos.y == 0 && achievement->animation_state == 0) {
        sfClock_restart(obj->clock);
        achievement->animation_state = 1;
    }
    if (obj->pos.y < 0 && achievement->animation_state == 0) {
        if (elapsed < 16)
            return;
        npos.y += 1;
        set_obj_pos(obj, npos);
        obj->pos = npos;
        sfClock_restart(obj->clock);
        return;
    }
}

void display_achievement(achievement_t *achievement)
{
    obj_t *obj;

    if (achievement == NULL || achievement->obj == NULL)
        return;
    obj = achievement->obj;
    if (!is_obj_visible(obj))
        return;
    move_achievement_card(achievement, obj);
}

void display_achievements(game_t *game)
{
    if (game == NULL || game->achievements == NULL)
        return;
    for (unsigned int itr = 0; game->achievements[itr]; ++itr) {
        display_achievement(game->achievements[itr]);
    }
}