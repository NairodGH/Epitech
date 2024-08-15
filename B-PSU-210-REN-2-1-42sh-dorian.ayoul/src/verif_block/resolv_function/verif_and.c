/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

bool verif_and(return_t *ret, block_t *last, block_t *next)
{
    if ((!next || next->id_type != -1) && last) {
        dprintf(STDERR_FILENO, "Invalid null command.\n");
        ret->error_code = 1;
        return 1;
    }
    return 0;
}
