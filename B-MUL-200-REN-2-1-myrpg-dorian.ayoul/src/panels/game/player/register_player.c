/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** register_player
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

int get_player_id(game_t *game)
{
    if (game == NULL)
        return (1);
    if (game->settings == NULL)
        return (1);
    return (game->settings->player);
}

void register_player(ENGPANEL)
{
    char *player_path = "assets/game/player.png";
    sfIntRect rct = {0, 0, 30, 36};
    sfVector2f pos = {960 / 2 - 32, 540 / 2 - 32};
    obj_t *player = create_object(player_path, rct, pos);
    sfVector2f sheetpos = get_player_pos(get_player_id(game), 1, -1);

    player_teleport(game, game->player->pos_x, game->player->pos_y);
    rct.left = sheetpos.x;
    rct.top = sheetpos.y;
    sfSprite_setTextureRect(player->sprite, rct);
    set_obj_type(player, OBJ_PLAYER);
    register_object(panel, player);
}