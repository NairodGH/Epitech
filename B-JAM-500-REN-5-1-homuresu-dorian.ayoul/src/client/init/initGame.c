#include "includes.h"

void initGame(game_t *game)
{
    #ifndef _WIN32
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initWindow(game->windowSize.x, game->windowSize.y);
    #else
    initWindow(1280, 720);
    #endif
    game->id = -1;
    initCamera(game);
    initModels(game);
    initItem(game);
    initProjectile(game);
    initCube(game);
    initWall(game);
    initMusic(game);
    initSounds(game);
    initSprite(game);
    initStat(game);
    initPlayer(game);
    initMenu(game);
}
