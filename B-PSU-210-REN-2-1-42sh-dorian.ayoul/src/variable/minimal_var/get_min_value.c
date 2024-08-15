/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

variable_t *get_status(void)
{
    variable_t *var = create_variable(strdup("status"), strdup("0"), 0);

    var->alias = badd_array(var->alias, strdup("?"));
    return var;
}
