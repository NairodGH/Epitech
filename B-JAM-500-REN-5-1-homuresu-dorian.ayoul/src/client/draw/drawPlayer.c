#include "includes.h"

void drawPlayer(game_t *game)
{
    node_t *node = NULL;
    player_t *temp = NULL;

    foreach(game->player->head, node) {
        temp = (player_t *)node->data;
        if (temp->isAlive) {
            Matrix transform = temp->model.model.transform;

            temp->model.model.transform = MatrixMultiply(transform, MatrixRotateY(atan2(temp->direction.x, temp->direction.z) + PI));
            DrawModel(temp->model.model, temp->position, 1, WHITE);
            temp->model.model.transform = transform;
        }
    }
}
