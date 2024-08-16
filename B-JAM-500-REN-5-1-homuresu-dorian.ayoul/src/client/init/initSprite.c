#include "includes.h"

static char *spritePath[] = {"assets/sprites/crosshair.png",};

void initSprite(game_t *game)
{
    game->sprite = list_create();

    sprite_t *temp =NULL;

    for (size_t i = 0; i < sizeof(spritePath) / sizeof(spritePath[0]); i++) {
        temp = calloc(1, sizeof(sprite_t));
        temp->texture = LoadTexture(spritePath[i]);
        temp->position = (Vector2){0, 0};
        temp->origin = (Vector2){0, 0};
        temp->tint = WHITE;
        temp->name = strdup(spritePath[i]);
        list_push_data(game->sprite, temp);
    }
    setupSprite(game, CROSSHAIR, (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2}, (Vector2){32, 32}, 1, BLACK);
}
