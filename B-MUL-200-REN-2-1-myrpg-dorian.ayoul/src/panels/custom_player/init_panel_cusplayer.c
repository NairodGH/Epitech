/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init custom player panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE void init_cusplayer_buttons(panel_t *panel)
{
    char *save_btn = "assets/msettings/save_btn.png";
    sfIntRect rct = {0, 0, 147, 71};
    sfVector2f pos = {406, 400};
    button_t *btn = create_button(save_btn, rct, pos, true);

    set_button_events(btn, &on_cusplayer_save);
    set_tooltip(btn, "Save your choice");
    register_button(panel, btn);
}

PRIVATE void init_cusplayer_assets(panel_t *panel)
{
    char *player = "assets/game/player.png";
    playerasset_t *assets = get_player_assets();
    playerasset_t asset;
    sfVector2f bp;
    sfIntRect rc;
    obj_t *obj;
    int x = 120;

    for (unsigned int itr = 0; itr < 12; ++itr) {
        asset = assets[itr];
        bp = get_player_pos(asset.id, 1, -1);
        rc = (sfIntRect) {bp.x, bp.y, 30, 35};
        obj = create_object(player, rc, (sfVector2f){x, 250});

        set_obj_type(obj, OBJ_CUSPLAYER_ASSET);
        register_object(panel, obj);
        x += 60;
    }
}

PRIVATE void init_cusplayer_selector(panel_t *panel)
{
    char *heart_disabled = "assets/btns/heart_disabled.png";
    sfVector2f bp = {120, 290};
    sfIntRect rc = {0, 0, 32, 31};
    button_t *btn;

    for (unsigned int itr = 0; itr < 12; ++itr) {
        btn = create_button(heart_disabled, rc, bp, true);
        set_button_id(btn, BTN_CUSPLAYER_SELECTOR_1 + itr);
        set_tooltip(btn, "Select this character");
        set_button_events(btn, &on_cusplayer_select);
        register_button(panel, btn);
        bp.x += 60;
    }
}

void init_cusplayer_menu(engine_t *eng, game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    char *cusplayer_bg = "assets/mcusplayer/bg.png";
    obj_t *b = create_object(cusplayer_bg, rct, (sfVector2f){0, 0});

    (void) game;
    (void) eng;
    register_object(panel, b);
    init_cusplayer_buttons(panel);
    init_cusplayer_assets(panel);
    init_cusplayer_selector(panel);
}

void init_panel_cusplayer(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(CUSTOM_PLAYER);

    (void) game;
    set_panel_initializer(panel, &init_cusplayer_menu, NULL);
    set_panel_updater(panel, NULL, &on_cusplayer_render);
    register_panel(eng, panel);
}