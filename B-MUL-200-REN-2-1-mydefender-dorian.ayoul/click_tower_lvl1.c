/*
** EPITECH PROJECT, 2020
** click_tower_lvl1.c
** File description:
** level 1 tower click related functions
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

game create_mortar_lvl1(game g, button *b, tower *t, int i)
{
    if (g.pos.x < b[84 + i].pos.x + 44 && g.pos.x > b[84 + i].pos.x
    && g.pos.y < b[84 + i].pos.y + 40 && g.pos.y > b[84 + i].pos.y
    && g.gold >= 125) {
        g.gold -= 125;
        t[i].stage = 2;
        sfClock_restart(t[i].clock);
        t[i].pause = 0;
        t[i].rec.left = 798;
        sfSound_play(g.s[4]);
        b[101 + i].rec.left += 585;
    }
    return (g);
}

game create_mage_lvl1(game g, button *b, tower *t, int i)
{
    if (g.pos.x < b[76 + i].pos.x + 44 && g.pos.x > b[76 + i].pos.x
    && g.pos.y < b[76 + i].pos.y + 40 && g.pos.y > b[76 + i].pos.y
    && g.gold >= 100) {
        g.gold -= 100;
        t[i].stage = 2;
        sfClock_restart(t[i].clock);
        t[i].pause = 0;
        t[i].rec.left = 578;
        sfSound_play(g.s[4]);
        b[101 + i].rec.left += 385;
    }
    g = create_mortar_lvl1(g, b, t, i);
    return (g);
}

game create_knight_lvl1(game g, button *b, tower *t, int i)
{
    if (g.pos.x < b[68 + i].pos.x + 44 && g.pos.x > b[68 + i].pos.x
    && g.pos.y < b[68 + i].pos.y + 40 && g.pos.y > b[68 + i].pos.y
    && g.gold >= 70) {
        g.gold -= 70;
        t[i].stage = 2;
        sfClock_restart(t[i].clock);
        t[i].pause = 0;
        t[i].rec.left = 355;
        sfSound_play(g.s[4]);
        b[101 + i].rec.left += 185;
    }
    g = create_mage_lvl1(g, b, t, i);
    return (g);
}

game lvl1_menu(game g, button *b, tower *t, int i)
{
    if (g.pos.x < b[60 + i].pos.x + 44 && g.pos.x > b[60 + i].pos.x
    && g.pos.y < b[60 + i].pos.y + 40 && g.pos.y > b[60 + i].pos.y
    && g.gold >= 70) {
        g.gold -= 70;
        t[i].stage = 2;
        sfClock_restart(t[i].clock);
        t[i].pause = 0;
        t[i].rec.left = 141;
        sfSound_play(g.s[4]);
        b[101 + i].rec.left += 185;
    }
    g = create_knight_lvl1(g, b, t, i);
    return (g);
}