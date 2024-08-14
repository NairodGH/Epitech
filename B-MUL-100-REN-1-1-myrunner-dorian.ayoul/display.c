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
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "include/my_runner.h"

void create(game g, map *m, player p)
{
    char *path = malloc(9);

    path[0] = 'b', path[1] = 'g', path[2] = '/', path[3] = 'x',
    path[4] = '.', path[5] = 'p', path[6] = 'n', path[7] = 'g', path[8] = '\0';
    for (int i = 0; i != 16; i++) {
        path[3] = i / 2 + 48;
        m[i].sprite = sfSprite_create();
        m[i].t = sfTexture_createFromFile(path, NULL);
        sfSprite_setTexture(m[i].sprite, m[i].t, sfTrue);
        m[i].pos = (sfVector2f){(i % 2 == 0 ? 0 : 1280), 0};
        m[i].speed = (float)(i / 2) / 8;
    }
    free(path), sfSprite_setTexture(p.sprite, p.t, sfTrue);
    sfText_setFont(g.text, g.font), sfText_setColor(g.text, sfBlack);
    sfText_setOutlineColor(g.text, sfWhite);
    sfText_setOutlineThickness(g.text, 1.0);
    sfText_setCharacterSize(g.text, 50), sfSound_setBuffer(g.sound, g.buff);
    sfText_setPosition(g.text, (sfVector2f){1175, 0}), sfMusic_play(g.music);
}

player move(game g, map *m, player p)
{
    for (int i = 0; i != 16 + s(g, 2); i++) {
        m[i].pos.x -= m[i].speed;
        if (m[i].pos.x <= -1280 && i < 16) m[i].pos.x = 1280;
    }
    for (int i = 0; i != s(g, 0) * 2; i += 2) {
        if (m[16].h[i] >= 0 && m[16].pos.x < -m[16].h[i]
            && m[16].pos.x > -m[16].h[i + 1]) p.pos.y -= 1.0;
        if (m[16].h[i] < 0 && m[16].pos.x < m[16].h[i]
            && m[16].pos.x > m[16].h[i + 1]) p.pos.y += 1.0;
    }
    for (int i = 0; i != s(g, 1) * 2; i += 2) {
        if (m[16].pos.x < m[16].f[i] && m[16].pos.x > m[16].f[i + 1]
            && p.jump == 0) p.fall = 1;
    }
    if (p.jump == 1)
        p.pos.y -= g.sec < 0.375 ? (0.375 - g.sec) * 5 : -(g.sec - 0.375) * 5;
    if (p.fall == 1) p.pos.y += 2.0;
    if (p.pos.y > 720 - p.rec.height) sfRenderWindow_close(g.window);
    return (p);
}

player animations(game g, player p)
{
    if (p.fall == 0 && p.jump == 0)
        g.sec <= 0.1 ? p.rec.left = 0, p.rec.width = 38, p.rec.height = 43 :
        (p.rec.left = 38, p.rec.width = 42, p.rec.height = 45);
    if (g.sec > 0.2 && p.fall == 0 && p.jump == 0) sfClock_restart(g.clock);
    if (p.fall == 0 && p.jump == 1)
        g.sec <= 0.15 ? p.rec.left = 80, p.rec.width = 34, p.rec.height = 39 :
        g.sec <= 0.3 ? p.rec.left = 114, p.rec.width = 34, p.rec.height = 40 :
        g.sec <= 0.45 ? p.rec.left = 148, p.rec.width = 31, p.rec.height = 45 :
        g.sec <= 0.6 ? p.rec.left = 179, p.rec.width = 34, p.rec.height = 42 :
        (p.rec.left = 213, p.rec.width = 34, p.rec.height = 47);
    if (g.sec > 0.75 && p.fall == 0 && p.jump == 1)
        p.jump = 0, sfClock_restart(g.clock);
    return (p);
}

player display(game g, map *m, player p)
{
    char *score = malloc(4);

    sfRenderWindow_clear(g.window, sfWhite);
    for (int i = 0; i != 16 + s(g, 2); i++) {
        sfSprite_setPosition(m[i].sprite, m[i].pos);
        sfRenderWindow_drawSprite(g.window, m[i].sprite, NULL);
    }
    for (int i = 3, j = 0; i != -1; i--)
        j = g.score % 10, g.score = round(g.score / 10),
        score[i] = j + 48;
    sfText_setString(g.text, score);
    sfRenderWindow_drawText(g.window, g.text, NULL);
    if (m[16].pos.x > m[16].end) p = animations(g, p);
    sfSprite_setPosition(p.sprite, p.pos);
    sfSprite_setTextureRect(p.sprite, p.rec);
    sfRenderWindow_drawSprite(g.window, p.sprite, NULL);
    sfRenderWindow_display(g.window);
    free(score);
    return (p);
}

player end(game g, map *m, player p)
{
    if (g.sec < 0.2) sfSound_play(g.sound);
    if (g.sec < 1.0) p.pos.x += 0.3;
    if (g.sec > 1.0 && g.sec < 1.2)
        g.buff = sfSoundBuffer_createFromFile("water"),
        sfSound_setBuffer(g.sound, g.buff), sfSound_play(g.sound);
    if (g.sec > 1.2 && g.sec < 1.4) p.pos.y -= 0.4;
    g.sec <= 0.6 ? p.rec.left = 247, p.rec.width = 82, p.rec.height = 43 :
    g.sec <= 0.8 ? p.rec.left = 329, p.rec.width = 30, p.rec.height = 41 :
    g.sec <= 1.0 ? p.rec.left = 359, p.rec.width = 55, p.rec.height = 52 :
    g.sec <= 1.2 ? p.rec.left = 414, p.rec.width = 42, p.rec.height = 43 :
    g.sec <= 1.4 ? p.rec.left = 456, p.rec.width = 45, p.rec.height = 44 :
    g.sec <= 1.6 ? p.rec.left = 501, p.rec.width = 46, p.rec.height = 43 :
    g.sec <= 1.8 ? p.rec.left = 547, p.rec.width = 83, p.rec.height = 68 :
    (p.rec.left = 630, p.rec.width = 85, p.rec.height = 74);
    return (p);
}