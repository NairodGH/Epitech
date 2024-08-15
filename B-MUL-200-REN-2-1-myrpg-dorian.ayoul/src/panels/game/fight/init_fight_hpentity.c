/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init background fight object
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

int get_entity_health_percentage(game_t *game)
{
    fight_t *currfight;
    float pct = 0.f;

    if (!game)
        return (0);
    currfight = game->curr_fight;
    if (!currfight || !currfight->entity)
        return (0);
    if (!currfight->entity->fight)
        return (0);
    pct = currfight->entity_health * 1.f;
    pct /= currfight->entity->fight->health * 1.f;
    pct *= 100;
    return (pct);
}

void update_fight_hpentity(game_t *game, panel_t *panel)
{
    int pct = get_entity_health_percentage(game);
    obj_t *obj = get_obj_by_id(panel, OBJ_FIGHT_HP_ENTITY);
    sfIntRect rct;

    if (!game->curr_fight || !obj)
        return;
    rct = obj->rect;
    rct.width = pct;
    set_obj_rect(obj, rct);
}

void init_fight_hpentity(panel_t *panel)
{
    char *bg = "assets/fight/hpempty.png";
    sfIntRect rc = {0, 0, 100, 15};
    obj_t *b = create_object(bg, rc, (sfVector2f){671, 93});
    char *bg2 = "assets/fight/hpfill.png";
    sfIntRect rc2 = {0, 0, 100, 15};
    obj_t *b2 = create_object(bg2, rc2, (sfVector2f){671, 93});

    set_obj_type(b2, OBJ_FIGHT_HP_ENTITY);
    register_object(panel, b);
    register_object(panel, b2);
}