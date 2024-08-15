/*
** EPITECH PROJECT, 2021
** Get discuss chars
** File description:
** get discuss chars
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE void end_quest_discussion(panel_t *pan, game_t *gm, entity_t *entity)
{
    if (entity == NULL)
        return;
    gm->player->quest_id = entity->id;
    entity->state = WAITING_FOR_ACTION;
    start_quest_card_animation(pan);
}

PRIVATE void change_quest_template(panel_t *pan, game_t *gm, entity_t *ent)
{
    int len;
    char *rw;
    int lcount;

    if (ent == NULL || ent->quest->raw == NULL)
        return;
    lcount = my_arrcount(ent->quest->lines);
    len = nstrlen(ent->quest->raw);
    if (ent->quest->itr >= len) {
        if (ent->quest->id + 3 > lcount - 1) {
            end_quest_discussion(pan, gm, ent);
            return;
        }
        ent->quest->id += 3;
        ent->quest->itr = 0;
        rw = get_quest_chars(ent->quest->lines, ent->quest->id, 3);
        ent->quest->raw = rw;
    }
}

char *get_quest_str(panel_t *pan, game_t *game, entity_t *entity)
{
    int len;
    int itr = 0;
    char *str;

    if (entity == NULL)
        return ("");
    change_quest_template(pan, game, entity);
    len = entity->quest->itr;
    str = ncalloc(len + 1, sizeof(char));
    if (entity->quest->raw == NULL)
        return ("");
    for (; itr < len && entity->quest->raw[itr]; ++itr)
        str[itr] = entity->quest->raw[itr];
    str[itr] = '\0';
    change_discuss_time(entity, get_itc(str, itr - 1), (size_t) len);
    ++entity->quest->itr;
    return (str);
}

char *get_quest_chars(char **lines, int itr, int times)
{
    char *raw;
    int len = 0;
    int mtr = 0;

    if (lines == NULL || !lines[itr])
        return (NULL);
    for (int jtr = itr; lines[jtr] && jtr < itr + times; ++jtr)
        len += nstrlen(lines[jtr]) + 1;
    raw = ncalloc(len + 1, sizeof(char));
    for (int jtr = itr; lines[jtr] && jtr < itr + times; ++jtr) {
        for (int qtr = 0; lines[jtr][qtr]; ++qtr, ++mtr)
            raw[mtr] = lines[jtr][qtr];
        if (jtr < itr + times - 1)
            raw[mtr++] = '\n';
    }
    raw[mtr] = '\0';
    return (raw);
}