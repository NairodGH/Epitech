#include "includes.h"
#include "iencli.h"

void removeItemFromGame(game_t *game, float x, float z)
{
    node_t *node = NULL;
    item_t *temp = NULL;

    foreach(game->item->head, node) {
        temp = (item_t *)node->data;
        if (temp->position.x == x && temp->position.z == z) {
            temp->isAlive = false;
            break;
        }
    }
}

static void checkCollisionProjectile(game_t *game, cube_t *cube)
{
    node_t *node = NULL;
    projectile_t *temp = NULL;
    node_t *node2 = NULL;
    player_t *player = NULL;
    char *msg = calloc(1, 100);

    foreach(game->projectile->head, node) {
        temp = (projectile_t *)node->data;
        if (temp->isAlive == false)
            continue;
        if ((temp->position.x > cube->position.x - cube->width / 2 &&
            temp->position.x < cube->position.x + cube->width / 2 &&
            temp->position.z > cube->position.z - cube->length / 2 &&
            temp->position.z < cube->position.z + cube->length / 2)) {
            playSound(game, SOUND_HIT);
            temp->isAlive = false;
        }
        if (temp->position.y < 0 || temp->position.y > 32) {
            temp->isAlive = false;
        }
        foreach(game->player->head, node2) {
            player = (player_t *)node2->data;
            if (player->isAlive == false || player->id == temp->id)
                continue;
            if (temp->position.x > player->position.x - 0.5 &&
                temp->position.x < player->position.x + 0.5 &&
                temp->position.z > player->position.z - 0.5 &&
                temp->position.z < player->position.z + 0.5) {
                temp->isAlive = false;
                game->stat->score += 1;
                #ifndef _WIN32
                sprintf(msg, "LIFE %d %d", player->id, -20);
                send_tcp_packet(game->socket, msg, EOF_NETWORK);
                return;
                #endif
            }
        }
    }
}

static void checkCollisionItem(game_t *game)
{
    node_t *node = NULL;
    item_t *temp = NULL;
    char *msg = calloc(1, 100);

    foreach(game->item->head, node) {
        temp = (item_t *)node->data;
        if (game->camera.position.x > temp->position.x - temp->width / 2 &&
            game->camera.position.x < temp->position.x + temp->width / 2 &&
            game->camera.position.z > temp->position.z - temp->length / 2 &&
            game->camera.position.z < temp->position.z + temp->length / 2) {
            if (strcmp(temp->name, "ammoBox") == 0) {
                playSound(game, SOUND_AMMO);
                game->stat->ammo += 10;
                temp->isAlive = false;
                #ifndef _WIN32
                sprintf(msg, "ITEM %f %f", temp->position.x, temp->position.z);
                send_tcp_packet(game->socket, msg, EOF_NETWORK);
                #endif
                return;
            }
        }
    }
}

void checkCollision(game_t *game)
{
    node_t *node = NULL;
    cube_t *temp = NULL;

    foreach(game->cube->head, node) {
        temp = (cube_t *)node->data;
        if (game->camera.position.x > temp->position.x - temp->width / 2 &&
            game->camera.position.x < temp->position.x + temp->width / 2 &&
            game->camera.position.z > temp->position.z - temp->length / 2 &&
            game->camera.position.z < temp->position.z + temp->length / 2)
            game->camera.position = game->cameraLastPosition;
        checkCollisionProjectile(game, temp);
    }
    checkCollisionItem(game);
}

void updateCollision(game_t *game)
{
    checkCollision(game);
}
