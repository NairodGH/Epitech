/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save position
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

xml_balise_t *save_pos(save_t *sv, xml_balise_t *root)
{
    xml_balise_t *pos = xml_add_balise(root, "position");
    char *pos_x = string_format("%i", sv->pos_x);
    char *pos_y = string_format("%i", sv->pos_y);

    xml_add_attribute(pos, "x", pos_x);
    xml_add_attribute(pos, "y", pos_y);
    free(pos_x);
    free(pos_y);
    return pos;
}

xml_balise_t *save_pos_player(player_t *pl, xml_balise_t *root)
{
    xml_balise_t *pos = xml_add_balise(root, "position");
    char *pos_x = string_format("%i", pl->pos_x);
    char *pos_y = string_format("%i", pl->pos_y);

    xml_add_attribute(pos, "x", pos_x);
    xml_add_attribute(pos, "y", pos_y);
    free(pos_x);
    free(pos_y);
    return pos;
}