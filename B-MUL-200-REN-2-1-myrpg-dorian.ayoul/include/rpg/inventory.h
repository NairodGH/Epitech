/*
** EPITECH PROJECT, 2021
** inventory.h
** File description:
** RPG inventory
*/

#ifndef RPG_INVENTORY_H
#define RPG_INVENTORY_H

#include <engine.h>
#include <envdata.h>
#include <buttons.h>
#include <objects.h>

typedef struct item_s {
    int id;
    int max_stack;
    int tile;
    int category;
    char *name;
    char *description;
    char *asset_image;
    sfIntRect asset_rect;
    obj_t *obj;
    obj_t *obj_gui;
    list_t *consumptions;
} item_t;

typedef struct itemstack_s {
    item_t *item;
    int count;
} itemstack_t;

enum consumption_type {
    UNKNOWN_CONSUMPTION,
    CONSUMPTION_HEALTH,
    CONSUMPTION_FOOD
};

typedef struct consumption_s {
    enum consumption_type type;
    int value;
    char *message;
    char *sound;
} consumption_t;

list_t *load_items(void);

item_t *get_item_from_tile_id(game_t *game, int tile_id);

list_t *get_inventory(game_t *game);

itemstack_t *create_itemstack(item_t *item, int item_count);

bool remove_inventory_item(game_t *game, item_t *item, int count);

bool add_inventory_item(game_t *game, item_t *item, int count);

itemstack_t *get_available_itemstack(game_t *game, item_t *item, int ncount);

void debug_inventory(game_t *game);

itemstack_t *get_itemstack_from_tileid(game_t *game, int tile_id);

item_t *get_item_from_id(game_t *game, int id);

bool remove_item_from_id(game_t *game, int item_id, int count);

itemstack_t *get_itemstack(game_t *game, int id);

bool give_item(game_t *game, int item_id, int count);

item_t *parse_item_consumable(item_t *item, char *xml);

bool remove_itemstack(game_t *game, itemstack_t *itemstack, int count);

void on_item_click(ENGPANEL, obj_t *obj);

bool consume_itemstack(game_t *game, itemstack_t *stack);

save_t *read_inventory(game_t *game, save_t *save, char *xml);

void save_save_inventory(save_t *save, xml_balise_t *content);

void save_player_inventory(player_t *player, xml_balise_t *content);

void init_panel_inventory(engine_t *eng, game_t *game UNUSED);

void handle_panel_inventory_events(ENGPANEL);

void start_inventory_panel(ENGPANEL);

void on_close_inventory(ENGPANEL, button_t *btn);

void on_left_inventory(ENGPANEL, button_t *btn);

void on_right_inventory(ENGPANEL, button_t *btn);

void render_inventory_gui(ENGPANEL);

unsigned int get_inventory_count(game_t *game);

unsigned int get_inventory_pagecount(game_t *game);

unsigned int get_current_page(panel_t *panel);

void render_inventory_gui(ENGPANEL);

bool navigate_inventory(panel_t *panel, int relative_page);

void render_inventory_items(game_t *game, panel_t *panel);

void tick_inventory_gui(ENGPANEL);

#endif