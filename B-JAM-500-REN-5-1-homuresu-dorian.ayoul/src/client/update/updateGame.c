#include "includes.h"

static void updateMusic(game_t *game)
{
    if (IsSoundPlaying(game->music))
        return;
    PlaySound(game->music);
}

void updateGame(game_t *game)
{
    updateMusic(game);
    game->cameraLastPosition = game->camera.position;
    UpdateCamera(&game->camera);
    if (game->height != 0.25f) {
        game->camera.position.y += game->height;
        game->height += (game->gravity -= 0.01f);
        if (game->gravity < -0.25f)
            game->height = game->gravity = 0.25f;
    }
    game->camera.position.x += (game->camera.position.x - game->cameraLastPosition.x) * game->speed * 1.5;
    game->camera.position.z += (game->camera.position.z - game->cameraLastPosition.z) * game->speed * 1.5;
    updateCollision(game);
    updateEvent(game);
    updateDeadProjectile(game);
    updateDeadItem(game);
}
