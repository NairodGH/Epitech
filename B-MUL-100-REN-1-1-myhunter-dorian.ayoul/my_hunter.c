/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** plif plouf être méchant c'est pas ouf
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "include/my_hunter.h"

int str(char *arr, int mode)
{
    int nb = 0;

    while (mode == 0 && arr[nb] != '\0') nb++;
    for (int i = 0; mode == 1 && arr[i] != '\0'; i++) {
        if (arr[0] == '-' && arr[1] == 'h' && arr[2] == '\0') return (10);
        if (47 < arr[i] && arr[i] < 58) nb *= 10, nb += arr[i] - 48;
        else {
            str("/!\\ Custom number of ducks is not a valid integer !\n", 2);
            return (10);
        }
        if (nb >= 100) {
            str("/!\\ Custom number shall not exceed the double digit !\n", 2);
            return (10);
        }
    }
    if (mode == 2) write(1, arr, str(arr, 0));
    return (nb);
}

void destroy(game g, duck *d, hound h)
{
    for (int i = 0; i != g.nb; i++)
        sfSprite_destroy(d[i].s), sfTexture_destroy(d[i].t),
        sfClock_destroy(d[i].clock);
    sfSprite_destroy(h.s), sfTexture_destroy(h.t), sfClock_destroy(h.clock);
    sfSprite_destroy(g.bg_s), sfTexture_destroy(g.bg_t);
    sfMusic_destroy(g.m), sfRenderWindow_destroy(g.window);
    sfSound_destroy(g.sound), sfSoundBuffer_destroy(g.buff);
    sfFont_destroy(g.font), sfText_destroy(g.text), free(d);
}

void game_loop(game g, duck *d, hound h)
{
    for (double *save = malloc(8 * g.nb); g.shot != 0;) {
        while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            if (g.event.type == sfEvtClosed) g.shot = 0;
            g.event.type == sfEvtMouseButtonPressed &&
            g.event.mouseButton.button == sfMouseLeft ?
            g.shot--, sfSound_play(g.sound) : 1;
        }
        g.pos = sfMouse_getPosition(g.window);
        for (int i = 0; i != g.nb; i++)
            d[i].time = sfClock_getElapsedTime(d[i].clock),
            d[i].sec = d[i].time.microseconds / 1000000.0;
        h.time = sfClock_getElapsedTime(h.clock);
        h.sec = h.time.microseconds / 1000000.0;
        if (h.sec < 2.4) h = intro(g, h);
        else g = move(g, d, save);
        display(g, d, h);
    }
    end(g, h), sfRenderWindow_close(g.window), destroy(g, d, h);
}

void create(game g, duck *d, hound h)
{
    srand(time(NULL));
    for (int i = 0; i != g.nb; i++) {
        d[i].s = sfSprite_create();
        d[i].rec = (sfIntRect){0, 0, 0, 0};
        d[i].t = sfTexture_createFromFile("sheet.png", NULL);
        sfSprite_setTexture(d[i].s, d[i].t, sfTrue);
        rand() % 6 <= 2 ? d[i].speedx = d[i].speedy = 0.02 :
        rand() % 6 == 5 ? d[i].rec.left = 1252, d[i].speedx = d[i].speedy = 0.06
        : (d[i].rec.left = 626, d[i].speedx = d[i].speedy = 0.04);
        d[i].flip = false, d[i].shot = false;
        d[i].pos = (sfVector2f){rand() / 3000000.0f, 560};
        d[i].clock = sfClock_create();
    }
    sfText_setFont(g.text, g.font), sfText_setCharacterSize(g.text, 40);
    sfSound_setBuffer(g.sound, g.buff), sfText_setLineSpacing(g.text, 0.55);
    sfSprite_setTexture(h.s, h.t, sfTrue), sfText_setLetterSpacing(g.text, 2);
    sfSprite_setTexture(g.bg_s, g.bg_t, sfTrue), sfSound_setVolume(g.sound, 10);
    sfWindow_setKeyRepeatEnabled(g.window, false), sfMusic_play(g.m);
    sfRenderWindow_setFramerateLimit(g.window, INT_MAX);
}

int main(int ac, char **av)
{
    game g = {{800, 600, 32}, sfTexture_createFromFile("bg.png", NULL),
    sfRenderWindow_create(g.dim, "my_hunter", sfDefaultStyle, NULL),
    sfSprite_create(), sfMusic_createFromFile("music"),
    sfText_create(), sfFont_createFromFile("font"), sfSound_create(),
    sfSoundBuffer_createFromFile("shot"), ac == 2 ? str(av[1], 1) : 10, g.nb};
    duck *d = malloc(sizeof(duck) * g.nb);
    hound h = {sfSprite_create(), sfTexture_createFromFile("sheet.png", NULL),
    {1877, 0, 53, 42}, {150, 425}, sfClock_create()};

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        sfSound_destroy(g.sound), sfSoundBuffer_destroy(g.buff),
        str("Duck hunt remake project made in CSFML at Epitech. The ", 2),
        str("player has to shoot as much ducks as he can until he runs ", 2),
        str("out of ammunitions or closes the game to increase his ", 2),
        str("final score.\n\nUSAGE\n./my_hunter\trun the game (base ", 2),
        str("difficulty of 10 ducks)\n./my_hunter [n]\trun the game with ", 2),
        str("a custom number of [n] ducks\n./my_hunter -h\tgame usage\n\n", 2),
        str("USER INTERACTIONS\nLEFT_CLICK\tshoot\n", 2), sfMusic_destroy(g.m);
    else create(g, d, h), game_loop(g, d, h);
    return (0);
}