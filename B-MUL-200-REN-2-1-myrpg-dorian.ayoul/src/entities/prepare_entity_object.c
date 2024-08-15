/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** prepare_entity_object
*/

#include <rpg/rpg.h>

obj_t *prepare_entity_object(entity_t *e)
{
    obj_t *obj = create_object(e->asset, e->rect, e->pos);

    set_obj_type(obj, OBJ_ENTITY);
    return (obj);
}