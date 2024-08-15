/*
** EPITECH PROJECT, 2021
** panel.h
** File description:
** Panel prototypes
*/

#ifndef PANEL_H
#define PANEL_H

#include <engine.h>
#include <stdbool.h>
#include <sounds.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <nep/nhashmap.h>

typedef struct panel_s {
    int id;
    list_t *buttons;
    list_t *texts;
    list_t *objects;
    list_t *tooltips;
    bool visibility;
    bool init;
    sound_t *bg_sound;
    void (*on_init)(ENGPANEL);
    void (*on_tick_update)(ENGPANEL);
    void (*on_render_update)(ENGPANEL);
    void (*on_event)(ENGPANEL, sfEvent event);
    void (*on_destroy)(ENGPANEL);
} panel_t;

void call_panel_events(engine_t *engine, game_t *game, sfEvent event);

void close_panel(engine_t *engine, game_t *game, panel_t *panel);

void close_panel_by_id(engine_t *engine, game_t *game, int id);

panel_t *create_panel(int id);

void destroy_panel(panel_t *panel);

void destroy_panels(list_t *list);

void draw_panel(engine_t *engine, game_t *game, panel_t *panel);

void draw_panels(engine_t *engine, game_t *game);

bool is_panel_visible(panel_t *panel);

void register_panel(engine_t *engine, panel_t *panel);

void set_panel_events(panel_t *panel, void (*ev)(ENGPANEL, sfEvent event));

void set_panel_initializer(panel_t *panel, void (*on_init)(ENGPANEL), \
    void (*on_destroy)(ENGPANEL));

void set_panel_updater(panel_t *panel, void (*on_tick_update)(ENGPANEL), \
    void (*on_render_update)(ENGPANEL));

bool set_panel_visibility(panel_t *panel, bool visibility);

void show_panel(engine_t *engine, game_t *game, panel_t *panel);

void show_panel_by_id(engine_t *engine, game_t *game, int id);

void tick_panels(engine_t *engine, game_t *game);

char get_converted_key(sfKeyCode code);

void hide_panel(engine_t *engine, int id);

panel_t *get_panel_by_id(engine_t *engine, int id);

void set_panel_bgsound(engine_t *engine, panel_t *panel, char *sound);

#endif //PANEL_H
