/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** initialisation functions for variables and sprite positionning
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "include/my_defender.h"

void ui_pos(button *b, tower *t)
{
    b[125].pos = (sfVector2f){307, 414};
    for (int i = 0; i != 8; i++) {
        b[60 + i].pos = (sfVector2f){t[i].pos.x + 10, t[i].pos.y - 60};
        b[68 + i].pos = (sfVector2f){t[i].pos.x + 62, t[i].pos.y - 8};
        b[76 + i].pos = (sfVector2f){t[i].pos.x - 40, t[i].pos.y - 8};
        b[84 + i].pos = (sfVector2f){t[i].pos.x + 10, t[i].pos.y + 39};
        b[92 + i].pos = (sfVector2f){t[i].pos.x + 10, t[i].pos.y - 60};
        b[101 + i].pos = (sfVector2f){t[i].pos.x - 40, t[i].pos.y - 60};
        b[109 + i].pos = (sfVector2f){t[i].pos.x, t[i].pos.y - 20};
        b[117 + i].pos = (sfVector2f){t[i].pos.x + 2, t[i].pos.y - 18};
    }
}

void spritesheet(button *b, int i)
{
    if (i > 28 && i < 58) b[i].rec.left = 200;
    if (i == 58) b[i].rec.left = 400;
    if (i == 59) b[i].rec.left = 600;
    if (i > 59 && i < 68) b[i].rec.left = 800;
    if (i > 67 && i < 76) b[i].rec.left = 1000;
    if (i > 75 && i < 84) b[i].rec.left = 1200;
    if (i > 83 && i < 92) b[i].rec.left = 1400;
    if (i > 91 && i < 100) b[i].rec.left = 1600;
    if (i == 100) b[i].rec.left = 2200;
    if (i > 100 && i < 109) b[i].rec.left = 2600;
    if (i > 108 && i < 117) b[i].rec.left = 3600;
    if (i > 116 && i < 125) b[i].rec.left = 3800;
    if (i == 125) b[i].rec.left = 4000;
}

void create_ui(button *b, tower *t)
{
    ui_pos(b, t);
    for (int i = 0; i != 126; i++) {
        b[i].sprite = sfSprite_create();
        b[i].rec = (sfIntRect){0, 0, 200, 157};
        b[i].texture = sfTexture_createFromFile("sprites/UI.png", NULL);
        sfSprite_setTexture(b[i].sprite, b[i].texture, sfTrue);
        spritesheet(b, i);
        sfSprite_setPosition(b[i].sprite, b[i].pos);
        sfSprite_setTextureRect(b[i].sprite, b[i].rec);
    }
}

void create_tower(tower *t)
{
    t[0].pos = (sfVector2f){240, 170};
    t[1].pos = (sfVector2f){180, 190};
    t[2].pos = (sfVector2f){250, 290};
    t[3].pos = (sfVector2f){250, 350};
    t[4].pos = (sfVector2f){325, 350};
    t[5].pos = (sfVector2f){400, 450};
    t[6].pos = (sfVector2f){500, 360};
    t[7].pos = (sfVector2f){630, 420};
    for (int i = 0; i != 8; i++) {
        t[i].sprite = sfSprite_create();
        t[i].rec = (sfIntRect){0, 0, 73, 70};
        t[i].texture = sfTexture_createFromFile("sprites/towers.png", NULL);
        sfSprite_setTexture(t[i].sprite, t[i].texture, sfTrue);
        sfSprite_setTextureRect(t[i].sprite, t[i].rec);
        sfSprite_setPosition(t[i].sprite, t[i].pos);
        t[i].stage = 0;
        t[i].clock = sfClock_create();
        t[i].cd = sfClock_create();
        t[i].pause = 0;
    }
}

void create(game g, button *b, tower *t)
{
    char *path = malloc(9);

    lib("sounds/x", path, 0);
    for (int i = 0; i != 34; i++) {
        g.s[i] = sfSound_create();
        path[7] = i + 48;
        sfSound_setBuffer(g.s[i], sfSoundBuffer_createFromFile(path));
    }
    sfSound_setLoop(g.s[0], 1);
    sfSound_setLoop(g.s[2], 1);
    free(path);
    sfRenderWindow_setKeyRepeatEnabled(g.window, 0);
    create_tower(t);
    create_ui(b, t);
    sfRenderWindow_setIcon(g.window, 256, 256, sfImage_getPixelsPtr(g.icon));
    sfSprite_setTexture(g.bg_sprite, g.bg_texture, sfTrue);
    sfSprite_setTexture(g.menu_sprite, g.menu_texture, sfTrue);
    sfText_setFont(g.text, g.font);
    sfText_setCharacterSize(g.text, 20);
}