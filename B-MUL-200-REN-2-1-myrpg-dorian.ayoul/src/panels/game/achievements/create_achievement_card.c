/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Create achievement card
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE char *get_achievement_status(game_t *game, achievement_t *ach)
{
    if (!ach)
        return ("assets/mquests/todo.png");
    if (already_finished_achievement(game, ach->id))
        return ("assets/mquests/finished.png");
    return ("assets/mquests/todo.png");
}

void register_acard(char *asset, panel_t *pan, achievement_t *ach, V2I p)
{
    sfIntRect rct = {0, 0, 64, 59};
    sfVector2f pos = {p.x * 1.f, p.y * 1.f};
    sfVector2f txtpos = {pos.x + 80, pos.y + 16};
    obj_t *b = create_object("assets/mquests/card-quest-item.png", rct, pos);
    sfIntRect rct2 = {0, 0, 64, 80};
    sfVector2f pos2 = {pos.x + 350, pos.y - 7};
    obj_t *state = create_object(asset, rct2, pos2);
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    txt_t *txt = create_text(font, ach->description, txtpos);

    set_text_size(txt, 18);
    set_text_color(txt, sfBlack);
    register_text(pan, txt);
    register_object(pan, b);
    register_object(pan, state);
}

void register_achievement_cards(engine_t *eng, game_t *game, panel_t *pan)
{
    sfVector2i pos = {270, 170};
    size_t qtr = 0;
    char *asset = NULL;

    if (!eng || !game || !pan)
        return;
    if (!game->entities)
        return;
    for (unsigned int itr = 0; game->achievements[itr] && qtr < 3; ++itr) {
        asset = get_achievement_status(game, game->achievements[itr]);
        register_acard(asset, pan, game->achievements[itr], pos);
        pos.y += 80;
        ++qtr;
    }
}