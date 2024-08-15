/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static const resolver_t resolv_flag[] = {
    {ID_DOUBLE_RIGHT, 1, r_double_right},
    {ID_DOUBLE_LEFT, 1, r_double_left},
    {ID_OR, 0, r_or},
    {ID_AND, 0, r_and},
    {ID_SEP, 0, r_sep},
    {ID_LEFT, 1, r_left},
    {ID_RIGHT, 1, r_right},
    {ID_PIPE, 1, r_pipe},

    {0, 0, NULL}
};

int get_block(int id_type)
{
    int result = 0;

    for (; resolv_flag[result].id_elem != 0; result++) {
        if (resolv_flag[result].id_elem == id_type)
            return result;
    }
    return -1;
}

static list_node_t *skip_nbr(list_node_t *node_temp, size_t to_skip)
{
    size_t nbr = 0;
    list_node_t *result = 0;

    if (!to_skip)
        return node_temp;
    foreach(node_temp, result) {
        if (to_skip == nbr) {
            return result;
        }
        nbr++;
    }
    return node_temp;
}

static void send_resolv(shell_t *shell, list_node_t *node_temp,
    int block_nbr, return_t *ret)
{
    list_node_t *next = node_temp->next;
    list_node_t *last = node_temp->last;
    block_t *next_block = NULL;
    block_t *last_block = NULL;

    if (next)
        next_block = (block_t *)next->data;
    if (last)
        last_block = (block_t *)last->data;
    resolv_flag[block_nbr].resolv_func(shell, ret, last_block, next_block);
}

void resolver(shell_t *shell, return_t *ret)
{
    list_node_t *node_temp = NULL;
    block_t *block_temp = NULL;
    int block_nbr = 0;

    foreach(shell->parsing->head, node_temp) {
        block_temp = (block_t *)node_temp->data;
        if (block_temp->id_type != ID_WITHOUT) {
            block_nbr = get_block(block_temp->id_elem);
            if (block_nbr == ID_WITHOUT)
                continue;
            send_resolv(shell, node_temp, block_nbr, ret);
            node_temp = skip_nbr(node_temp, resolv_flag[block_nbr].to_skip);
        }
    }
}
