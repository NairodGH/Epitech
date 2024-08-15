/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init game hud
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void update_level(panel_t *panel, game_t *game)
{
    int lvl;
    txt_t *level = get_text_by_type(panel, LEVEL);

    if (level == NULL || game == NULL || game->player == NULL)
        return;
    lvl = game->player->level;
    if (lvl < 1 || lvl > 95) {
        lvl = 1;
    }
    set_text_content(level, game->statics->basic_num[lvl]);
}

void on_hud_render(engine_t *eng UNUSED, game_t *game, panel_t *panel)
{
    obj_t *icon = get_obj_by_id(panel, ICON);
    obj_t *hp = get_obj_by_id(panel, HP);
    obj_t *food = get_obj_by_id(panel, FOOD);
    obj_t *exp = get_obj_by_id(panel, EXP);

    if (!icon || !hp || !food || !exp)
        return;
    icon->rect.left = 567 + game->settings->player * 69 - 69;
    sfSprite_setTextureRect(icon->sprite, icon->rect);
    hp->rect.width = 100 - (100 - game->player->health);
    sfSprite_setTextureRect(hp->sprite, hp->rect);
    food->rect.width = 100 - (100 - game->player->food_level);
    sfSprite_setTextureRect(food->sprite, food->rect);
    exp->rect.width = 0 + game->player->xp;
    sfSprite_setTextureRect(exp->sprite, exp->rect);
    update_level(panel, game);
}

void text_settings(panel_t *panel)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    txt_t *txt = create_text(font, "1", (V2F){78, 120});
    char *content = "Level";
    txt_t *txt_info = create_text(font, content, (V2F){30, 120});

    set_text_size(txt, 18);
    set_text_size(txt_info, 18);
    set_text_type(txt, LEVEL);
    set_text_color(txt, sfBlack);
    set_text_color(txt_info, sfBlack);
    register_text(panel, txt);
    register_text(panel, txt_info);
}

void hud_start_panel(ENGPANEL)
{
    char *path = "assets/textures/hud/hud.png";
    obj_t *icon = create_object(path, (IR){567, 0, 69, 85}, (V2F){23, 23});
    obj_t *hud = create_object(path, (IR){0, 0, 266, 120}, (V2F){0, 0});
    obj_t *hp = create_object(path, (IR){266, 0, 100, 15}, (V2F){145, 10});
    obj_t *food = create_object(path, (IR){366, 0, 100, 15}, (V2F){155, 52});
    obj_t *exp = create_object(path, (IR){467, 0, 100, 15}, (V2F){145, 95});

    text_settings(panel);
    set_obj_type(icon, ICON);
    register_object(panel, icon);
    set_obj_type(hud, HUD_OBJ);
    register_object(panel, hud);
    set_obj_type(hp, HP);
    register_object(panel, hp);
    set_obj_type(food, FOOD);
    register_object(panel, food);
    set_obj_type(exp, EXP);
    register_object(panel, exp);
}

void init_panel_hud(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(HUD);

    set_panel_initializer(panel, &hud_start_panel, NULL);
    set_panel_updater(panel, NULL, &on_hud_render);
    register_panel(eng, panel);
}