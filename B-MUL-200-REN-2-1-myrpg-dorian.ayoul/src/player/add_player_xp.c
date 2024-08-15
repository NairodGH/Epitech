/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Add player xp
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

void add_player_xp(game_t *game, int xp)
{
    player_t *player;

    if (!game || !game->player)
        return;
    player = game->player;
    player->xp += xp;
    while (player->xp >= 100) {
        player->level += 1;
        give_player_skills(game, player);
        player->xp -= 100;
    }
    if (player->xp < 0)
        player->xp = 0;
}