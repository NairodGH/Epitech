/*
** EPITECH PROJECT, 2021
** handle key change
** File description:
** handle key
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

PRIVATE bool update_keymv(settings_t *settings, int button_id, sfKeyCode code)
{
    if (button_id == BTN_KEY_UP) {
        settings->key_up = code;
        return (true);
    }
    if (button_id == BTN_KEY_LEFT) {
        settings->key_left = code;
        return (true);
    }
    if (button_id == BTN_KEY_RIGHT) {
        settings->key_right = code;
        return (true);
    }
    if (button_id == BTN_KEY_DOWN) {
        settings->key_down = code;
        return (true);
    }
    return (false);
}

char update_key(settings_t *settings, int button_id, sfKeyCode code)
{
    char info = get_converted_key(code);

    if (info == '\0' || is_key_already_set(settings, code))
        return ('\0');
    if (update_keymv(settings, button_id, code))
        return (code);
    if (button_id == BTN_KEY_INV)
        settings->key_inv = code;
    if (button_id == BTN_KEY_PLAYER)
        settings->key_player = code;
    if (button_id == BTN_KEY_ACH)
        settings->key_ach = code;
    if (button_id == BTN_KEY_QUEST)
        settings->key_quest = code;
    if (button_id == BTN_KEY_PICKUP)
        settings->key_pickup = code;
    return (code);
}

static void update_key_sound(engine_t *eng, char c)
{
    if (c == '\0') {
        play_seffect(eng->game, eng, "assets/sounds/click-err.ogg");
        return;
    }
    play_seffect(eng->game, eng, "assets/sounds/click-ok.ogg");
}

void on_key_update(engine_t *eng, game_t *gm, sfKeyCode code)
{
    button_t *btn;
    settings_t *settings;

    if (gm == NULL || gm->st_clicked_key == NULL)
        return;
    if (gm->settings == NULL)
        return;
    settings = gm->settings;
    btn = gm->st_clicked_key;
    if (!btn->is_clicked)
        return;
    set_button_clicked(btn, false);
    update_key_sound(eng, update_key(settings, btn->id, code));
    save_settings(settings);
}

void on_key_change(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) eng;
    (void) pan;
    btn->is_clicked = true;
    gm->st_clicked_key = btn;
}