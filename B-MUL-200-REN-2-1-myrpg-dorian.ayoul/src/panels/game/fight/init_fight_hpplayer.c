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

int get_player_health_percentage(game_t *game)
{
    player_t *player;

    if (!game)
        return (0);
    player = game->player;
    if (!player)
        return (0);
    return (player->health);
}

void update_fight_hpplayer(game_t *game, panel_t *panel)
{
    int pct = get_player_health_percentage(game);
    obj_t *obj = get_obj_by_id(panel, OBJ_FIGHT_HP_PLAYER);
    sfIntRect rct;

    if (!game->curr_fight || !obj)
        return;
    rct = obj->rect;
    rct.width = pct;
    set_obj_rect(obj, rct);
}

void init_fight_hpplayer(panel_t *panel)
{
    char *bg = "assets/fight/hpempty.png";
    sfIntRect rc = {0, 0, 100, 15};
    obj_t *b = create_object(bg, rc, (sfVector2f){199, 232});
    char *bg2 = "assets/fight/hpfill.png";
    sfIntRect rc2 = {0, 0, 100, 15};
    obj_t *b2 = create_object(bg2, rc2, (sfVector2f){199, 232});

    set_obj_type(b2, OBJ_FIGHT_HP_PLAYER);
    register_object(panel, b);
    register_object(panel, b2);
}