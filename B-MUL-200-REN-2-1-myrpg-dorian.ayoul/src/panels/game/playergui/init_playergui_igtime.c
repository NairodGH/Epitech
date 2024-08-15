/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui ingame time
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void init_playergui_igtime_info(ENGPANEL)
{
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    pos = (sfVector2f) {353, 340};
    txt = create_text(font, "Playtime: ", pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 12);
    register_text(panel, txt);
}

PRIVATE void init_playergui_igtime_content(ENGPANEL)
{
    char *str;
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    str = get_seconds_to_time(game->player->ingame_time);
    pos = (sfVector2f) {410, 340};
    txt = create_text(font, str, pos);
    if (!txt || !str)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 12);
    register_text(panel, txt);
}

void init_playergui_igtime(ENGPANEL)
{
    init_playergui_igtime_info(engine, game, panel);
    init_playergui_igtime_content(engine, game, panel);
}