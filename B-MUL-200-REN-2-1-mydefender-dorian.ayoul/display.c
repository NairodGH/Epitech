/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display function to show text and sprites depending on current game stage
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

void show(game g, button *b, tower *t)
{
    for (int i = 0; i != 8; i++) {
        if (t[i].stage == 0 || t[i].stage == 1)
            t[i].rec.left = 0;
        if (g.pos.x < t[i].pos.x + 67 && g.pos.x > t[i].pos.x &&
            g.pos.y < t[i].pos.y + 38 && g.pos.y > t[i].pos.y &&
            (t[i].stage == 0 || t[i].stage == 1))
            t[i].rec.left = 73;
        sfSprite_setTextureRect(t[i].sprite, t[i].rec);
        sfRenderWindow_drawSprite(g.window, t[i].sprite, NULL);
    }
    lvl1_buttons_build_bar(g, b, t);
    lvl2_quotes_menu(g, b, t);
    lvl3_display(g, b, t);
}

void text(game g)
{
    char ui[4];

    ui[3] = '\0';
    for (int i = 2, j = 0; i != -1; i--) {
        j = g.gold % 10;
        g.gold = round(g.gold / 10);
        ui[i] = j + 48;
    }
    sfText_setPosition(g.text, (sfVector2f){120, 13});
    sfText_setString(g.text, ui);
    sfRenderWindow_drawText(g.window, g.text, NULL);
    for (int i = 2, j = 0; i != -1; i--) {
        j = g.hp % 10;
        g.hp = round(g.hp / 10);
        ui[i] = j + 48;
    }
    sfText_setPosition(g.text, (sfVector2f){60, 13});
    sfText_setString(g.text, ui);
    sfRenderWindow_drawText(g.window, g.text, NULL);
}

void display(game g, button *b, tower *t, list_t *npcs)
{
    sfRenderWindow_clear(g.window, sfWhite);
    sfRenderWindow_drawSprite(g.window, g.bg_sprite, NULL);
    if (!g.started && g.pos.x < 497 && g.pos.x > 295 && g.pos.y < 491
        && g.pos.y > 404)
        sfRenderWindow_drawSprite(g.window, b[125].sprite, NULL);
    if (g.started) {
        text(g);
        show(g, b, t);
        draw_list(g.window, npcs);
        if (!g.paused) {
            anim_npcs(npcs);
            move_ennemies(npcs);
        }
    }
    if (g.paused) {
        sfSprite_setPosition(g.menu_sprite, (sfVector2f){232, 0});
        sfRenderWindow_drawSprite(g.window, g.menu_sprite, NULL);
    }
    sfRenderWindow_display(g.window);
}

int help(void)
{
    my_printf("\t\tWelcome to Kingdom Rush !\n");
    my_printf("This TD is pretty like any others, build towers to kill");
    my_printf(" enemies.\n\n- Click any tower emplacement to build them\n");
    my_printf("- Use 'esc' key to pause the game while playing\n");
    my_printf("\n\tYour score will be displayed once no HP are remaining.\n");
    my_printf("Hf !\n");
    return 0;
}

void get_end_msg(game g, list_t *npcs)
{
    if (g.hp <= 0)
        my_printf("You lost !\n");
    else
        my_printf("You won !\n");
}