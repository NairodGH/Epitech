/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init buttons start
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_buttons_pause_resume(panel_t *panel)
{
    sfIntRect rct = {0, 0, 115, 57};
    char *asset = "assets/pause/resume.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){400, 155}, true);

    set_button_events(btn, &on_pause_resume);
    set_tooltip(btn, "Resume game");
    register_button(panel, btn);
}

void init_buttons_pause_options(panel_t *panel)
{
    sfIntRect rct = {0, 0, 115, 57};
    char *asset = "assets/pause/options.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){400, 225}, true);

    set_button_events(btn, &on_pause_options);
    set_tooltip(btn, "Change settings");
    register_button(panel, btn);
}

void init_buttons_pause_start(panel_t *panel)
{
    sfIntRect rct = {0, 0, 115, 57};
    char *asset = "assets/pause/title_screen.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){400, 295}, true);

    set_button_events(btn, &on_pause_start);
    set_tooltip(btn, "Go to start menu");
    register_button(panel, btn);
}

void init_buttons_pause_quit(panel_t *panel)
{
    sfIntRect rct = {0, 0, 115, 57};
    char *asset = "assets/pause/quit.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){400, 365}, true);

    set_button_events(btn, &on_pause_quit);
    set_tooltip(btn, "Quit the game");
    register_button(panel, btn);
}