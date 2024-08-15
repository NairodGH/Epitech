/*
** EPITECH PROJECT, 2021
** engine.h
** File description:
** Engine prototypes
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <window.h>
#include <stdbool.h>
#include <nep/nlist.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct engine_s engine_t;
typedef struct panel_s panel_t;
typedef struct game_s game_t;

#define sfrenderstate_t sfRenderStates
#define sfsoundstatus_t sfSoundStatus
#define sfkeycode_t     sfKeyCode

#define ENGPANEL \
            engine_t *engine UNUSED, game_t *game UNUSED, panel_t *panel UNUSED

typedef struct engine_s {
    window_t *window;
    list_t *panels;
    list_t *sounds;
    game_t *game;
    sfEvent event;
    panel_t *last_panel;
    bool panel_changed;
    bool end;
    sfClock *lastclick;
} engine_t;

void close_engine(engine_t *engine);

sfRenderWindow *get_window(engine_t *engine);

engine_t *create_engine(window_t *window, game_t *game, list_t *panels);

void destroy_engine(engine_t *engine);

void handle_builtin_events(engine_t *engine, game_t *game, sfEvent event);

void poll_events(engine_t *engine, game_t *game, sfRenderWindow *window);

void start_engine(engine_t *engine, game_t *game);

void update_game_loop(engine_t *engine, game_t *game, sfRenderWindow *window);

void handle_texts_click(engine_t *engine, game_t *game, sfVector2i mouse);

#endif //ENGINE_H
