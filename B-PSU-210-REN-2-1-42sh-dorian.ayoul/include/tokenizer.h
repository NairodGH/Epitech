/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "return.h"
#include "block.h"

typedef struct {
    size_t adv;
    size_t len;
} parser_t;

typedef struct {
    char *elem;
    int id_type;
    int id_elem;
} elem_t;

typedef enum {
    D_NORMAL,
    D_DELIM,
    D_GET,
    D_SEPARATOR
} id_type_t;

typedef enum {
    ID_WITHOUT = -1,
    ID_SPACE,
    ID_TAB,
    ID_DOUBLE_QUOTE,
    ID_SIMPLE_QUOTE,
    ID_BACK_QUOTE,
    ID_PARENTHESE,
    ID_DOUBLE_RIGHT,
    ID_RIGHT,
    ID_DOUBLE_LEFT,
    ID_LEFT,
    ID_OR,
    ID_AND,
    ID_SEP,
    ID_PIPE,
    ID_BACKGROUND,
    ID_REDIRECTION
} id_elem_t;

typedef struct {
    char *token;
    char *end_token;
    size_t len_token;
    int id_type;
    int id_elem;
} token_t;

int get_token(char *line, size_t adv);

// CREATE ELEMS
parser_t *create_parser(size_t adv, size_t len);
elem_t *create_elem(char *elem, int id_type, int id_elem);
block_t *create_elem_block(elem_t *elem, size_t alloc_size);

// DESTROY ELEMS
void destroy_elem(void *elem);
void destroy_elem_block(void *block);
list_node_t *delete_excess(list_t *blocks, list_node_t *temp_node);

// GET POS
size_t get_last_without(char *line, size_t adv);
int get_end_delim(char *line, size_t adv, char *end_delim, bool *errored);
size_t get_next_elem(char *line, size_t adv, int token, bool *errored);
list_t *get_pos(char *line);
bool set_null_node(list_t *result, bool errored, size_t *adv);

// GET ELEM
list_t *get_elems(char *line, list_t *pos);
list_t *parser(char *line, return_t *ret);
list_t *over_parser(list_t *parsed);

// ERR GESTION
void *ret_err(return_t *ret, int err_code, bool is_exited);
parser_t *create_parser_and_set_adv(char *str, size_t *adv, int token, bool *r);
void set_bool_fd(list_t *blocks);
char *set_coma(char *line);

#endif // TOKENIZER_H
