/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static const token_t delim[] = {
    {" ", "", 1, D_NORMAL, ID_SPACE},
    {"\t", "", 1, D_NORMAL, ID_TAB},
    {"\"", "\"", 1, D_DELIM, ID_DOUBLE_QUOTE},
    {"'", "'", 1, D_DELIM, ID_SIMPLE_QUOTE},
    {"`", "`", 1, D_DELIM, ID_BACK_QUOTE},
    {"(", ")", 1, D_DELIM, ID_PARENTHESE},
    {">>", "", 2, D_GET, ID_DOUBLE_RIGHT},
    {"<<", "", 2, D_GET, ID_DOUBLE_LEFT},
    {">&", "", 2, D_NORMAL, ID_REDIRECTION},
    {"||", "", 2, D_SEPARATOR, ID_OR},
    {"&&", "", 2, D_SEPARATOR, ID_AND},
    {"&", "", 1, D_SEPARATOR, ID_BACKGROUND},
    {";", "", 1, D_SEPARATOR, ID_SEP},
    {"<", "", 1, D_GET, ID_LEFT},
    {">", "", 1, D_GET, ID_RIGHT},
    {"|", "", 1, D_GET, ID_PIPE},

    {NULL, NULL, 0, ID_WITHOUT, ID_WITHOUT},
};

int get_token(char *line, size_t adv)
{
    int result = 0;

    for (; delim[result].token; result++) {
        if (!strncmp(delim[result].token, line + adv,
            delim[result].len_token)) {
            return result;
        }
    }
    return ID_WITHOUT;
}

size_t get_next_elem(char *line, size_t adv, int token, bool *errored)
{
    if (token == ID_WITHOUT)
        adv = get_last_without(line, adv);
    else if (delim[token].id_type == D_DELIM)
        adv = get_end_delim(line, adv, delim[token].end_token, errored);
    else
        adv += delim[token].len_token;
    return adv;
}

list_t *get_pos(char *line)
{
    list_t *result = create_list();
    parser_t *temp_pars = NULL;
    int token = 0;
    bool errored = false;

    for (size_t adv = 0; line[adv] && line[adv] != '\n';) {
        token = get_token(line, adv);
        if (token != ID_WITHOUT && delim[token].id_type == D_NORMAL) {
            adv++;
            continue;
        }
        if (delim[token].id_type == D_DELIM)
            adv++;
        temp_pars = create_parser_and_set_adv(line, &adv, token, &errored);
        if (set_null_node(result, errored, &adv) == true) continue;
        if (!adv) return NULL;
        else temp_pars->len = adv - temp_pars->adv;
        add_node(result, create_node((void *)temp_pars));
        if (delim[token].id_type == D_DELIM) adv++;
    }
    return result;
}

list_t *get_elems(char *line, list_t *pos)
{
    list_t *result = create_list();
    list_node_t *temp_node = NULL;
    parser_t *temp_pars = NULL;
    elem_t *temp_elem = NULL;
    char *temp_str = NULL;
    int token = 0;

    foreach(pos->head, temp_node) {
        temp_pars = (parser_t *)temp_node->data;
        if (!temp_pars)
            temp_str = strdup("\0");
        else
            temp_str = strndup(line + temp_pars->adv, temp_pars->len);
        token = get_token(temp_str, 0);
        temp_elem = create_elem(temp_str,
            token != -1 ? delim[token].id_type : -1,
            token != -1 ? delim[token].id_elem : -1);
        add_node(result, create_node((void *)temp_elem));
    }
    return result;
}

list_t *parser(char *line, return_t *ret)
{
    list_t *pos = NULL;
    list_t *pars = NULL;
    list_t *block = NULL;

    if (!line) {
        ret->is_exited = true;
        return NULL;
    }
    pos = get_pos(line);
    if (!pos)
        return ret_err(ret, 1, false);
    pars = get_elems(line, pos);
    destroy_list(pos, NULL);
    if (pars) {
        block = over_parser(pars);
        destroy_list(pars, destroy_elem);
    }
    return block;
}
