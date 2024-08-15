/*
** EPITECH PROJECT, 2021
** funcs to handle some basic error cases
** File description:
** err_case
*/

#include "42sh.h"

bool set_null_node(list_t *result, bool errored, size_t *adv)
{
    if (errored == false)
        return false;
    add_node(result, create_node(NULL));
    (*adv)++;
    return true;
}

void *ret_err(return_t *ret, int err_code, bool is_exited)
{
    ret->error_code = err_code;
    ret->is_exited = is_exited;
    return NULL;
}
