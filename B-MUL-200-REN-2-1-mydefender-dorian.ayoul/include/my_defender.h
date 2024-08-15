/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** Header file containing
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    sfVideoMode dim;
    sfRenderWindow* window;
    sfImage* icon;
    bool started;
    sfSprite* bg_sprite;
    sfTexture* bg_texture;
    bool paused;
    sfSprite* menu_sprite;
    sfTexture* menu_texture;
    sfSound* *s;
    int gold;
    int hp;
    sfText* text;
    sfFont* font;

    sfVector2i pos;
    sfEvent event;
} game;

typedef struct {
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rec;
    sfVector2f pos;
} button;

typedef struct {
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rec;
    sfVector2f pos;
    sfClock* clock;
    sfClock *cd;
    sfTime time;
    double sec;
    double pause;
    int stage;
} tower;

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
    sfClock *move_clock;
    sfClock *anim_clock;
    int life;
    int direction;
    int is_locked;
    int time;
    int type;
} game_object_t;

typedef struct list {
    game_object_t *data;
    struct list *next;
} list_t;

void create(game g, button *b, tower *t);
game menu(game g);
game click(game g, button *b, tower *t);
game clock_pause(game g, tower *t);
game lvl1_menu(game g, button *b, tower *t, int i);
void lvl1_buttons_build_bar(game g, button *b, tower *t);
void quotes(game g, tower *t, int i, int random_number);
game lvl2_menu(game g, button *b, tower *t, int i);
void lvl2_quotes_menu(game g, button *b, tower *t);
game lvl3_menu(game g, button *b, tower *t, int i);
void menu_open_close_lvl3(game g, button *b, tower *t, int i);
void lvl3_display(game g, button *b, tower *t);
void display(game g, button *b, tower *t, list_t *npcs);

//LS
void list_push(list_t **head, game_object_t *data);
void list_stack(list_t **head, game_object_t *data);
void list_destroy(list_t *head);
void list_remove(list_t **head, int index);

//NPCS
void draw_list(sfRenderWindow *w, list_t *ennemies);
void add_ennemies(list_t **enemies, int number, int type, sfClock *gtime);
sfVector2f rdmpos(int xupl, int xdownl, int yupl, int ydownl);
void move_ennemies(list_t *npcs);
void anim_npcs(list_t *npcs);

//UTILS
char *get_ennemy_path(int type);
sfIntRect get_enemy_rect(game_object_t *npc, int type);
char int_to_len(int n);
game_object_t *create_object(char *path, sfVector2f pos, float speed);
int is_dead(list_t **npcs, game *g);
int help(void);
void get_end_msg(game g, list_t *npcs);

//HITBOX
int is_hit(list_t *npcs, tower *towers);

int lib(char *str1, char *str2, int mode);

#endif