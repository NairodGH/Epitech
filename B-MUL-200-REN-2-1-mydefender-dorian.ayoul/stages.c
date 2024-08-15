/*
** EPITECH PROJECT, 2020
** stages.c
** File description:
** stages-related functions
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

void lvl1_buttons_build_bar(game g, button *b, tower *t)
{
    for (int i = 0; i != 8; i++) {
        if (t[i].stage == 1) {
            sfSprite_setTextureRect(b[101 + i].sprite, b[101 + i].rec);
            sfRenderWindow_drawSprite(g.window, b[101 + i].sprite, NULL);
        }
        if (t[i].stage == 1 && g.gold >= 70) {
            sfRenderWindow_drawSprite(g.window, b[60 + i].sprite, NULL);
            sfRenderWindow_drawSprite(g.window, b[68 + i].sprite, NULL);
        }
        if (t[i].stage == 1 && g.gold >= 100)
            sfRenderWindow_drawSprite(g.window, b[76 + i].sprite, NULL);
        if (t[i].stage == 1 && g.gold >= 125)
            sfRenderWindow_drawSprite(g.window, b[84 + i].sprite, NULL);
        if (t[i].stage == 2) {
            b[117 + i].rec.width = t[i].sec * 63;
            sfSprite_setTextureRect(b[117 + i].sprite, b[117 + i].rec);
            sfRenderWindow_drawSprite(g.window, b[109 + i].sprite, NULL);
            sfRenderWindow_drawSprite(g.window, b[117 + i].sprite, NULL);
        }
    }
}

void quotes(game g, tower *t, int i, int random_number)
{
    if (t[i].rec.left < 342) {
        if (random_number == 0) sfSound_play(g.s[5]);
        if (random_number == 1) sfSound_play(g.s[6]);
        if (random_number == 2) sfSound_play(g.s[7]);
    }
    if (t[i].rec.left >= 342 && t[i].rec.left < 578) {
        if (random_number == 0) sfSound_play(g.s[8]);
        if (random_number == 1) sfSound_play(g.s[9]);
        if (random_number == 2) sfSound_play(g.s[10]);
    }
    if (t[i].rec.left >= 578 && t[i].rec.left < 798) {
        if (random_number == 0) sfSound_play(g.s[11]);
        if (random_number == 1) sfSound_play(g.s[12]);
        if (random_number == 2) sfSound_play(g.s[13]);
    }
    if (t[i].rec.left >= 798) {
        if (random_number == 0) sfSound_play(g.s[14]);
        if (random_number == 1) sfSound_play(g.s[15]);
        if (random_number == 2) sfSound_play(g.s[16]);
    }
}

void upgrade_button(game g, button *b, tower *t, int i)
{
    if (t[i].stage == 4 && t[i].rec.left < 578 && g.gold >= 110) {
        b[92 + i].rec.left = 1600;
        sfSprite_setTextureRect(b[92 + i].sprite, b[92 + i].rec);
        sfRenderWindow_drawSprite(g.window, b[92 + i].sprite, NULL);
    }
    if (t[i].stage == 4 && t[i].rec.left > 577 && t[i].rec.left < 798
    && g.gold >= 160) {
        b[92 + i].rec.left = 1800;
        sfSprite_setTextureRect(b[92 + i].sprite, b[92 + i].rec);
        sfRenderWindow_drawSprite(g.window, b[92 + i].sprite, NULL);
    }
    if (t[i].stage == 4 && t[i].rec.left > 797 && g.gold >= 220) {
        b[92 + i].rec.left = 2000;
        sfSprite_setTextureRect(b[92 + i].sprite, b[92 + i].rec);
        sfRenderWindow_drawSprite(g.window, b[92 + i].sprite, NULL);
    }
}

void lvl2_quotes_menu(game g, button *b, tower *t)
{
    for (int i = 0; i != 8; i++) {
        if (t[i].stage == 2 && t[i].sec > 1) {
            quotes(g, t, i, rand() % 3);
            t[i].stage = 3;
        }
        if (t[i].stage == 3 && t[i].rec.left < 342)
            t[i].rec.left = 205;
        if (t[i].stage == 3 && t[i].rec.left > 341 && t[i].rec.left < 578)
            t[i].rec.left = 430;
        if (t[i].stage == 3 && t[i].rec.left > 577 && t[i].rec.left < 798)
            t[i].rec.left = 657;
        if (t[i].stage == 3 && t[i].rec.left > 797)
            t[i].rec.left = 876;
        if (t[i].stage == 4) {
            sfSprite_setTextureRect(b[101 + i].sprite, b[101 + i].rec);
            sfRenderWindow_drawSprite(g.window, b[101 + i].sprite, NULL);
        }
        upgrade_button(g, b, t, i);
    }
}

void lvl3_display(game g, button *b, tower *t)
{
    for (int i = 0; i != 8; i++) {
        if (t[i].stage == 6) {
            sfSprite_setTextureRect(b[101 + i].sprite, b[101 + i].rec);
            sfRenderWindow_drawSprite(g.window, b[101 + i].sprite, NULL);
        }
    }
}