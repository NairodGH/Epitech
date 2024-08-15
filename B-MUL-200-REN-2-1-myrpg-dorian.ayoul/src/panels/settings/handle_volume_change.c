/*
** EPITECH PROJECT, 2021
** handle volume change
** File description:
** handle volume
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

void init_settings_volume_text(game_t *game, panel_t *panel)
{
    sfFont *font;
    txt_t *txt;
    sfVector2f pos = {525, 185};

    if (panel == NULL)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (font == NULL)
        return;
    txt = create_text(font, int_to_str(game->settings->volume), pos);
    set_text_size(txt, 30);
    set_text_color(txt, sfBlack);
    set_text_type(txt, TXT_SETTINGS_VOLUME);
    register_text(panel, txt);
}

void update_settings_volume_text(game_t *game, panel_t *panel)
{
    txt_t *txt = get_text_by_type(panel, TXT_SETTINGS_VOLUME);

    if (txt == NULL || game == NULL || game->settings == NULL)
        return;
    set_text_content(txt, int_to_str(game->settings->volume));
}

void on_volume_decrease(ENGPANEL, button_t *btn)
{
    settings_t *settings;

    (void) btn;
    if (game == NULL || game->settings == NULL)
        return;
    settings = game->settings;
    if (settings->volume - VOL_GAP < VOL_MIN) {
        settings->volume = VOL_MIN;
        save_settings(settings);
        return;
    }
    settings->volume -= VOL_GAP;
    save_settings(settings);
}

void on_volume_increase(ENGPANEL, button_t *btn)
{
    settings_t *settings;

    (void) btn;
    if (game == NULL || game->settings == NULL)
        return;
    settings = game->settings;
    if (settings->volume + VOL_GAP > VOL_MAX) {
        settings->volume = VOL_MAX;
        save_settings(settings);
        return;
    }
    settings->volume += VOL_GAP;
    save_settings(settings);
}