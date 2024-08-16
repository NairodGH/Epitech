#include "includes.h"

void drawGame(game_t *game)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // 3D
    BeginMode3D(game->camera);
    drawCube(game);
    drawProjectile(game);
    drawPlayer(game);
    drawItem(game);
    // add ...

    EndMode3D();
    drawSpriteTwoD(game);
    drawTextTwoD(game);
    // 2D
    // add ...

    EndDrawing();
}
