/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** click-related functions
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

void menu_open_close_lvl1_lvl2(game g, button *b, tower *t, int i)
{
    if (t[i].rec.left == 0 && t[i].stage == 1) {
        t[i].stage = 0;
        sfSound_play(g.s[17]);
    }
    if (t[i].rec.left == 73 && t[i].stage == 0) {
        t[i].stage = 1;
        sfSound_play(g.s[3]);
    }
    if (g.pos.x < t[i].pos.x + t[i].rec.width && g.pos.x > t[i].pos.x
    && g.pos.y < t[i].pos.y + t[i].rec.height && g.pos.y > t[i].pos.y
    && t[i].stage == 3) {
        t[i].stage = 4;
        sfSound_play(g.s[3]);
    }
    if ((g.pos.x > t[i].pos.x + t[i].rec.width || g.pos.x < t[i].pos.x
    || g.pos.y > t[i].pos.y + t[i].rec.height || g.pos.y < t[i].pos.y)
    && t[i].stage == 4) {
        t[i].stage = 3;
        sfSound_play(g.s[17]);
    }
}

game clock_pause(game g, tower *t)
{
    for (int i = 0; i != 8; i++) {
        if (!g.paused)
            t[i].pause += t[i].time.microseconds;
        if (g.paused)
            sfClock_restart(t[i].clock);
    }
    for (int i = 0; i != 34; i++) {
        if (!g.paused && sfSound_getStatus(g.s[i]) == sfPlaying)
            sfSound_pause(g.s[i]);
        if (g.paused && sfSound_getStatus(g.s[i]) == sfPaused)
            sfSound_play(g.s[i]);
    }
    return (g);
}

game restart(game g, tower *t)
{
    g.started = 0;
    g.paused = 0;
    g.gold = 999;
    g.hp = 10;
    for (int i = 0; i != 8; i++) {
        t[i].stage = 0;
        t[i].pause = 0;
    }
    for (int i = 0; i != 34; i++)
        sfSound_stop(g.s[i]);
    sfSound_play(g.s[0]);
    sfSound_play(g.s[1]);
    g.bg_texture = sfTexture_createFromFile("scenes/menu.png", NULL);
    sfSprite_setTexture(g.bg_sprite, g.bg_texture, sfTrue);
    return (g);
}

game pause_check(game g, tower *t)
{
    if (g.pos.x > 764 && g.pos.y < 30) {
        g = clock_pause(g, t);
        g.paused = !g.paused;
    }
    if (g.pos.x < 488 && g.pos.x > 311 && g.pos.y < 205 && g.pos.y > 155
    && g.paused) {
        g = clock_pause(g, t);
        g.paused = !g.paused;
    }
    if (g.pos.x < 488 && g.pos.x > 311 && g.pos.y < 265 && g.pos.y > 215
        && g.paused)
        sfRenderWindow_close(g.window);
    if (g.pos.x < 488 && g.pos.x > 311 && g.pos.y < 325 && g.pos.y > 275
        && g.paused)
        g = restart(g, t);
    return (g);
}

game click(game g, button *b, tower *t)
{
    if (!g.started)
        return (menu(g));
    g = pause_check(g, t);
    for (int i = 0; i != 8 && !g.paused; i++) {
        if (t[i].stage == 1)
            g = lvl1_menu(g, b, t, i);
        if (t[i].stage == 4)
            g = lvl2_menu(g, b, t, i);
        if (t[i].stage == 6)
            g = lvl3_menu(g, b, t, i);
        menu_open_close_lvl1_lvl2(g, b, t, i);
        menu_open_close_lvl3(g, b, t, i);
    }
    return (g);
}