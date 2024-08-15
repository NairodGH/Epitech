/*
** EPITECH PROJECT, 2021
** buttons.h
** File description:
** Buttons prototypes
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>
#include <engine.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct button_s button_t;

typedef struct tooltip_s {
    int id;
    char *string;
    sfUint8 *pixels;
    sfImage *image;
    sfText *text;
    sfTexture *texture;
    sfSprite *sprite;
} tooltip_t;

typedef struct button_s {
    int id;
    char *path;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2u size;
    sfColor color;
    bool is_visible;
    bool is_hovered;
    bool is_clicked;
    bool is_sticky;
    void (*on_click)(ENGPANEL, button_t *btn);
    tooltip_t *tooltip;
} button_t;

button_t *create_button(char *path, sfIntRect rect, sfVector2f pos, bool vis);
void update_button(button_t *button);
void destroy_button(button_t *button);

bool get_button_clicked(button_t *button, sfMouseButtonEvent ev);
char *get_button_path(button_t *button);
sfVector2f get_button_pos(button_t *button);
sfIntRect get_button_rect(button_t *button);
sfVector2u get_button_size(button_t *button);

void set_button_id(button_t *button, int id);
void set_button_clicked(button_t *button, bool is_clicked);
void set_button_hovered(button_t *button, bool is_hovered);
void set_button_path(button_t *button, char *path);
void set_button_pos(button_t *button, sfVector2f pos);
void set_button_rect(button_t *button, sfIntRect rect);
void set_button_size(button_t *button, sfVector2u size);
void set_button_visible(button_t *button, bool is_visible);

void register_button(panel_t *panel, button_t *btn);

void draw_buttons(engine_t *engine, list_t *list);
void draw_button(engine_t *engine, button_t *btn);

bool get_button_hovered(engine_t *eng, button_t *button, sfVector2i v2i);
void set_button_events(button_t *btn, void (*ev)(ENGPANEL, button_t *btn));
void handle_buttons_click(engine_t *engine, game_t *game, sfVector2i mouse);

tooltip_t *create_tooltip(char *text);
sfFloatRect get_tooltip_size(tooltip_t *tool);
void set_tooltip(button_t *btn, char *text);
void display_tooltip(engine_t *eng, sfVector2f pos, tooltip_t *tool);
sfVector2f get_tooltip_pos(tooltip_t *tool, sfVector2f mouse);
sfVector2f get_tooltip_text_pos(sfVector2f newpos);
tooltip_t *get_tooltip_by_id(panel_t *panel, int id);
void register_tooltip(panel_t *panel, tooltip_t *tooltip);
void set_tooltip_id(tooltip_t *tooltip, int id);

void remove_button_click(engine_t *engine);
void destroy_buttons(list_t *list);

void draw_button_tooltips(engine_t *engine, list_t *list);
button_t *get_button_by_id(panel_t *panel, int id);

sfColor get_button_color(button_t *button);
void set_button_color(button_t *button, sfColor color);

#endif //BUTTONS_H