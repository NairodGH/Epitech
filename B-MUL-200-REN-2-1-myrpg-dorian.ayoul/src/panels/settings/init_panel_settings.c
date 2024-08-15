/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init settings panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

const size_t gkey_count = 9;

const gkey_t gkeys[] = {
        {MOVE_UP, BTN_KEY_UP, (sfVector2f) {499, 295}, NULL, 'Z'},
        {MOVE_DOWN, BTN_KEY_DOWN, (sfVector2f) {621, 295}, NULL, 'S'},
        {MOVE_LEFT, BTN_KEY_LEFT, (sfVector2f) {735, 295}, NULL, 'Q'},
        {MOVE_RIGHT, BTN_KEY_RIGHT, (sfVector2f) {831, 295}, NULL, 'D'},
        {KEY_INV, BTN_KEY_INV, (sfVector2f) {499, 390}, NULL, 'F'},
        {KEY_PLAYER, BTN_KEY_PLAYER, (sfVector2f) {621, 390}, NULL, 'P'},
        {KEY_ACH, BTN_KEY_ACH, (sfVector2f) {735, 390}, NULL, 'H'},
        {KEY_QUEST, BTN_KEY_QUEST, (sfVector2f) {831, 390}, NULL, 'Q'},
        {KEY_PICKUP, BTN_KEY_PICKUP, (sfVector2f) {831, 478}, NULL, 'E'},
};

void on_settings_event(engine_t *eng, game_t *game, panel_t *pn, sfEvent ev)
{
    (void) pn;
    if (ev.type == sfEvtKeyPressed) {
        on_key_update(eng, game, ev.key.code);
    }
}

void init_settings_keys(engine_t *eng UNUSED, game_t *game, panel_t *panel)
{
    gkey_t gkey;
    sfIntRect rct = {0, 0, 47, 47};
    button_t *btn;
    char *settings_key = "assets/msettings/key.png";

    for (size_t i = 0; i < gkey_count; ++i) {
        gkey = gkeys[i];
        btn = create_button(settings_key, rct, gkey.card_pos, true);
        btn->is_sticky = true;
        set_button_events(btn, &on_key_change);
        set_button_id(btn, gkey.button_id);
        set_tooltip(btn, "Change the attached key");
        register_button(panel, btn);
        create_key_text(game, panel, gkey);
    }
}

void init_settings_menu(engine_t *eng, game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    char *settings_bg = "assets/msettings/bg.png";
    obj_t *b = create_object(settings_bg, rct, (sfVector2f){0, 0});

    register_object(panel, b);
    init_panel_buttons(panel);
    init_settings_keys(eng, game, panel);
    init_settings_fps_text(game, panel);
    init_settings_volume_text(game, panel);
}

void init_panel_settings(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(SETTINGS);

    (void) game;
    set_panel_initializer(panel, &init_settings_menu, NULL);
    set_panel_events(panel, &on_settings_event);
    set_panel_updater(panel, NULL, &on_settings_render);
    register_panel(eng, panel);
}