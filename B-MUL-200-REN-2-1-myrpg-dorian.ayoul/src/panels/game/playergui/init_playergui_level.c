/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui level
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void init_playergui_level_info(ENGPANEL)
{
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    pos = (sfVector2f) {353, 260};
    txt = create_text(font, "Level: ", pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

PRIVATE void init_playergui_level_content(ENGPANEL)
{
    char *health;
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    health = append_str(int_to_str(game->player->level), "/5");
    pos = (sfVector2f) {400, 260};
    txt = create_text(font, health, pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

void init_playergui_level(ENGPANEL)
{
    init_playergui_level_info(engine, game, panel);
    init_playergui_level_content(engine, game, panel);
}