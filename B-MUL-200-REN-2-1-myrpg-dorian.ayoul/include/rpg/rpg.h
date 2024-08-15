/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#ifndef RPG_H
#define RPG_H

#include <rpg/event.h>
#include <rpg/draw.h>
#include <window.h>
#include <rpg/map.h>
#include <rpg/tileset.h>
#include <rpg/tiled.h>
#include <rpg/grid.h>
#include <rpg/skill.h>

#include <nep/nctype.h>
#include <nep/nstring.h>
#include <nep/nlist.h>
#include <nep/nhashmap.h>
#include <nep/nprintf.h>
#include <hnep/config/nxml.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <engine.h>
#include <envdata.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>

#include <SFML/Window.h>
#include <SFML/Graphics.h>

#define     WINDOW_X    960
#define     WINDOW_Y    540

#define     FPS_MIN     10
#define     FPS_MAX     120
#define     FPS_GAP     10
#define     VOL_MIN     0
#define     VOL_MAX     100
#define     VOL_GAP     10

#define     V2F         sfVector2f
#define     V2I         sfVector2i
#define     IR          sfIntRect
#define     EGSTATIC(eng)      (eng->game->statics)

#define xml_balcontent(xml, n) (xml_get_content(xml_get_balise(xml, n)))

typedef struct fight_s fight_t;
typedef struct entity_s entity_t;
typedef struct achievement_s achievement_t;

enum panel_type {
    START_ANIM,
    START,
    GAME,
    SETTINGS,
    CUSTOM_PLAYER,
    EXIT_CONFIRMATION,
    GAME_END,
    CREDITS,
    SAVE_LIST,
    SAVE_CREATE,
    HOW_TO_PLAY,
    PAUSE,
    HUD,
    GAME_QUESTS,
    GAME_PLAYERGUI,
    GAME_ACHIEVEMENTS,
    GAME_INVENTORY,
    SNOW_PANEL,
    RAIN_PANEL,
    FOG_PANEL,
    GAME_FIGHT
};

enum elem_type {
    BTN_KEY_UP,
    BTN_KEY_DOWN,
    BTN_KEY_LEFT,
    BTN_KEY_RIGHT,
    BTN_KEY_INV,
    BTN_KEY_PLAYER,
    BTN_KEY_ACH,
    BTN_KEY_QUEST,
    BTN_KEY_PICKUP,
    BTN_CUSPLAYER_SELECTOR_1,
    BTN_CUSPLAYER_SELECTOR_2,
    BTN_CUSPLAYER_SELECTOR_3,
    BTN_CUSPLAYER_SELECTOR_4,
    BTN_CUSPLAYER_SELECTOR_5,
    BTN_CUSPLAYER_SELECTOR_6,
    BTN_CUSPLAYER_SELECTOR_7,
    BTN_CUSPLAYER_SELECTOR_8,
    BTN_CUSPLAYER_SELECTOR_9,
    BTN_CUSPLAYER_SELECTOR_10,
    BTN_CUSPLAYER_SELECTOR_11,
    BTN_CUSPLAYER_SELECTOR_12,
    BTN_NPC_DISCUSS,
    BTN_NPC_FIGHT,
    BTN_NPC_QUEST,
    TXT_SETTINGS_VOLUME,
    TXT_SETTINGS_FPS,
    OBJ_CUSPLAYER_ASSET,
    OBJ_PLAYER,
    OBJ_ENTITY,
    OBJ_MINIPANEL,
    OBJ_SAVECREATE_ARROW,
    OBJ_SNOW,
    OBJ_RAIN,
    OBJ_FOG,
    OBJ_NEWQUEST,
    OBJ_INVENTORY_ITEM,
    TXT_SAVE_CREATE_NAME,
    TXT_SAVE_NAME,
    TXT_NPC,
    TXT_PICKUP,
    TXT_CREDITS,
    BTN_SAVE_LOAD,
    HUD_OBJ,
    OBJ_INVENTORY_BAR,
    TXT_ACTION_BAR,
    OBJ_INVENTORY_BACKGROUND,
    OBJ_INVENTORY_ARROWRIGHT,
    OBJ_INVENTORY_ARROWLEFT,
    OBJ_INVENTORY_CLOSE,
    OBJ_GAME_LOADING,
    OBJ_GAME_LOADING_SHADER,
    BTN_SAVE_CREATE,
    BTN_SAVE_LISTCREATE,
    OBJ_BG_STARTMENU,
    HP,
    FOOD,
    EXP,
    ICON,
    LEVEL,
    OBJ_FIGHT_BG,
    OBJ_FIGHT_ENTITY,
    OBJ_FIGHT_PLAYER,
    OBJ_FIGHT_HP_ENTITY,
    OBJ_FIGHT_HP_PLAYER,
    TXT_FIGHT_STATUS,
    TXT_FIGHT_SKILL,
    BTN_FIGHT_HEAL,
    BTN_END_CREDITS,
    BTN_END_HOME
};

enum key_type {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    KEY_INV,
    KEY_PLAYER,
    KEY_ACH,
    KEY_QUEST,
    KEY_PICKUP
};

enum npc_state {
    WAITING_FOR_ACTION,
    DISCUSS,
    FIGHT,
    QUEST
};

enum quest_type {
    UNKNOWN_QUEST,
    GET_ITEM
};

enum reward_type {
    UNKNOWN_REWARD,
    REWARD_XP,
    REWARD_ITEM
};

enum achievement_type {
    UNKNOWN_ACHIEVEMENT,
    DISCUSS_NPC,
    QUEST_NPC,
    FIGHT_NPC
};

enum hard_tile {
    GRASS_1 = 1,
    GRASS_2 = 6,
    GRASS_3 = 7,
    SNOW_1 = 1559,
    SNOW_2 = 1653,
    SNOW_3 = 1749,
    SNOW_4 = 1754,
    SAND_1 = 1787,
    SAND_2 = 1790,
    SAND_3 = 1794,
    SAND_4 = 1795,
    SAND_5 = 1880,
    SAND_6 = 1881,
    SAND_7 = 1882,
    SAND_8 = 1883,
    SAND_9 = 1884,
    SAND_10 = 1975,
    WOOD_1 = 2736,
    WOOD_2 = 2737,
    WOOD_3 = 2738,
};

typedef struct cutscene_s {
    bool in_cutscene;
    int movement_sleep;
    int movement_index;
    sfClock *clock;
    char **movements;
    sfVector2i end_pos;
} cutscene_t;

typedef struct stage_s {
    map_t *map;
} stage_t;

typedef struct keyconv_s {
    sfKeyCode code;
    char shown_key;
} keyconv_t;

typedef struct gkey_s {
    enum key_type id;
    int button_id;
    sfVector2f card_pos;
    button_t *card;
    char assigned_key;
} gkey_t;

typedef struct settings_s {
    int volume;
    int fps;
    sfKeyCode key_up;
    sfKeyCode key_down;
    sfKeyCode key_left;
    sfKeyCode key_right;
    sfKeyCode key_inv;
    sfKeyCode key_player;
    sfKeyCode key_ach;
    sfKeyCode key_quest;
    sfKeyCode key_pickup;
    int player;
} settings_t;

typedef struct player_s {
    char *save_name;
    int health;
    int xp;
    int level;
    int food_level;
    int pos_x;
    int pos_y;
    int last_view;
    int last_view_id;
    long tmp_movement_count;
    char *achievements;
    char *quests;
    int quest_id;
    int ingame_time;
    list_t *pickitems;
    list_t *inventory;
    list_t *skills;
    sfClock *last_movement;
    sfClock *last_pos_change;
    sfClock *last_save;
    sfClock *movement_soundclock;
    sfClock *regen_clock;
} player_t;

typedef struct save_s {
    char *name;
    int health;
    int xp;
    int level;
    int food_level;
    int pos_x;
    int pos_y;
    int last_view;
    int last_view_id;
    int quest_id;
    int ingame_time;
    list_t *pickitems;
    list_t *inventory;
    list_t *skills;
    char *achievements;
    char *quests;
    sfClock *last_movement;
} save_t;

typedef struct statics_s {
    obj_t *push_quest;
    txt_t **hud_inv_amount;
    char **basic_num;
} statics_t;

typedef struct game_s {
    bool is_waiting;
    bool first_game;
    engine_t *engine;
    window_t *window;
    settings_t *settings;
    hashmap_t *tilesets;
    stage_t *stage;
    player_t *player;
    entity_t **entities;
    fight_t *curr_fight;
    statics_t *statics;
    achievement_t **achievements;
    button_t *st_clicked_key;
    cutscene_t *cutscene;
    save_t **saves;
    list_t *items;
    list_t *skills;
    bool paused;
    bool loaded;
    bool load_after;
    int curr_fps;
    int fps;
} game_t;

typedef struct playerasset_s {
    int id;
    sfVector2f basepos;
} playerasset_t;

typedef struct reward_s {
    enum reward_type type;
    int value;
    int item_id;
    int item_count;
} reward_t;

typedef struct quest_s {
    char *name;
    char *text;
    char *info;
    char *started_text;
    char *finished_text;
    char **lines;
    char *raw;
    int id;
    int itr;
    enum quest_type type;
    int item_id;
    int item_count;
    list_t *rewards;
} quest_t;

typedef struct entity_fight_s {
    int health;
    int defense;
    list_t *skills;
    int pathing_sleep;
    int path_index;
    sfClock *path_clock;
    pos_t **pathing;
} entity_fight_t;

typedef struct entity_s {
    int id;
    char *asset;
    char *name;
    sfIntRect rect;
    sfVector2f pos;
    quest_t *quest;
    entity_fight_t *fight;
    char *discuss;
    char **discuss_lines;
    char *discuss_raw;
    int line_id;
    int discuss_itr;
    int next_time;
    sfClock *discuss_clock;
    sfClock *discuss_soundclock;
    obj_t *obj;
    enum npc_state state;
} entity_t;

enum fight_status {
    FIGHT_ONGOING,
    FIGHT_WON,
    FIGHT_WAIT_FOR_ENEMY,
    FIGHT_LOST
};

typedef struct fight_s {
    entity_t *entity;
    int entity_health;
    sfClock *nextattack;
    enum fight_status status;
} fight_t;

typedef struct achievement_s {
    int id;
    char *type;
    int npc_id;
    char *asset;
    char *description;
    obj_t *obj;
    int animation_state;
    int reward_xp;
} achievement_t;

char *replace_char(char *str, char from, char to);

void game_start(list_t *args);

void game_init(game_t *game, list_t *args);

void game_loop(game_t *game);

void game_exit(game_t *game, char const *message);

void stage_init(game_t *game);

void stage_free(game_t *game);

void register_tileset(game_t *game);

void init_panel_game(engine_t *eng, game_t *game);

void init_panel_start(engine_t *eng, game_t *game);

void on_start_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void on_quit_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void init_buttons_start_play(game_t *game, panel_t *panel);

void init_buttons_start_quit(panel_t *panel);

void init_buttons_start_settings(panel_t *panel);

void on_settings_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void init_panel_settings(engine_t *eng, game_t *game);

void on_key_change(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void on_key_update(engine_t *eng, game_t *gm, sfKeyCode code);

void create_key_text(game_t *game, panel_t *panel, gkey_t gkey);

void update_key_texts(game_t *game, panel_t *panel);

void on_settings_render(engine_t *eng, game_t *game, panel_t *panel);

bool is_key_already_set(settings_t *settings, sfKeyCode code);

void init_panel_buttons(panel_t *panel);

void on_volume_decrease(ENGPANEL, button_t *btn);

void on_volume_increase(ENGPANEL, button_t *btn);

void on_fps_decrease(ENGPANEL, button_t *btn);

void on_fps_increase(ENGPANEL, button_t *btn);

char *int_to_str(int nb);

void init_settings_fps_text(game_t *game, panel_t *panel);

void update_settings_fps_text(game_t *game, panel_t *panel);

settings_t *init_settings(list_t *args);

envkey_t **generate_default_settings(void);

settings_t *read_settings(list_t *list);

void save_settings_array(envkey_t **set);

char *convert_key_char(sfKeyCode code);

void save_settings(settings_t *st);

sfkeycode_t get_key_code(char *str);

void move_player(engine_t *eng, panel_t *pan, game_t *game);

void init_panel_cusplayer(engine_t *eng, game_t *game);

playerasset_t *get_player_assets(void);

sfVector2f get_player_basepos(int player_id);

sfVector2f get_player_pos(int player_id, int movement, int foot);

void on_cusplayer_save(ENGPANEL, button_t *btn);

void on_cusplayer_render(engine_t *eng, game_t *game, panel_t *panel);

void on_cusplayer_select(ENGPANEL, button_t *btn);

void on_cusmenu_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void init_buttons_start_custom(panel_t *panel);

void init_panel_exit(engine_t *eng, game_t *game);

void init_buttons_exit_yes(panel_t *panel);

void init_buttons_exit_no(panel_t *panel);

void init_exit_text(panel_t *panel);

void init_panel_anim(engine_t *eng, game_t *game);

void init_settings_volume_text(game_t *game, panel_t *panel);

void update_settings_volume_text(game_t *game, panel_t *panel);

void load_player(player_t *player);

envkey_t **read_saved_player(void);

void save_player_array(envkey_t **set);

bool load_after(engine_t *engine);

bool is_movement_key(game_t *game);

obj_t *get_player(panel_t *pan);

void set_player_movement_asset(panel_t *pan, game_t *game, sfKeyCode code);

void on_pause_resume(ENGPANEL, button_t *btn);

void on_pause_options(ENGPANEL, button_t *btn);

void on_pause_start(ENGPANEL, button_t *btn);

void on_pause_quit(ENGPANEL, button_t *btn);

void init_buttons_pause_resume(panel_t *panel);

void init_buttons_pause_options(panel_t *panel);

void init_buttons_pause_start(panel_t *panel);

void init_buttons_pause_quit(panel_t *panel);

void init_panel_pause(engine_t *eng, game_t *game);

void init_panel_savelist(engine_t *eng, game_t *game);

void init_panel_savecreate(engine_t *eng, game_t *game);

void init_savecreate_menu(ENGPANEL);

void on_save_save(ENGPANEL, button_t *btn);

void on_save_create_events(ENGPANEL, sfEvent event);

void update_save_arrow(ENGPANEL);

void set_save_arrow_position(obj_t *obj, txt_t *txt);

void change_player_asset(panel_t *pan, game_t *game, int movement, bool mov);

save_t **load_saves(game_t *game);

void save_save(save_t *st);

void save_save_skills(save_t *save, xml_balise_t *content);

void save_player_skills(player_t *player, xml_balise_t *content);

bool give_player_skills(game_t *game, player_t *player);

save_t *read_save(game_t *game, char *file);

bool str_endswith(char *str, char *check);

char *append_str(char *from, char *append);

save_t *init_default_save(char *name);

player_t *init_player(save_t *save);

save_t *generate_default_save(save_t *save);

void on_save_load(ENGPANEL, button_t *btn);

char *get_pretty_save_name(char *file);

void init_buttons_saves(game_t *game, panel_t *panel);

void on_save_create(ENGPANEL, button_t *btn);

void init_save_name(panel_t *panel, save_t *save, int x, int y);

void save_player_clock(player_t *player);

void zoom_map(engine_t *eng, sfEvent event);

void init_panel_hwp(engine_t *eng, game_t *game);

void init_buttons_hwp_back(panel_t *panel);

void on_hwp_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void handle_food_decrease(player_t *player);

void player_teleport(game_t *game, int x, int y);

bool player_collides(panel_t *panel, map_t *m, float sx, float sy);

entity_t **parse_entities(void);

quest_t *parse_quest(char *quest_info);

sfIntRect parse_rect(char *rect_info);

sfVector2f parse_pos(char *pos_info);

entity_fight_t *parse_fight(char *fight_info);

obj_t *prepare_entity_object(entity_t *e);

void display_entities(panel_t *pan, game_t *game);

float get_entity_distance(panel_t *panel, game_t *game, sfVector2f epos);

void init_npc_panel(ENGPANEL);

void init_snow_panel(engine_t *engine, game_t *game);

void init_rain_panel(engine_t *engine, game_t *game);

void init_fog_panel(engine_t *engine, game_t *game);

void check_npc_panel(ENGPANEL);

void on_npc_discuss(ENGPANEL, button_t *btn);

void on_npc_fight(ENGPANEL, button_t *btn);

void on_npc_quest(ENGPANEL, button_t *btn);

entity_t *get_nearest_npc(ENGPANEL);

void check_pickup_panel(ENGPANEL);

void init_pickup_panel(ENGPANEL);

map_tile_t *get_item_nearest(panel_t *panel, map_t *m);

char *get_discuss_chars(char **lines, int itr, int times);

char *get_discuss_str(game_t *game, entity_t *entity);

void display_npc_discuss(ENGPANEL);

achievement_t **parse_achievements(void);

enum achievement_type get_achievement_type(achievement_t *achievement);

bool finish_achievement(game_t *game, int npc_id, enum achievement_type type);

achievement_t *get_npc_achievement(game_t *gm, int n, enum achievement_type y);

void display_achievements(game_t *game);

void register_achievement_objects(game_t *game, panel_t *panel);

void save_achievement(game_t *game, int id);

bool already_finished_achievement(game_t *game, int id);

float rfdiff(sfVector2f pos1, sfVector2f pos2);

double get_rymax(map_t *m);

double get_rxmax(map_t *m);

void animate_background(obj_t *obj);

void skip_anim(engine_t *eng, game_t *gm);

void animate_pacman(engine_t *eng, game_t *gm, obj_t *obj);

void play_footsteps(panel_t *pan, game_t *game, player_t *player);

int get_player_tile(map_t *map, obj_t *obj);

void init_pickup(panel_t *panel);

void handle_item_pick(panel_t *panel, game_t *game);

void pickup_item(panel_t *panel, game_t *game);

sfVector2i get_player_tile_pos(map_t *map, obj_t *obj);

xml_balise_t *save_attributes(save_t *sv, xml_balise_t *content);

xml_balise_t *save_pos(save_t *sv, xml_balise_t *content);

xml_balise_t *save_attributes_player(player_t *pl, xml_balise_t *content);

xml_balise_t *save_pos_player(player_t *pl, xml_balise_t *content);

void display_npc_quest(ENGPANEL);

void play_discuss_sound(engine_t *eng, game_t *game, entity_t *ent);

char *get_quest_chars(char **lines, int itr, int times);

entity_t *prepare_entity_discuss(entity_t *entity, char *ent);

entity_t *parse_entity_data(entity_t *entity, char *entity_info);

void change_discuss_time(entity_t *entity, char last_char, size_t len);

char *get_quest_str(panel_t *pan, game_t *game, entity_t *entity);

statics_t *init_statics(void);

void register_player(ENGPANEL);

void display_quest_card(panel_t *panel);

void start_quest_card_animation(panel_t *panel);

char *get_screenshot_name(void);

void take_screenshot(engine_t *engine);

void init_panel_hud(engine_t *eng, game_t *game UNUSED);

bool already_finished_quest(game_t *game, int id);

void handle_quest_end(game_t *game, entity_t *entity);

list_t *parse_quest_rewards(char *xml);

void give_quest_rewards(game_t *game, entity_t *entity);

void init_inventory_bar(panel_t *pan);

void update_inventory_bar(engine_t *eng, game_t *game, panel_t *pan);

void draw_items(game_t *game, panel_t *panel);

void game_event(engine_t *eng, game_t *game, panel_t *panel, sfEvent ev);

void game_render(engine_t *eng, game_t *game, panel_t *panel);

void game_tick(engine_t *eng, game_t *game, panel_t *panel);

void game_event_escape(engine_t *eng, game_t *game, sfEvent ev);

void init_panel_quest(engine_t *eng, game_t *game);

void init_action_bar(engine_t *engine, panel_t *panel);

void update_action_bar(panel_t *panel);

void handle_panel_quests_events(ENGPANEL);

void register_quest_cards(engine_t *eng, game_t *game, panel_t *pan);

void draw_item_tooltip(engine_t *eng, obj_t *obj, sfVector2f pos, bool hu);

void add_player_health(game_t *game, int health);

void add_player_food(game_t *game, int food_level);

void set_action_bar(engine_t *eng, panel_t *panel, char *content);

void update_snow_panel(ENGPANEL);

void add_pick_item(game_t *game, map_tile_t *tile, sfVector2f pos);

void save_save_pickitems(save_t *save, xml_balise_t *content);

void save_player_pickitems(player_t *player, xml_balise_t *content);

save_t *read_pickitems(save_t *save, char *xml);

void add_player_xp(game_t *game, int xp);

void load_game(engine_t *engine, game_t *game, panel_t *panel);

void remove_pickitems(game_t *game);

void start_fps(game_t *game);

void register_achievement_cards(engine_t *eng, game_t *game, panel_t *pan);

void handle_panel_achievements_events(ENGPANEL);

void init_panel_achievement(engine_t *eng, game_t *game UNUSED);

bool save_exists(game_t *game, char *name);

void handle_map_movement(sfKeyCode key, ENGPANEL);

void move_force_player(engine_t *en, panel_t *pan, game_t *gm, sfKeyCode ke);

cutscene_t *parse_cutscene(void);

bool end_cutscene(game_t *game);

bool is_cutscene_started(game_t *game);

void handle_cutscene(ENGPANEL);

void load_first_game(ENGPANEL);

bool start_cutscene(game_t *game);

bool skip_cutscene(game_t *game);

void credits_events(engine_t *eng, game_t *game, panel_t *pan, sfEvent ev);

void scroll_credits(engine_t *engine, game_t *game, panel_t *panel);

void init_panel_credits(engine_t *eng, game_t *game);

void on_credits_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn);

void init_buttons_start_credits(panel_t *panel);

void init_playergui_bg(ENGPANEL);

void init_playergui_char(ENGPANEL);

void init_playergui_name(ENGPANEL);

void handle_playergui_events(ENGPANEL);

void init_panel_player(engine_t *eng, game_t *game UNUSED);

void init_playergui_health(ENGPANEL);

void init_playergui_hunger(ENGPANEL);

void init_playergui_level(ENGPANEL);

void init_playergui_xp(ENGPANEL);

void init_playergui_ach(ENGPANEL);

void init_playergui_quest(ENGPANEL);

char *get_seconds_to_time(int seconds);

void init_playergui_igtime(ENGPANEL);

void init_playergui_buttons(ENGPANEL);

unsigned int get_current_save_count(game_t *game);

void render_savelist(ENGPANEL);

char *set_button_key(settings_t *settings, int btn_id);

char *get_assigned_key(game_t *game, gkey_t gkey);

void parse_settings_attributes(settings_t *settings, char *xml);

bool parse_settings_keys(settings_t *settings, char *xml);

bool update_volume(settings_t *settings, char *vol);

bool update_fps(settings_t *settings, char *fps);

bool update_playerid(settings_t *settings, char *plid);

void update_snow_panel(ENGPANEL);

void update_rain_panel(ENGPANEL);

void update_fog_panel(ENGPANEL);

void init_texts_hwp(ENGPANEL);

void init_txt_key_down(ENGPANEL);

void init_txt_key_up(ENGPANEL);

void init_txt_key_right(ENGPANEL);

void init_txt_key_left(ENGPANEL);

void init_txt_key_inv(ENGPANEL);

void init_txt_key_interact(ENGPANEL);

void init_txt_key_player(ENGPANEL);

void init_txt_key_quests(ENGPANEL);

void on_snow_panel_start(ENGPANEL);

void on_rain_panel_start(ENGPANEL);

void on_fog_panel_start(ENGPANEL);

void start_game_load(engine_t *engine, game_t *game, panel_t *panel);

void render_game_load(engine_t *engine, game_t *game, panel_t *panel);

bool check_assets(void);

void set_panel_bgsound(engine_t *engine, panel_t *panel, char *sound);

char get_itc(char *str, int itr);

void init_start_texts(game_t *game, panel_t *panel);

void start_fight(game_t *game, entity_t *entity);

void update_entity_position(entity_t **entities);

void init_panel_fight(engine_t *eng, game_t *game UNUSED);

void tick_fight(ENGPANEL);

void render_fight(ENGPANEL);

void start_fight_panel(ENGPANEL);

void start_display_fight(ENGPANEL, entity_t *entity);

int get_player_id(game_t *game);

void init_fight_background(panel_t *panel);

void init_enemy_fight(panel_t *panel, game_t *game);

void init_player_fight(panel_t *panel, game_t *game);

void init_fight_background(panel_t *panel);

void create_fight_escape_button(panel_t *panel);

void end_fight(engine_t *engine, game_t *game);

void init_fight_hpentity(panel_t *panel);

void update_fight_hpentity(game_t *game, panel_t *panel);

void update_fight_hpplayer(game_t *game, panel_t *panel);

void init_fight_hpplayer(panel_t *panel);

void init_fight_hpentity(panel_t *panel);

void create_fight_status_txt(panel_t *panel);

void create_skill_texts(game_t *game, panel_t *panel);

skill_t *get_attack_by_id(game_t *game, int id);

void on_attack_select(ENGPANEL, txt_t *txt);

void update_fight_stext(panel_t *panel, char *str);

bool fight_attack_entity(game_t *game, int damage);

bool fight_attack_player(game_t *game);

skill_t *fight_turn_ia(fight_t *fight, player_t *player);

void wait_for_attack(panel_t *panel, game_t *game);

void won_fight(engine_t *engine, game_t *game);

void lost_fight(engine_t *engine, game_t *game);

void create_fight_heal_button(panel_t *panel);

void render_heal_button(ENGPANEL);

void handle_health(ENGPANEL);

void init_buttons_home(panel_t *panel);

void init_buttons_credits(panel_t *panel);

void init_panel_end(engine_t *eng, game_t *game);

bool handle_game_end(ENGPANEL);

void init_txt_key_ach(ENGPANEL);

#endif