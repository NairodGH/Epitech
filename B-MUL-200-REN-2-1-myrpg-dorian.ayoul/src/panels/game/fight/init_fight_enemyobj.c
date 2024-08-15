/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init enemy fight object
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_enemy_fight(panel_t *panel, game_t *game)
{
    obj_t *obj;
    entity_t *entity;
    sfVector2f pos = {700, 130};

    if (!panel || !game)
        return;
    if (!game->curr_fight || !game->curr_fight->entity)
        return;
    entity = game->curr_fight->entity;
    obj = create_object(entity->asset, entity->rect, pos);
    set_obj_type(obj, OBJ_FIGHT_ENTITY);
    sfSprite_setScale(obj->sprite, (sfVector2f) {2.f, 2.f});
    register_object(panel, obj);
}