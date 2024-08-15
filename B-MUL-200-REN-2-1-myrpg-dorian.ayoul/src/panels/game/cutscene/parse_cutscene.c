/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Parse cutscene
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <file_utils.h>

PRIVATE sfVector2i parse_endpos(char *endpos)
{
    sfVector2i pos = {288, 381};
    char *raw_x;
    char *raw_y;

    if (!endpos) {
        return (pos);
    }
    raw_x = xml_get_attribute(endpos, "x");
    raw_y = xml_get_attribute(endpos, "y");
    if (!raw_x || !raw_y)
        return (pos);
    if (!nstr_isdigit(raw_x) || !nstr_isdigit(raw_y))
        return (pos);
    pos.x = natoi(raw_x);
    pos.y = natoi(raw_y);
    return (pos);
}

PRIVATE void fill_cutscene(cutscene_t *cutscene, char *content)
{
    char *info = xml_balcontent(content, "cutscene");
    int time;
    char *path_balise;
    char *pathing;
    char *endpos;

    if (!info)
        return;
    path_balise = xml_get_balise(info, "pathing");
    time = natoi(xml_get_attribute(path_balise, "time"));
    pathing = xml_get_content(path_balise);
    cutscene->movement_sleep = time;
    cutscene->movements = my_strtok(pathing, ',');
    endpos = xml_get_balise(info, "endpos");
    cutscene->end_pos = parse_endpos(endpos);
}

cutscene_t *parse_cutscene(void)
{
    char *content = read_file("config/cutscene.xml");
    cutscene_t *cutscene;

    if (content == NULL)
        return (NULL);
    cutscene = ncalloc(1, sizeof(cutscene_t));
    if (!cutscene)
        return (NULL);
    cutscene->in_cutscene = false;
    cutscene->movement_sleep = 0;
    cutscene->movement_index = 0;
    cutscene->clock = sfClock_create();
    cutscene->movements = NULL;
    fill_cutscene(cutscene, content);
    return (cutscene);
}