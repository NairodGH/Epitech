/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** custom player menu render
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE void update_player_render(obj_t *obj)
{
    sfIntRect base = obj->rect;
    sfIntRect c = sfSprite_getTextureRect(obj->sprite);

    if (base.left == c.left) {
        c.left -= 32;
        c.top = base.top;
        sfSprite_setTextureRect(obj->sprite, c);
        return;
    }
    if (c.left == base.left - 32) {
        c.left += 63;
        c.top = base.top;
        sfSprite_setTextureRect(obj->sprite, c);
        return;
    }
    sfSprite_setTextureRect(obj->sprite, base);
    return;
}

PRIVATE void update_cusplayer_select_btn(button_t *btn, int player_id)
{
    char *disabled = "assets/btns/heart_disabled.png";
    char *enabled = "assets/btns/heart.png";

    if (btn == NULL)
        return;
    if (btn->id < BTN_CUSPLAYER_SELECTOR_1)
        return;
    if (btn->id == BTN_CUSPLAYER_SELECTOR_1 + (player_id - 1)) {
        if (nstrcmp(get_button_path(btn), enabled))
            set_button_path(btn, enabled);
        return;
    }
    if (btn->id <= BTN_CUSPLAYER_SELECTOR_12) {
        if (nstrcmp(get_button_path(btn), disabled))
            set_button_path(btn, disabled);
    }
}

PRIVATE void update_cusplayer_selector(ENGPANEL)
{
    button_t *btn;
    int player_id;

    if (panel->buttons == NULL || game->settings == NULL)
        return;
    player_id = game->settings->player;
    list_foreach(panel->buttons, node) {
        btn = (button_t *) node->value;
        update_cusplayer_select_btn(btn, player_id);
    }
}

void on_cusplayer_render(engine_t *eng, game_t *game, panel_t *panel)
{
    obj_t *obj;

    update_cusplayer_selector(eng, game, panel);
    if (panel->objects == NULL)
        return;
    list_foreach(panel->objects, node) {
        obj = (obj_t *) node->value;
        if (obj->type != OBJ_CUSPLAYER_ASSET)
            continue;
        sfClock *c = obj->clock;
        sfInt64 time = sfClock_getElapsedTime(c).microseconds;
        if (time / 10000 < 16.f)
            continue;
        update_player_render(obj);
        sfClock_restart(c);
    }
}