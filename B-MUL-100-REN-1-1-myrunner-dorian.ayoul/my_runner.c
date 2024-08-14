/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** gotta go fast
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

int s(game g, int mode)
{
    int fd = open(g.path, O_RDONLY);
    char b[4096];
    int ret = read(fd, b, 4096);
    int n = 0;

    for (int i = 0; !(b[i] == '\n' && b[i + 1] == '\n') && fd != -1; i++) {
        if (mode == 0) (b[i] == '^' || b[i] == 'v') && (n++);
        if (mode == 1) (b[i] == '!') && (n++);
        if (mode == 2)
            (47 < b[i] && b[i] < 58 || b[i] == '<' || b[i] == '>') && (n++);
        if (mode == 3) (b[i + 1] == '\n') && (n++);
        if (mode == 4)
            n++, (b[i + 1] == '\n' && b[i + 2] == '\n') && (n /= s(g, 3), n++);
        if (mode == 5) n++, (b[i + 1] == 10 && b[i + 2] == '\n') && (n++);
    }
    close(fd);
    return (n);
}

player mapping(game g, char b[4096], map *m, player p)
{
    char *path = malloc(8);

    path[0] = 'a', path[1] = 's', path[2] = 's', path[3] = 'e', path[4] = 't';
    path[5] = 's', path[6] = '/';
    for (int i = s(g, 5) - s(g, 4), j = 16; i >= s(g, 4) * 2; i++) {
        if (47 < b[i] && b[i] < 58 || b[i] == '<' || b[i] == '>') {
            m[j].sprite = sfSprite_create();
            path[7] = b[i], m[j].t = sfTexture_createFromFile(path, NULL);
            sfSprite_setTexture(m[j].sprite, m[j].t, sfTrue);
            m[j].pos = (sfVector2f){(s(g, 4) * ceil((s(g, 5) - i) /
            (double)s(g, 4)) - (s(g, 5) - i)) * 128,
            720 - ceil((s(g, 5) - i) / (double)s(g, 4)) * 128};
            m[j].speed = 1.0, j++;
        }
        if (b[i] == '\n') i -= s(g, 4) * 2;
    }
    for (int i = s(g, 4) * 2; !(b[i] == '\n' && b[i + 1] == '\n'); i++)
        if (b[i] == '@')
            p.pos.y = 820 - ceil((s(g, 5) - i) / (double)s(g, 4)) * 128;
    return (p);
}

player legend(game g, map *m, player p)
{
    int fd = open(g.path, O_RDONLY);
    char b[4096];

    m[16].h = malloc(4 * s(g, 0) * 2), m[16].f = malloc(4 * s(g, 1) * 2);
    read(fd, b, 4096), p = mapping(g, b, m, p);
    for (int i = 0, j = 0; b[i] != '\n'; i++) {
        if (b[i] == '^') m[16].h[j++] = i * 128, m[16].h[j++] = i * 128 + 128;
        if (b[i] == 'v') m[16].h[j++] = -i * 128, m[16].h[j++] = -i * 128 - 128;
    }
    for (int i = s(g, 4), j = 0; b[i] != '\n'; i++)
        if (b[i] == '!')
            m[16].f[j++] = -(i - s(g, 4)) * 128,
            m[16].f[j++] = -(i - s(g, 4)) * 128 - 128;
    for (int i = s(g, 4) * 2; !(b[i] == '\n' && b[i + 1] == '\n'); i++)
        if (b[i] == '$')
            m[16].end = -(s(g, 4) * ceil((s(g, 5) - i) /
            (double)s(g, 4)) - (s(g, 5) - i)) * 128;
    close(fd);
    return (p);
}

void game_loop(game g, map *m, player p)
{
    while (sfRenderWindow_isOpen(g.window)) {
        sfRenderWindow_pollEvent(g.window, &g.event);
        if (g.event.type == sfEvtClosed) sfRenderWindow_close(g.window);
        if (g.event.type == sfEvtKeyPressed && p.fall == 0
            && g.event.key.code == sfKeySpace && p.jump == 0)
            sfClock_restart(g.clock), p.jump = 1;
        g.time = sfClock_getElapsedTime(g.clock);
        g.sec = g.time.microseconds / 1000000.0;
        if (m[16].pos.x > m[16].end)
            p = move(g, m, p), g.score++;
        else
            p = end(g, m, p);
        p = display(g, m, p);
    }
    for (int i = 0; i != 16 + s(g, 2); i++)
        sfSprite_destroy(m[i].sprite), sfTexture_destroy(m[i].t);
    sfSprite_destroy(p.sprite), sfTexture_destroy(p.t);
    sfMusic_destroy(g.music), sfRenderWindow_destroy(g.window);
    sfSound_destroy(g.sound), sfSoundBuffer_destroy(g.buff);
    sfFont_destroy(g.font), sfText_destroy(g.text), free(m);
}

int main(int ac, char **av)
{
    game g = {ac == 2 ? av[1] : NULL, {1280, 720, 32}, sfSound_create(),
    sfRenderWindow_create(g.dim, "Crimson cavern", sfDefaultStyle, NULL),
    sfClock_create(), sfMusic_createFromFile("music"), sfText_create(),
    sfFont_createFromFile("font"), sfSoundBuffer_createFromFile("fire")};
    player p = {sfSprite_create(), sfTexture_createFromFile("sheet.png", NULL)};
    map *m;

    if (error(ac, av) == 84) {sfSound_destroy(g.sound), sfMusic_destroy(g.music)
        , sfSoundBuffer_destroy(g.buff);
        return (84);}
    m = malloc(sizeof(map) * (16 + s(g, 2)));
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        write(1, "Finite runner taking in argument the given .legend file", 55),
        write(1, " path with a map plan/formatting help. Backdrop/terrain", 55),
        write(1, " from Saukgp's forest and cave themes, spritesheet from", 55),
        write(1, " Contadodavid and song is Gurenge by LiSa.\n\nUSAGE\n./", 55),
        write(1, "my_runner .legend\trun the game\n./my_runner -h\tgame ", 54),
        write(1, "info/usage\n\nUSER INTERACTIONS\nSPACE_KEY\tjump\n", 46);
    else p = legend(g, m, p), create(g, m, p), game_loop(g, m, p);
    return (0);
}