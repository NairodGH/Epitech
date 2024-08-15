/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef ZAPPY_AI_H
    #define ZAPPY_AI_H

    #define RESSOURCE_NBR 7
    #define MAP_REFRESH 10

    #ifndef _GNU_SOURCE
        #define _GNU_SOURCE
    #endif

    #define SUCCESS (0)
    #define ERROR (1)
    #define EXIT (2)

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #include <sys/types.h>
    #include <linux/limits.h>
    #include <sys/stat.h>

    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <regex.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <uuid/uuid.h>
    #include <math.h>

    #include "list.h"
    #include "nlib.h"
    #include "raylib.h"
    #include "command.h"

typedef enum {
    North,
    East,
    South,
    West
} direction_e;

typedef struct arg_s {
    int port;
    char *machine;
} arg_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct {
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
    pos_t food_pos;
    pos_t linemate_pos;
    pos_t deraumere_pos;
    pos_t sibur_pos;
    pos_t mendiane_pos;
    pos_t phiras_pos;
    pos_t thystame_pos;
} inventory_t;

typedef struct player_s {
    int level;
    char *team_name;
    inventory_t *inv;
    pos_t pos;
    direction_e dir;
    char *uuid;
} player_t;

typedef enum {
    STATE_NONE,
    STATE_INCANT,
    STATE_FAILED,
    STATE_SUCCESS,
} state_inc_e;

typedef struct map_s {
    inventory_t *inv;
    list_t *player;
    bool clicked;
    int it;
    state_inc_e incantation;
    size_t act_frame_x;
    size_t act_frame_y;
    size_t frame_x;
    size_t frame_y;
    Color color;
} map_t;

typedef struct client_s {
    socket_t *socket;
    char *machine;
    char *uuid;
    size_t time_unit;
    pos_t size_map;
    fd_set readfds;
    fd_set writefds;
    list_t *command;
    list_t *pending_commands;
    list_t *player;
    list_t *team;
    map_t **map;
    char *win_team;
} client_t;

    #define R "\033[1;31m"
    #define G "\033[1;32m"
    #define Y "\033[1;33m"
    #define B "\033[1;34m"
    #define M "\033[1;35m"
    #define C "\033[1;36m"
    #define W "\033[1;0m"

void sig_handler(int signum);

bool send_message(list_t *pending, list_t *list, socket_t *socket, char *mess);

int read_stdin(client_t *client);

bool parse_return(client_t *client, char *str);

bool init_client(arg_t *arg);
client_t *create_client(arg_t *arg);
void free_client(client_t *client);
void free_player(void *data);

bool first_command(client_t *client);
bool loop_command(client_t *client);
bool find_command(client_t *client, char *temp);
bool clock_update(size_t freq);

char *create_uuid();
char *get_one_word(char *str);
char *move_str(char *str);
char *go_next_command(char *save, char *research);
char *go_next_space(char *str);
char *get_one_command(char *save);
char *go_next_char(char *str, char chr);

void print_player(player_t *player);
void print_inventory(inventory_t *inv);
void print_inventory_map(client_t *client);
void print_team(list_t *team);

void display(client_t *client);
Texture *get_textures();
void unload_textures(Texture *textures);
int get_item(map_t map, const char *object_name);
int levels_nb(client_t *client, pos_t pos, int level);
void unclick_rest(client_t *client, pos_t tile);

void draw_incantation(map_t *tile, pos_t pos, int ratio);
void draw_items(map_t tile, pos_t pos, int ratio);
void draw_inventory(client_t *client, pos_t pos, pos_t map, pos_t edge);
void check_click(client_t *client, pos_t map, pos_t edge);
void draw_player(map_t tile, int ratio, pos_t pos);
void draw_map(client_t *client, int ratio, pos_t edge);

void draw_misc(client_t *client, int ratio, pos_t map, pos_t edge);

Font *get_font(void);
void unload_fonts(Font *fonts);

#endif // ZAPPY_AI_H
