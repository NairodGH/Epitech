/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init game panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE char *get_quest_asset(game_t *game, entity_t *ent)
{
    if (!ent || !ent->quest)
        return ("assets/mquests/todo.png");
    if (already_finished_quest(game, ent->id))
        return ("assets/mquests/finished.png");
    if (game->player != NULL && game->player->quest_id == ent->id)
        return ("assets/mquests/progress.png");
    return ("assets/mquests/todo.png");
}

PRIVATE void register_qcard(char *asset, panel_t *pan, quest_t *quest, V2I p)
{
    sfIntRect rct = {0, 0, 64, 59};
    sfVector2f pos = {p.x * 1.f, p.y * 1.f};
    sfVector2f txtpos = {pos.x + 80, pos.y + 16};
    obj_t *b = create_object("assets/mquests/card-quest-item.png", rct, pos);
    sfIntRect rct2 = {0, 0, 64, 80};
    sfVector2f pos2 = {pos.x + 350, pos.y - 7};
    obj_t *state = create_object(asset, rct2, pos2);
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    txt_t *txt = create_text(font, quest->info, txtpos);

    set_text_size(txt, 18);
    set_text_color(txt, sfBlack);
    register_text(pan, txt);
    register_object(pan, b);
    register_object(pan, state);
}

void register_quest_cards(engine_t *eng, game_t *game, panel_t *pan)
{
    sfVector2i pos = {270, 170};
    size_t qtr = 0;
    char *asset = NULL;

    if (!eng || !game || !pan)
        return;
    if (!game->entities)
        return;
    for (unsigned int itr = 0; game->entities[itr] && qtr < 5; ++itr) {
        if (!game->entities[itr]->quest)
            continue;
        asset = get_quest_asset(game, game->entities[itr]);
        register_qcard(asset, pan, game->entities[itr]->quest, pos);
        pos.y += 80;
        ++qtr;
    }
}