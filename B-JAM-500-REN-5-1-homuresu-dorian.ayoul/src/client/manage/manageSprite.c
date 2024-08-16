#include "includes.h"

typedef struct {
    spriteName_t name;
    char *path;
} namePath_t;

static const namePath_t namePath[] = {
    {CROSSHAIR, "assets/sprites/crosshair.png"},
};

sprite_t *findSpriteByName(game_t *game, spriteName_t name)
{
    node_t *node = NULL;
    sprite_t *temp = NULL;

    foreach(game->sprite->head, node) {
        temp = (sprite_t *)node->data;
        for (size_t i = 0; i < sizeof(namePath) / sizeof(namePath[0]); i++) {
            if (namePath[i].name == name)
                return temp;
        }
    }
    return NULL;
}

void setupSprite(game_t *game, spriteName_t name, Vector2 position, Vector2 size, float scale, Color tint)
{
    sprite_t *crosshair = findSpriteByName(game, name);

    crosshair->texture = LoadTexture(crosshair->name);
    crosshair->texture.width = size.x;
    crosshair->texture.height = size.y;
    crosshair->origin = (Vector2){crosshair->texture.width / 2, crosshair->texture.height / 2};
    crosshair->position = (Vector2){position.x - crosshair->origin.x, position.y - crosshair->origin.y};
    crosshair->scale = 1;
    crosshair->tint = tint;
}