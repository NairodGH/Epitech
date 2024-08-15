/*
** EPITECH PROJECT, 2020
** my_defender.c
** File description:
** main (g b t variables filling/allocation), game loop and menu (buttons)
*/

#include "my.h"
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

void volume(game g)
{
    if (g.pos.x < 84 && g.pos.x > 0 && g.pos.y < 65 && g.pos.y > 0 &&
        g.event.mouseButton.button == sfMouseLeft)
        for (int i = 0; i != 34 && sfSound_getVolume(g.s[i]) - 10 > 0; i++)
            sfSound_setVolume(g.s[i], sfSound_getVolume(g.s[i]) - 10);
    if (g.pos.x < 84 && g.pos.x > 0 && g.pos.y < 65 && g.pos.y > 0 &&
        g.event.mouseButton.button == sfMouseRight)
        for (int i = 0; i != 34 && sfSound_getVolume(g.s[i]) + 10 < 100; i++)
            sfSound_setVolume(g.s[i], sfSound_getVolume(g.s[i]) + 10);
    if (g.pos.x < 162 && g.pos.x > 84 && g.pos.y < 65 && g.pos.y > 0) {
        if (sfSound_getVolume(g.s[0]) == 0) {
            sfSound_setVolume(g.s[0], sfSound_getVolume(g.s[1]));
            sfSound_setVolume(g.s[2], sfSound_getVolume(g.s[1]));
        }
        else {
            sfSound_setVolume(g.s[0], 0);
            sfSound_setVolume(g.s[2], 0);
        }
    }
}

game menu(game g)
{
    volume(g);
    if (g.pos.x < 500 && g.pos.x > 290 && g.pos.y < 490 && g.pos.y > 410) {
        g.started = true;
        sfSound_stop(g.s[0]);
        sfSound_play(g.s[1]);
        sfSound_play(g.s[2]);
        g.bg_texture = sfTexture_createFromFile("scenes/map.png", NULL);
        sfSprite_setTexture(g.bg_sprite, g.bg_texture, sfTrue);
    }
    if (g.pos.x < 47 && g.pos.x > 0 && g.pos.y < 600 && g.pos.y > 562)
        sfRenderWindow_close(g.window);
    return (g);
}

game event(game g, button *b, tower *t)
{
    while (sfRenderWindow_pollEvent(g.window, &g.event)) {
        if (g.event.type == sfEvtClosed)
            sfRenderWindow_close(g.window);
        if (g.event.type == sfEvtMouseButtonPressed)
            g = click(g, b, t);
        if (g.event.type == sfEvtKeyPressed && g.started &&
        g.event.key.code == sfKeyEscape) {
            g = clock_pause(g, t);
            g.paused = !g.paused;
        }
    }
    return (g);
}

void loop(game g, button *b, tower *t)
{
    list_t *npcs = NULL;
    sfClock *clock = sfClock_create();
    add_ennemies(&npcs, 30, 1, clock);
    for (sfSound_play(g.s[0]); sfRenderWindow_isOpen(g.window);) {
        g.pos = sfMouse_getPositionRenderWindow(g.window);
        g = event(g, b, t);
        for (int i = 0; i != 8 && g.paused == 0; i++) {
            t[i].time = sfClock_getElapsedTime(t[i].clock);
            t[i].sec = (t[i].time.microseconds + t[i].pause) / 1000000.0;
            srand(t[i].sec);
        }
        display(g, b, t, npcs), is_hit(npcs, t), is_dead(&npcs, &g);
        if (g.hp == 0 || !npcs) {
            get_end_msg(g, npcs), sfRenderWindow_close(g.window);
            return;
        }
    }
    for (int i = 0; i != 34; i++) {
        sfSoundBuffer_destroy(sfSound_getBuffer(g.s[i]));
        sfSound_destroy(g.s[i]);
    }
}

int main(int ac, char **av)
{
    game g = {{800, 600, 32},
        sfRenderWindow_create(g.dim, "Kingdom Rush", sfDefaultStyle, NULL),
        sfImage_createFromFile("icon"), 0,
        sfSprite_create(), sfTexture_createFromFile("scenes/menu.png", NULL),
        0, sfSprite_create(), sfTexture_createFromFile("sprites/pause.png",
        NULL), malloc(sizeof(sfSound*) * 34), 999, 10, sfText_create(),
        sfFont_createFromFile("font.ttf")};
    button *b = malloc(sizeof(button) * 126);
    tower *t = malloc(sizeof(tower) * 8);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return help();

    create(g, b, t);
    loop(g, b, t);
    return (0);
}