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

PRIVATE void end_discussion(game_t *game, entity_t *entity)
{
    if (entity == NULL)
        return;
    entity->state = WAITING_FOR_ACTION;
    finish_achievement(game, entity->id, DISCUSS_NPC);
}

PRIVATE void change_discuss_template(game_t *game, entity_t *entity)
{
    int len;
    char *rw;
    int lcount;

    if (entity == NULL || entity->discuss_raw == NULL)
        return;
    lcount = my_arrcount(entity->discuss_lines);
    len = nstrlen(entity->discuss_raw);
    if (entity->discuss_itr >= len) {
        if (entity->line_id + 3 > lcount - 1) {
            end_discussion(game, entity);
            return;
        }
        entity->line_id += 3;
        entity->discuss_itr = 0;
        rw = get_discuss_chars(entity->discuss_lines, entity->line_id, 3);
        entity->discuss_raw = rw;
    }
}

void change_discuss_time(entity_t *entity, char last_char, size_t len)
{
    int time = 30;

    if (entity == NULL || entity->discuss_raw == NULL)
        return;
    if (last_char == ' ')
        time = 60;
    if (last_char >= '0' && last_char <= '9')
        time = 100;
    if (last_char >= 'A' && last_char <= 'Z')
        time = 150;
    if (last_char == ',')
        time = 300;
    if (last_char == '.' || last_char == '!')
        time = 500;
    entity->next_time = len >= nstrlen(entity->discuss_raw) - 1 ? -1 : time;
}

char *get_discuss_str(game_t *game, entity_t *entity)
{
    int len;
    int itr = 0;
    char *str;

    if (entity == NULL)
        return ("");
    change_discuss_template(game, entity);
    len = entity->discuss_itr;
    str = ncalloc(len + 1, sizeof(char));
    if (entity->discuss_raw == NULL)
        return ("");
    for (; itr < len && entity->discuss_raw[itr]; ++itr)
        str[itr] = entity->discuss_raw[itr];
    change_discuss_time(entity, get_itc(str, itr - 1), (size_t) len);
    str[itr] = '\0';
    ++entity->discuss_itr;
    return (str);
}

char *get_discuss_chars(char **lines, int itr, int times)
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