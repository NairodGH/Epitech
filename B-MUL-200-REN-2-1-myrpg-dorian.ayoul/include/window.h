/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** window
*/

#ifndef RPG_WINDOW_H
#define RPG_WINDOW_H

#include <nep/nctype.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct engine_s engine_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVector2f base_size;
    int framerate;
    bool destroyed;
} window_t;

void center_window(window_t *window);

window_t *create_window(int height, int width, char *title, int framerate);

void destroy_window(window_t *window);

sfRenderWindow *get_window(engine_t *engine);

sfVector2f get_window_size(engine_t *engine);

bool has_display_env(char **env);

void set_window_framerate(window_t *window, int framerate);

sfVector2f get_window_scale(engine_t *eng);

double safe_scale(double pos, double scale);

#endif