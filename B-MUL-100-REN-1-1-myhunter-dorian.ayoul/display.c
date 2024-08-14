/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display-related functions
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "include/my_hunter.h"

void randomizer(game g, duck *d, double *save, int i)
{
    if ((rand() % 5000 == 0 && d[i].speedx != 0 && !d[i].shot)
        || d[i].pos.x < 0 || d[i].pos.x > g.dim.width - d[i].rec.width)
        d[i].speedx *= -1, d[i].flip = !d[i].flip;
    if (rand() % 10000 == 0 && d[i].speedx != 0 && d[i].speedy != 0
        && !d[i].shot)
        save[i] = d[i].speedx, d[i].speedx = 0;
    if (rand() % 10000 == 0 && d[i].speedx != 0 && d[i].speedy != 0
        && !d[i].shot)
        save[i] = d[i].speedy, d[i].speedy = 0;
    if (rand() % 5000 == 0 && (d[i].speedx == 0 || d[i].speedy == 0)
        && !d[i].shot) {
        if (d[i].speedx == 0) d[i].speedx = save[i];
        else d[i].speedy = save[i];
    }
}

game move(game g, duck *d, double *save)
{
    for (int i = 0; i != g.nb; i++) {
        d[i].pos.x += d[i].speedx, d[i].pos.y -= d[i].speedy;
        randomizer(g, d, save, i);
        if (!d[i].shot && g.event.type == sfEvtMouseButtonPressed &&
            g.event.mouseButton.button == sfMouseLeft && g.pos.x >= d[i].pos.x
            && g.pos.x <= d[i].pos.x + d[i].rec.width && g.pos.y >= d[i].pos.y
            && g.pos.y <= d[i].pos.y + d[i].rec.height && d[i].pos.y < 410)
            d[i].shot = true, d[i].speedx = 0, d[i].speedy = -0.1, g.hit++,
            g.score += d[i].rec.left < 626 ? 500 : d[i].rec.left < 1252 ? 1000 :
            1500, sfClock_restart(d[i].clock);
        if (!d[i].shot && d[i].sec > 0.3) sfClock_restart(d[i].clock);
        d[i].rec = vertical(g, d[i]);
        if (d[i].flip) d[i].rec.left += 313;
    }
    return (g);
}

void text(game g)
{
    char shot[2];
    char hit[2];
    char score[7];

    for (int i = 1, j = 0; i != -1; i--)
        j = g.shot % 10, g.shot = round(g.shot / 10), shot[i] = j + 48;
    sfText_setPosition(g.text, (sfVector2f){100, 510}), shot[2] = '\0';
    sfText_setString(g.text, shot);
    sfRenderWindow_drawText(g.window, g.text, NULL);
    for (int i = 1, j = 0; i != -1; i--)
        j = g.hit % 10, g.hit = round(g.hit / 10), hit[i] = j + 48;
    sfText_setPosition(g.text, (sfVector2f){335, 510}), hit[2] = '\0';
    sfText_setString(g.text, hit);
    sfRenderWindow_drawText(g.window, g.text, NULL);
    for (int i = 5, j = 0; i != -1; i--)
        j = g.score % 10, g.score = round(g.score / 10), score[i] = j + 48;
    sfText_setPosition(g.text, (sfVector2f){602, 508}), score[6] = '\0';
    sfText_setString(g.text, score);
    sfRenderWindow_drawText(g.window, g.text, NULL);
}

void display(game g, duck *d, hound h)
{
    sfRenderWindow_clear(g.window, sfCyan);
    for (int i = 0; i != g.nb; i++) {
        sfSprite_setPosition(d[i].s, d[i].pos);
        sfSprite_setTextureRect(d[i].s, d[i].rec);
        sfRenderWindow_drawSprite(g.window, d[i].s, NULL);
    }
    sfSprite_setPosition(h.s, h.pos);
    sfSprite_setTextureRect(h.s, h.rec);
    if (h.sec > 2.1) sfRenderWindow_drawSprite(g.window, h.s, NULL);
    sfRenderWindow_drawSprite(g.window, g.bg_s, NULL);
    if (h.sec < 2.1) sfRenderWindow_drawSprite(g.window, h.s, NULL);
    text(g);
    sfRenderWindow_display(g.window);
}

void end(game g, hound h)
{
    sfSprite* result = sfSprite_create();
    sfTexture* t = sfTexture_createFromFile("sheet.png", NULL);
    sfMusic* music = sfMusic_createFromFile("end");

    sfSprite_setTexture(result, t, sfTrue), sfClock_restart(h.clock);
    sfSprite_setPosition(result, (sfVector2f){276, 277}), h.sec = 0;
    sfText_setCharacterSize(g.text, 40), sfMusic_setVolume(music, 10);
    sfSprite_setTextureRect(result, (sfIntRect){2262, 0, 258, 46});
    sfText_setPosition(g.text, (sfVector2f){327, 275});
    sfRenderWindow_drawSprite(g.window, result, NULL);
    sfRenderWindow_drawText(g.window, g.text, NULL), sfMusic_play(music);
    sfRenderWindow_display(g.window), sfMusic_stop(g.m);
    while (h.sec < 7 && sfRenderWindow_isOpen(g.window)) {
        h.time = sfClock_getElapsedTime(h.clock),
        h.sec = h.time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(g.window, &g.event))
            if (g.event.type == sfEvtClosed) sfRenderWindow_close(g.window);
    }
    sfSprite_destroy(result), sfMusic_destroy(music), sfTexture_destroy(t);
}