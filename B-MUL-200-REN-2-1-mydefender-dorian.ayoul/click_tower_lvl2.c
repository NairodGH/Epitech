/*
** EPITECH PROJECT, 2020
** click_tower_lvl2.c
** File description:
** level 2 tower click related functions
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

void menu_open_close_lvl3(game g, button *b, tower *t, int i)
{
    if (g.pos.x < t[i].pos.x + t[i].rec.width && g.pos.x > t[i].pos.x
    && g.pos.y < t[i].pos.y + t[i].rec.height && g.pos.y > t[i].pos.y
    && t[i].stage == 5) {
        t[i].stage = 6;
        sfSound_play(g.s[3]);
    }
    if ((g.pos.x > t[i].pos.x + t[i].rec.width || g.pos.x < t[i].pos.x
    || g.pos.y > t[i].pos.y + t[i].rec.height || g.pos.y < t[i].pos.y)
    && t[i].stage == 6) {
        t[i].stage = 5;
        sfSound_play(g.s[17]);
    }
}

game lvl2_sell(game g, button *b, tower *t, int i)
{
    if (g.pos.x < t[i].pos.x + 40 && g.pos.x > t[i].pos.x + 10
    && g.pos.y < t[i].pos.y + 67 && g.pos.y > t[i].pos.y + 40) {
        if (t[i].rec.left == 205 || t[i].rec.left == 430)
            g.gold += 50;
        if (t[i].rec.left == 657)
            g.gold += 80;
        if (t[i].rec.left == 876)
            g.gold += 100;
        t[i].stage = 0;
        sfSound_play(g.s[30]);
        b[101 + i].rec.left = 2600;
    }
    return (g);
}

game lvl3_menu(game g, button *b, tower *t, int i)
{
    if (g.pos.x < t[i].pos.x + 40 && g.pos.x > t[i].pos.x + 10
    && g.pos.y < t[i].pos.y + 67 && g.pos.y > t[i].pos.y + 40) {
        if (t[i].rec.left == 280 || t[i].rec.left == 511)
            g.gold += 120;
        if (t[i].rec.left == 730)
            g.gold += 220;
        if (t[i].rec.left == 1460)
            g.gold += 280;
        t[i].pos.y += 20;
        sfSprite_setPosition(t[i].sprite, t[i].pos);
        t[i].stage = 0;
        sfSound_play(g.s[30]);
        b[101 + i].rec.left = 2600;
    }
    return (g);
}

game mage_lvl2_tesla(game g, button *b, tower *t, int i)
{
    if (t[i].rec.left == 657 && g.gold >= 160) {
        g.gold -= 160;
        t[i].stage = 5;
        t[i].pos.y -= 20;
        sfSprite_setPosition(t[i].sprite, t[i].pos);
        t[i].rec.left = 730;
        quotes(g, t, i, rand() % 3);
        b[101 + i].rec.left += 400;
    }
    if (t[i].rec.left == 876 && g.gold >= 220) {
        g.gold -= 220;
        t[i].stage = 5;
        t[i].pos.y -= 20;
        sfSprite_setPosition(t[i].sprite, t[i].pos);
        t[i].rec.left = 1460;
        quotes(g, t, i, rand() % 3);
        b[101 + i].rec.left += 200;
    }
    return (g);
}

game lvl2_menu(game g, button *b, tower *t, int i)
{
    if (g.pos.x < b[60 + i].pos.x + 44 && g.pos.x > b[60 + i].pos.x
    && g.pos.y < b[60 + i].pos.y + 40 && g.pos.y > b[60 + i].pos.y) {
        if ((t[i].rec.left == 205 || t[i].rec.left == 430) && g.gold >= 110) {
            g.gold -= 110;
            t[i].stage = 5;
            t[i].pos.y -= 20;
            sfSprite_setPosition(t[i].sprite, t[i].pos);
            t[i].rec.left = (t[i].rec.left == 205 ? 280 : 511);
            quotes(g, t, i, rand() % 3);
            b[101 + i].rec.left += 600;
        }
        g = mage_lvl2_tesla(g, b, t, i);
    }
    g = lvl2_sell(g, b, t, i);
    return (g);
}