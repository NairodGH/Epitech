/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui xp
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void init_playergui_xp_info(ENGPANEL)
{
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    pos = (sfVector2f) {353, 280};
    txt = create_text(font, "XP: ", pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

PRIVATE void init_playergui_xp_content(ENGPANEL)
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
    health = append_str(int_to_str(game->player->xp), "/100");
    pos = (sfVector2f) {385, 280};
    txt = create_text(font, health, pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

void init_playergui_xp(ENGPANEL)
{
    init_playergui_xp_info(engine, game, panel);
    init_playergui_xp_content(engine, game, panel);
}