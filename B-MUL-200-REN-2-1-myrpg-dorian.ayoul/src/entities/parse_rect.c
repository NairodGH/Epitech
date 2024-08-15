/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_rect
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

sfIntRect parse_rect(char *rect_info)
{
    sfIntRect rect = {0, 0, 0, 0};
    char *raw_top = xml_get_attribute(rect_info, "top");
    char *raw_left = xml_get_attribute(rect_info, "left");
    char *raw_width = xml_get_attribute(rect_info, "width");
    char *raw_height = xml_get_attribute(rect_info, "height");

    if (!nstr_isdigit(raw_top) || !nstr_isdigit(raw_left))
        return (rect);
    if (!nstr_isdigit(raw_width) || !nstr_isdigit(raw_height))
        return (rect);
    rect.top = natoi(raw_top);
    rect.left = natoi(raw_left);
    rect.width = natoi(raw_width);
    rect.height = natoi(raw_height);
    return (rect);
}