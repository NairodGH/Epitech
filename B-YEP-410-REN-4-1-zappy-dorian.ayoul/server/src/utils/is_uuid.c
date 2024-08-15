/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

bool is_uuid(char *str)
{
    regex_t regex = {0};
    bool res = false;

    if (regcomp(&regex, "^[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-"
            "[0-9a-fA-F]{4}-[0-9a-fA-F]{12}$", REG_EXTENDED) != 0)
        return false;
    if (regexec(&regex, str, 0, NULL, 0) == 0) {
        res = true;
    }
    regfree(&regex);
    return res;
}
