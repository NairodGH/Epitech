#include "includes.h"

void initMusic(game_t *game)
{
    game->music = LoadSound("assets/sounds/music.wav");
    SetSoundVolume(game->music, 0.15);
}
