/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static bool parenthesis_validity_check(char *line, size_t adv)
{
    int open_par = 0;
    int closing_par = 0;

    for (; line[adv] != '\n' && line[adv] != '\0'; adv++) {
        if (line[adv] == '(')
            open_par++;
        if (line[adv] == ')')
            closing_par++;
    }
    if (open_par == closing_par)
        return true;
    else if (open_par > closing_par)
        bprintf("Too many ('s.\n");
    else
        bprintf("Too many )'s.\n");
    return false;
}

size_t get_last_without(char *line, size_t adv)
{
    for (; line[adv] && line[adv] != '\n'; adv++) {
        if (get_token(line, adv) != -1) {
            return adv;
        }
    }
    return adv;
}

int get_end_delim(char *line, size_t adv, char *end_delim, bool *errored)
{
    size_t len_delim = strlen(end_delim);

    if (line[adv] == end_delim[0]) {
        *errored = true;
        return adv;
    }
    if (line[adv] == '(') {
        if (parenthesis_validity_check(line, adv) == false)
            return 0;
    }
    for (adv++; line[adv] && line[adv] != '\n'; adv++) {
        if (!bstrncmp(line + adv, end_delim, len_delim)) {
            return adv;
        }
    }
    bprintf("Unmatched '%c'.\n", end_delim[0]);
    return 0;
}

parser_t *create_parser_and_set_adv(char *str, size_t *adv, int token, bool *r)
{
    parser_t *temp_pars = NULL;

    temp_pars = create_parser(*adv, 0);
    (*adv) = get_next_elem(str, *adv, token, r);
    return temp_pars;
}
