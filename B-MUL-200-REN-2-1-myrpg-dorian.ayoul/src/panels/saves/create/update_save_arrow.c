/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update save arrow
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>

void set_save_arrow_position(obj_t *obj, txt_t *txt)
{
    sfVector2f txt_pos;
    sfVector2f obj_pos;
    float time;

    if (obj == NULL || txt == NULL || obj->clock == NULL)
        return;
    obj_pos = sfSprite_getPosition(obj->sprite);
    txt_pos = get_text_endpos(txt);
    obj_pos.x = txt_pos.x - 12;
    sfSprite_setPosition(obj->sprite, obj_pos);
    time = sfClock_getElapsedTime(obj->clock).microseconds / 1000;
    if (time < 300)
        return;
    sfClock_restart(obj->clock);
    set_obj_visibility(obj, !is_obj_visible(obj));
}

void update_save_arrow(ENGPANEL)
{
    obj_t *obj;
    txt_t *txt = NULL;

    if (panel->objects == NULL || panel->texts == NULL)
        return;
    list_foreach(panel->texts, node)
        txt = (txt_t *) node->value;
    if (txt == NULL)
        return;
    list_foreach(panel->objects, node) {
        obj = (obj_t *) node->value;
        if (obj->type != OBJ_SAVECREATE_ARROW)
            continue;
        set_save_arrow_position(obj, txt);
    }
}