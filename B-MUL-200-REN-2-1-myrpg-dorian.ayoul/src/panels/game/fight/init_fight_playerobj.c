/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player fight object
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_player_fight(panel_t *panel, game_t *game)
{
    char *player_path = "assets/game/player.png";
    sfIntRect rct = {0, 0, 30, 36};
    sfVector2f pos = {220, 280};
    obj_t *player = create_object(player_path, rct, pos);
    sfVector2f sheetpos = get_player_pos(get_player_id(game), 4, -1);

    rct.left = sheetpos.x;
    rct.top = sheetpos.y;
    sfSprite_setTextureRect(player->sprite, rct);
    set_obj_type(player, OBJ_FIGHT_PLAYER);
    sfSprite_setScale(player->sprite, (sfVector2f) {2.f, 2.f});
    register_object(panel, player);
}