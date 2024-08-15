/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display_quest_start_card
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

PRIVATE void slide_up_quest_card(obj_t *obj)
{
    sfVector2f npos = obj->pos;

    if (obj->state == 2 && obj->pos.y <= -65) {
        obj->state = 0;
        set_obj_visibility(obj, false);
    }
    if (obj->state == 2 && obj->pos.y > -65) {
        npos.y -= 1;
        set_obj_pos(obj, npos);
        obj->pos = npos;
        return;
    }
    if (obj->state == 1 && obj->pos.y > -65) {
        if (sfClock_getElapsedTime(obj->clock).microseconds / 1000 < 1500)
            return;
        obj->state = 2;
        sfClock_restart(obj->clock);
    }
}

PRIVATE void move_quest_card(obj_t *obj)
{
    sfVector2f npos = obj->pos;
    sfInt64 elapsed = sfClock_getElapsedTime(obj->clock).microseconds / 1000;

    slide_up_quest_card(obj);
    if (obj->pos.y == 0 && obj->state == 0) {
        sfClock_restart(obj->clock);
        obj->state = 1;
    }
    if (obj->pos.y < 0 && obj->state == 0) {
        if (elapsed < 16)
            return;
        npos.y += 1;
        set_obj_pos(obj, npos);
        obj->pos = npos;
        sfClock_restart(obj->clock);
        return;
    }
}

void display_quest_card(panel_t *panel)
{
    obj_t *obj;

    if (panel == NULL)
        return;
    obj = get_obj_by_id(panel, OBJ_NEWQUEST);
    if (obj == NULL)
        return;
    if (!is_obj_visible(obj))
        return;
    move_quest_card(obj);
}

void start_quest_card_animation(panel_t *panel)
{
    obj_t *obj;

    if (panel == NULL)
        return;
    obj = get_obj_by_id(panel, OBJ_NEWQUEST);
    if (obj == NULL)
        return;
    set_obj_visibility(obj, true);
}