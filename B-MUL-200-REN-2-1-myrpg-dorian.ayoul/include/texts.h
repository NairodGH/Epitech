/*
** EPITECH PROJECT, 2021
** texts.h
** File description:
** Texts prototypes
*/

#ifndef TEXTS_H
#define TEXTS_H

#include <engine.h>
#include <stdbool.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <nep/nhashmap.h>

typedef struct txt_s txt_t;

typedef struct txt_s {
    int type;
    char *content;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    sfColor color;
    bool visibility;
    int size;
    int state;
    void (*on_click)(ENGPANEL, txt_t *txt);
} txt_t;

void center_text_x(engine_t *engine, txt_t *txt);

void center_text_xy(engine_t *engine, txt_t *txt);

void center_text_y(engine_t *engine, txt_t *txt);

txt_t *create_text(sfFont *font, char *content, sfVector2f pos);

void destroy_text(txt_t *txt);

void destroy_texts(list_t *list);

void draw_text(engine_t *engine, txt_t *txt);

void draw_texts(engine_t *engine, list_t *list);

sfColor get_text_color(txt_t *txt);

char *get_text_content(txt_t *txt);

sfVector2f get_text_endpos(txt_t *txt);

sfFont *get_text_font(txt_t *txt);

sfVector2f get_text_pos(txt_t *txt);

int get_text_size(txt_t *txt);

int get_text_type(txt_t *txt);

bool is_text_visible(txt_t *txt);

void register_text(panel_t *panel, txt_t *txt);

void set_text_color(txt_t *txt, sfColor color);

void set_text_content(txt_t *txt, char *str);

void set_text_font(txt_t *txt, sfFont *font);

void set_text_pos(txt_t *txt, sfVector2f pos);

void set_text_size(txt_t *txt, int size);

void set_text_type(txt_t *txt, int type);

void set_text_visibility(txt_t *txt, bool visibility);

txt_t *get_text_by_type(panel_t *panel, int type);

void update_text(txt_t *txt);

int get_text_state(txt_t *txt);

void set_text_state(txt_t *txt, int state);

void set_text_events(txt_t *txt, void (*ev)(ENGPANEL, txt_t *obj));

bool is_text_clicked(txt_t *obj, sfVector2i ev);

#endif //TEXTS_H
