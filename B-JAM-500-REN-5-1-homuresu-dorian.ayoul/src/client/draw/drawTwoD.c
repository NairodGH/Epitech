#include "includes.h"

void drawSpriteTwoD(game_t *game)
{
    node_t *node = NULL;
    sprite_t *temp = NULL;

    foreach(game->sprite->head, node) {
        temp = (sprite_t *)node->data;
        DrawTextureEx(temp->texture, temp->position, 0, temp->scale, temp->tint);
    }
}

void drawTextTwoD(game_t *game)
{
    char ammo[10] = "Ammo: ";
    char life[10] = "Life: ";
    char score[12] = "Score: ";
    int y = 20;
    int c = 0;
    player_t *temp = NULL;
    node_t *node = NULL;
    Color color[8] = {RED, GREEN, YELLOW, PURPLE, ORANGE, PINK, BLACK, BROWN};

    sprintf(ammo, "%s%d", ammo, game->stat->ammo);
    sprintf(life, "%s%d", life, game->stat->life);
    sprintf(score, "%s%d", score, game->stat->score);
    DrawText(ammo, 10, y, 40, BLUE);
    DrawText(life, 10, y + 50, 40, BLUE);
    DrawText(score, 10, y + 100, 40, BLUE);
    y += 200;
    foreach(game->player->head, node) {
        memset(life, 0, 10);
        memset(score, 0, 12);
        temp = (player_t *)node->data;
        if (temp->isAlive == false)
            continue;
        sprintf(life, "%s%d", "Life: ", temp->stat.life);
        sprintf(score, "%s%d", "Score: ", temp->stat.score);
        DrawText(life, 10, y, 40, color[c]);
        DrawText(score, 10, y + 50, 40, color[c]);
        y += 100;
        c++;
    }
}