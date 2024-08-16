#include "includes.h"

void sprint(game_t *game, bool isPressed)
{
    game->speed = isPressed;
}

void jump(game_t *game, bool isPressed)
{
    if (isPressed && game->height == 0.25f)
        game->height -= 0.01f;
}

void walk(game_t *game, bool isPressed)
{
    Sound *sound = getSound(game, SOUND_WALK);
    if (sound && IsSoundPlaying(*sound))
        return;
    playSound(game, SOUND_WALK);
}