#include "includes.h"

static cube_t *createWall(Vector3 pos, float width, float height, float length)
{
    cube_t *temp = calloc(1, sizeof(cube_t));

    temp->position = pos;
    temp->width = width;
    temp->height = height;
    temp->length = length;
    temp->texture = LoadTexture("resources/immeuble/immeuble2.png");
    return temp;
}

void initWall(game_t *game)
{
    list_push_data(game->cube, createWall((Vector3){ 0.0f, 0.0f, -(MAP_SIZE / 2) }, MAP_SIZE, 16.0f, 0.1f));
    list_push_data(game->cube, createWall((Vector3){ 0.0f, 0.0f, MAP_SIZE / 2 }, MAP_SIZE, 16.0f, 0.1f));
    list_push_data(game->cube, createWall((Vector3){ MAP_SIZE / 2, 0.0f, 0.0f }, 0.1f, 16.0f, MAP_SIZE));
    list_push_data(game->cube, createWall((Vector3){ -(MAP_SIZE / 2), 0.0f, 0.0f }, 0.1f, 16.0f, MAP_SIZE));
}

void initCube(game_t *game)
{
    cube_t *temp = NULL;
    char *line = NULL;
    size_t len = 0;
    int read;
    int i = 0;

    game->cube = list_create();
    #ifndef _WIN32
    FILE *file = fopen("assets/map/map.txt", "r");
    if (file == NULL) {
        printf("Error: can't open file map.txt\n");
        exit(84);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (line[j] == '-')
                continue;
            if (line[j] == 'X') {
                temp = calloc(1, sizeof(cube_t));
                temp->width = 1.0f;
                temp->length = 1.0f;
                temp->height = 16.0f;
                temp->position = (Vector3){(float)j - 16, temp->height/2.0f, (float)i -16};
                temp->texture = LoadTexture("resources/immeuble/immeuble4.png");
                list_push_data(game->cube, temp);
            }
            if (line[j] == 'R') {
                createAmmoBox(game, (Vector3){(float)j - 16, 0.0f, (float)i -16});
            }
        }
        i++;
    }
    #else
    for (int i = 0; i < OBS_NBR; i++) {
        temp = calloc(1, sizeof(cube_t));
        temp->width = 2.0f;
        temp->length = 2.0f;
        temp->height = (float)GetRandomValue(8, 12);
        temp->position = (Vector3){(float)GetRandomValue(-15, 15), temp->height/2.0f, (float)GetRandomValue(-15, 15)};
        temp->texture = LoadTexture("resources/immeuble/immeuble3.png");
        list_push_data(game->cube, temp);
    }
    #endif
}
