/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#pragma once

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include "raylib.h"

typedef struct {
    Vector2 pos;
    bool floor;
} pos_t;

typedef struct {
    bool is_cut;
    int floor;
    float time;
    Vector2 pos;
} cactus_t;

typedef struct {
    bool is_fixed;
    int floor;
    float time;
    Vector2 pos;
} electric_t;

typedef struct {
    bool already_use;
    float time;
} vacuum_t;

typedef struct {
    bool is_open;
    bool is_burning;
    bool interaction;
    float time;
    float time_burn;
} oven_t;

typedef struct {
    bool is_open;
    bool interaction;
    float time;
} frigde_t;

typedef struct {
    bool is_open;
    bool interaction;
    float time;
} microwave_t;

typedef struct {
    bool is_full[2];
    float time;
    bool interaction;
} bathtub_t;

typedef struct baby_s {
    Vector2 pos;
    Vector2 temp_pos;
    int floor;
    int hp;
    float speed;
    cactus_t *cactus;
    frigde_t *fridge;
    bathtub_t *bathtub;
    electric_t *electric;
    oven_t *oven;
    vacuum_t *vacuum;
    microwave_t *microwave;
} baby_t;

typedef struct {
    Vector2 pos;
    Vector2 temp_pos;
    float speed;
    int floor;
} mom_t;

typedef struct {
    Vector2 pos_toilet[2];
    bool is_open[2];
    float time;
    Vector2 pos_stairs[2];
} tp_t;

typedef struct {
    baby_t *baby;
    mom_t *mom;
    tp_t *tp;
    char **first_floor;
    char **second_floor;
    Texture2D textures[4];
    Sound use;
    int *keys;
    float game_time;
} kidiot_t;

#define R "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define B "\033[1;34m"
#define M "\033[1;35m"
#define C "\033[1;36m"
#define W "\033[1;0m"

char **read_map(char *path);
bool game_loop(kidiot_t *play, int keys[]);
char **get_map(char *str);
int get_map_size(char **map);

void print_double_tab(char **map);
void free_double_tab(char **map);

kidiot_t *init_kidiot(char **first_floor, char **second_floor, int time);
Vector2 find_spawn_pos(char cell, char **map);
void print_keys(int keys[]);

bool is_obstacle(char obs, kidiot_t *play, bool baby);
void move_players_mom(kidiot_t *play, int keys[]);
void move_players_baby(kidiot_t *play, int keys[]);

void draw_map(kidiot_t *play, int hg, int wd);
void draw_elec(kidiot_t *kidiot, Rectangle dest, pos_t pos);
void draw_cactus(kidiot_t *kidiot, Rectangle dest, pos_t pos);
void draw_misc(kidiot_t *kidiot, char cell, Rectangle dest, pos_t pos);
void draw_mom(kidiot_t *kidiot, Rectangle dest);
void draw_baby(kidiot_t *kidiot, Rectangle dest);

void gest_clock(kidiot_t *players, int key[]);
void gest_clock_split(char **map, kidiot_t *play, int keys[], float time);

void end_screen(bool baby_win, kidiot_t *kidiot, Vector2 orig);

cactus_t *init_cactus(kidiot_t *kidiot);
electric_t *init_elec(kidiot_t *kidiot);

void find_cactus(kidiot_t *kidiot, int x, int y, float time);
void find_elec(kidiot_t *kidiot, int x, int y, float time);
void find_rescue_elec(kidiot_t *kidiot, int x, int y);
void find_rescue_cactus(kidiot_t *kidiot, int x, int y);

void print_vector(Vector2 *pos);
Vector2 *find_all_cell(char **map, char cell);
int get_len_vect(Vector2 *pos);
