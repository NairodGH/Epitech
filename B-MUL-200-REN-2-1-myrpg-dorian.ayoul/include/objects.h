/*
** EPITECH PROJECT, 2021
** objects.h
** File description:
** Objects prototypes
*/

#ifndef OBJECTS_H
#define OBJECTS_H

#include <engine.h>
#include <buttons.h>
#include <stdbool.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <nep/nhashmap.h>

typedef struct obj_s obj_t;

typedef struct obj_s {
    int type;
    char *asset;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfShader *shader;
    sfRenderStates render;
    sfClock *clock;
    sfColor color;
    tooltip_t *tooltip;
    void (*on_click)(ENGPANEL, obj_t *btn);
    void *child;
    bool visibility;
    int state;
    float statef;
} obj_t;

void center_obj_x(engine_t *engine, obj_t *obj);

void center_obj_xy(engine_t *engine, obj_t *obj);

void center_obj_y(engine_t *engine, obj_t *obj);

obj_t *create_object(char *asset, sfIntRect rect, sfVector2f pos);

obj_t *create_shader(char *asset);

void destroy_object(obj_t *obj);

void destroy_objects(list_t *list);

void draw_object(engine_t *engine, obj_t *obj);

void draw_object_shader(engine_t *engine, obj_t *obj);

void draw_objects(engine_t *engine, list_t *list);

void draw_objects_shaders(engine_t *engine, list_t *list);

obj_t *duplicate_object(obj_t *obj);

char *get_obj_asset(obj_t *obj);

sfVector2f get_obj_center(obj_t *obj);

sfVector2f get_obj_pos(obj_t *obj);

sfIntRect get_obj_rect(obj_t *obj);

sfSprite *get_obj_sprite(obj_t *obj);

sfTexture *get_obj_texture(obj_t *obj);

sfRenderStates get_obj_renderstates(obj_t *obj);

sfShader *get_obj_shader(obj_t *obj);

int get_obj_type(obj_t *obj);

bool is_obj_clicked(obj_t *obj, sfVector2i ev);

bool is_obj_visible(obj_t *obj);

void register_object(panel_t *panel, obj_t *obj);

void set_obj_asset(obj_t *obj, char *asset);

void set_obj_pos(obj_t *obj, sfVector2f pos);

void set_obj_rect(obj_t *obj, sfIntRect rect);

void set_obj_renderstates(obj_t *obj);

void set_obj_shader(obj_t *obj, char *asset);

void set_obj_type(obj_t *obj, int type);

void set_obj_visibility(obj_t *obj, bool visibility);

obj_t *get_obj_by_id(panel_t *panel, int id);

tooltip_t *create_tooltip(char *text);

void set_obj_tooltip(obj_t *obj, char *text);

void handle_objects_hover(engine_t *engine);

void handle_objects_click(engine_t *engine, game_t *game, sfVector2i mouse);

void set_obj_events(obj_t *obj, void (*ev)(ENGPANEL, obj_t *obj));

void set_obj_child(obj_t *obj, void *child);

sfColor get_obj_color(obj_t *obj);

void set_obj_color(obj_t *obj, sfColor color);

#endif //OBJECTS_H
