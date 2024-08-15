/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui quest
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE unsigned int get_quest_count(ENGPANEL)
{
    unsigned int itr = 0;
    unsigned int count = 0;

    if (!game || !game->entities)
        return (count);
    for (; game->entities[itr]; ++itr) {
        if (!game->entities[itr]->quest)
            continue;
        ++count;
    }
    return (count);
}

PRIVATE unsigned int get_quest_done(ENGPANEL)
{
    unsigned int count = 0;
    char last = '\n';
    char current = last;

    if (!game || !game->player || !game->player->quests)
        return (count);
    for (unsigned int itr = 0; game->player->quests[itr]; ++itr) {
        current = game->player->quests[itr];
        if (current == ',') {
            last = current;
            continue;
        }
        if (last == ',' && (current >= '0' && current <= '9'))
            ++count;
        last = current;
    }
    return (count);
}

PRIVATE void init_playergui_quest_info(ENGPANEL)
{
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    pos = (sfVector2f) {353, 320};
    txt = create_text(font, "Quests: ", pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

PRIVATE void init_playergui_quest_content(ENGPANEL)
{
    char *str;
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;
    unsigned int curr = get_quest_done(engine, game, panel);
    unsigned int total = get_quest_count(engine, game, panel);

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    str = append_str(append_str(int_to_str(curr), "/"), int_to_str(total));
    pos = (sfVector2f) {413, 320};
    txt = create_text(font, str, pos);
    if (!txt || !str)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

void init_playergui_quest(ENGPANEL)
{
    init_playergui_quest_info(engine, game, panel);
    init_playergui_quest_content(engine, game, panel);
}