/*
** EPITECH PROJECT, 2021
** handle fps change
** File description:
** handle fps
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

void init_settings_fps_text(game_t *game, panel_t *panel)
{
    sfFont *font;
    txt_t *txt;
    sfVector2f pos = {525, 230};

    if (panel == NULL)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (font == NULL)
        return;
    txt = create_text(font, int_to_str(game->settings->fps), pos);
    set_text_size(txt, 30);
    set_text_color(txt, sfBlack);
    set_text_type(txt, TXT_SETTINGS_FPS);
    register_text(panel, txt);
}

void update_settings_fps_text(game_t *game, panel_t *panel)
{
    txt_t *txt = get_text_by_type(panel, TXT_SETTINGS_FPS);

    if (txt == NULL || game == NULL || game->settings == NULL)
        return;
    set_text_content(txt, int_to_str(game->settings->fps));
}

void on_fps_decrease(ENGPANEL, button_t *btn)
{
    settings_t *settings;

    (void) btn;
    if (game == NULL || game->settings == NULL)
        return;
    settings = game->settings;
    if (settings->fps - FPS_GAP < FPS_MIN) {
        settings->fps = FPS_MIN;
        set_window_framerate(engine->window, settings->fps);
        save_settings(settings);
        return;
    }
    settings->fps -= FPS_GAP;
    set_window_framerate(engine->window, settings->fps);
    save_settings(settings);
}

void on_fps_increase(ENGPANEL, button_t *btn)
{
    settings_t *settings;

    (void) btn;
    if (game == NULL || game->settings == NULL)
        return;
    settings = game->settings;
    if (settings->fps + FPS_GAP > FPS_MAX) {
        settings->fps = FPS_MAX;
        set_window_framerate(engine->window, settings->fps);
        save_settings(settings);
        return;
    }
    settings->fps += FPS_GAP;
    set_window_framerate(engine->window, settings->fps);
    save_settings(settings);
}