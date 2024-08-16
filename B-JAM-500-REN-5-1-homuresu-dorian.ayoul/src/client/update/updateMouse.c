#include "includes.h"

void shoot(game_t *game, bool isPressed)
{
    if (isPressed) {
        if (game->stat->ammo <= 0 || game->stat->lastShoot != 0
            && time(NULL) - game->stat->lastShoot < game->stat->cooldownShoot)
        return;

        Sound *sound = getSound(game, SOUND_SHOT);

        if (sound && !IsSoundPlaying(*sound)) {
            playSound(game, SOUND_SHOT);
        }
        createProjectile(game, 0.3, 0.05);
    }
}
