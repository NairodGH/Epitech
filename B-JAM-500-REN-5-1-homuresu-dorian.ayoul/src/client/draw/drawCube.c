#include "includes.h"

void drawCube(game_t *game)
{
    node_t *node = NULL;
    cube_t *temp = NULL;

    DrawCubeTexture(game->menu->ground, (Vector3){ 0.0f, 0.0f, 0.0f }, 50.0f, 0.1f, 50.0f, WHITE);
    foreach(game->cube->head, node) {
        temp = (cube_t *)node->data;
        DrawCubeTexture(temp->texture, temp->position, temp->width, temp->height, temp->length, WHITE);
    }
}
