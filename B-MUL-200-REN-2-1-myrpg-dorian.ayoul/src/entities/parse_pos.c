/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_pos
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

sfVector2f parse_pos(char *pos_info)
{
    sfVector2f pos;
    char *raw_x = xml_get_attribute(pos_info, "x");
    char *raw_y = xml_get_attribute(pos_info, "y");

    if (!nstr_isdigit(raw_x) || !nstr_isdigit(raw_y))
        return ((sfVector2f) {0, 0});
    pos.x = natoi(raw_x) * 1.f;
    pos.y = natoi(raw_y) * 1.f;
    return (pos);
}