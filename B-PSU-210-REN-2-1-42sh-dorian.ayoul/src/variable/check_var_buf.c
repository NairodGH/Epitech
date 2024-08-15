/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

size_t get_next_pos(char *buffer, size_t adv)
{
    for (int id = ID_WITHOUT; id == ID_WITHOUT && buffer[adv] != '\0'; adv++)
        id = get_token(buffer, adv);
    return adv -= 1;
}

static char *place_var_value(char *buffer, char *var_name,
    char *var_value, size_t replace)
{
    char *first_part = strndup(buffer, replace);
    char *second_part = strdup(buffer + replace + strlen(var_name) + 1);
    char *result = NULL;

    if (!first_part || !second_part)
        return NULL;
    if (asprintf(&result, "%s%s%s", first_part,
        var_value, second_part) == -1 || !result)
        return NULL;
    free(first_part);
    free(second_part);
    free(buffer);
    return result;
}

static char *get_var_cara(shell_t *shell, return_t *ret,
    char *readed, size_t adv)
{
    char *var_name = dup_no_junk(readed + (adv + 1), get_next_pos(readed, adv));
    char *var_value = NULL;

    if (!var_name) {
        ret->is_exited = 1;
        return NULL;
    }
    if (!(var_value = get_var_value(shell->variable, var_name))) {
        error_command(var_name, "Undefined variable");
        free(var_name);
        ret->error_code = 1;
        free(readed);
        return strdup(" ");
    }
    if (!(readed = place_var_value(readed, var_name, var_value, adv))) {
        ret->is_exited = 1;
        return NULL;
    }
    free(var_name);
    return readed;
}

char *check_var_buf(shell_t *shell, return_t *ret, char *readed)
{
    if (!readed)
        return NULL;
    for (size_t adv = 0; readed[adv]; adv++) {
        if (!strncmp(readed + adv, "$", strlen("$"))) {
            readed = get_var_cara(shell, ret, readed, adv);
            if (!readed)
                return NULL;
            adv = get_next_pos(readed, adv);
        }
    }
    return readed;
}
