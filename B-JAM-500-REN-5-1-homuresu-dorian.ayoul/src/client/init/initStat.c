#include "includes.h"

void initStat(game_t *game)
{
    game->stat = calloc(1, sizeof(stat_t));
    game->stat->ammo = 10;
    game->stat->life = 100;
    game->stat->score = 0;
    game->stat->cooldownShoot = 1;
    game->stat->lastShoot = 0;
}
