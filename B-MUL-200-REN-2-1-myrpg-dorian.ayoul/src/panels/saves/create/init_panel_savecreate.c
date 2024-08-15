/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save list panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>

char *get_save_name(ENGPANEL)
{
    txt_t *txt = NULL;
    char *str;

    list_foreach(panel->texts, node)
        txt = (txt_t *)node->value;
    if (txt == NULL)
        return (NULL);
    str = (char *) sfText_getString(txt->text);
    return (str);
}

void on_save_save(ENGPANEL, button_t *btn UNUSED)
{
    save_t *save;
    char *save_name;

    save_name = get_save_name(engine, game, panel);
    if (!save_name || !nstrlen(save_name) || save_exists(game, save_name))
        return;
    close_panel_by_id(engine, game, SAVE_CREATE);
    save = init_default_save(save_name);
    save = generate_default_save(save);
    game->player = init_player(save);
    show_panel_by_id(engine, game, GAME);
    game->saves = load_saves(game);
    game->paused = false;
    game->first_game = true;
}

void on_savecreate_render(ENGPANEL)
{
    char *name = get_save_name(engine, game, panel);
    button_t *btn = get_button_by_id(panel, BTN_SAVE_CREATE);

    update_save_arrow(engine, game, panel);
    if (!btn)
        return;
    if (name == NULL || !nstrlen(name) || save_exists(game, name)) {
        set_button_color(btn, (sfColor) {120, 120, 120, 255});
        return;
    }
    set_button_color(btn, sfTransparent);
}

void init_panel_savecreate(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(SAVE_CREATE);

    set_panel_initializer(panel, &init_savecreate_menu, NULL);
    set_panel_events(panel, &on_save_create_events);
    set_panel_updater(panel, NULL, &on_savecreate_render);
    panel->visibility = false;
    register_panel(eng, panel);
}