/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** Header file containing
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    sfVideoMode dim;
    sfTexture* bg_t;
    sfRenderWindow* window;
    sfSprite* bg_s;
    sfMusic* m;
    sfText* text;
    sfFont* font;
    sfSound* sound;
    sfSoundBuffer* buff;
    int nb;
    int shot;
    int hit;
    int score;
    sfVector2i pos;
    sfEvent event;
} game;

typedef struct {
    sfSprite* s;
    sfIntRect rec;
    sfTexture* t;
    double speedx;
    double speedy;
    sfVector2f pos;
    bool flip;
    bool shot;
    sfClock* clock;
    sfTime time;
    double sec;
} duck;

typedef struct {
    sfSprite* s;
    sfTexture* t;
    sfIntRect rec;
    sfVector2f pos;
    sfClock* clock;
    sfTime time;
    double sec;
} hound;

hound intro(game g, hound h);
game move(game g, duck *d, double *save);
sfIntRect vertical(game g, duck d);
void display(game g, duck *d, hound h);
void end(game g, hound h);

#endif