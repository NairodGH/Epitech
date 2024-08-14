/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** header
*/

#ifndef MY_RUNNER_H
#define MY_RUNNER_H

#include <stdbool.h>

typedef struct{
    char *path;
    sfVideoMode dim;
    sfSound* sound;
    sfRenderWindow* window;
    sfClock* clock;
    sfMusic* music;
    sfText* text;
    sfFont* font;
    sfSoundBuffer* buff;
    int score;
    sfTime time;
    float sec;
    sfEvent event;
} game;

typedef struct{
    sfSprite* sprite;
    sfTexture* t;
    sfVector2f pos;
    float speed;
    int *h;
    int *f;
    int end;
} map;

typedef struct{
    sfSprite* sprite;
    sfTexture* t;
    sfVector2f pos;
    sfIntRect rec;
    bool jump;
    bool fall;
} player;

int error(int ac, char **av);
void create(game g, map *m, player p);
player move(game g, map *m, player p);
player display(game g, map *m, player p);
player end(game g, map *m, player p);
int s(game g, int mode);

#endif