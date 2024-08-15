/*
** EPITECH PROJECT, 2020
** verif_block
** File description:
** verif_block
*/

#include "42sh.h"

static const block_verif_t block_verif[] = {
    {ID_DOUBLE_RIGHT, verif_left_right},
    {ID_DOUBLE_LEFT, verif_left_right},
    {ID_OR, verif_or},
    {ID_AND, verif_and},
    {ID_LEFT, verif_left_right},
    {ID_RIGHT, verif_left_right},
    {ID_PIPE, verif_pipe},

    {0, NULL}
};

static int find_block_verif(int id)
{
    for (int i = 0; block_verif[i].id_elem; i++)
        if (id == block_verif[i].id_elem)
            return i;
    return -1;
}

static bool check_ambiguous(block_t *block, int last_elem)
{
    if (last_elem == block->id_elem && last_elem == ID_PIPE)
        return 0;
    if ((last_elem == ID_LEFT || last_elem == ID_DOUBLE_LEFT) &&
        (block->id_elem != ID_LEFT && block->id_elem != ID_DOUBLE_LEFT))
        return 0;
    if ((block->id_elem == ID_RIGHT || block->id_elem == ID_DOUBLE_RIGHT) &&
        (last_elem != ID_RIGHT && last_elem != ID_DOUBLE_RIGHT))
        return 0;
    if ((last_elem == ID_RIGHT || last_elem == ID_DOUBLE_RIGHT) &&
        (block->id_elem == ID_LEFT || block->id_elem == ID_DOUBLE_LEFT))
        return 0;
    return 1;
}

static void print_ambiguous(block_t *block, int last_elem)
{
    if (block->id_elem == ID_LEFT || block->id_elem == ID_DOUBLE_LEFT ||
        last_elem == ID_LEFT || last_elem == ID_DOUBLE_LEFT)
        dprintf(STDERR_FILENO, "Ambiguous input redirect.\n");
    else
        dprintf(STDERR_FILENO, "Ambiguous output redirect.\n");
}

static bool verif_get(shell_t *shell, return_t *ret)
{
    list_node_t *temp_node = NULL;
    block_t *temp_block = NULL;
    int last_type = ID_WITHOUT;
    int last_elem = ID_WITHOUT;

    foreach(shell->parsing->head, temp_node) {
        temp_block = (block_t *)temp_node->data;
        if (temp_block->id_type == D_GET && temp_block->id_type == last_type &&
            check_ambiguous(temp_block, last_elem)) {
            print_ambiguous(temp_block, last_elem);
            ret->error_code = 1;
            return 1;
        }
        if (temp_block->id_type != ID_WITHOUT) {
            last_type = temp_block->id_type;
            last_elem = temp_block->id_elem;
        }
    }
    return 0;
}

bool verif_block(shell_t *shell, return_t *ret)
{
    list_node_t *temp_node = NULL;
    block_t *temp_block = NULL;
    block_t *last = NULL;
    block_t *next = NULL;
    int id = 0;

    foreach(shell->parsing->head, temp_node) {
        temp_block = (block_t *)temp_node->data;
        id = find_block_verif(temp_block->id_elem);
        if (temp_node->last)
            last = (block_t *)temp_node->last->data;
        if (temp_node->next)
            next = (block_t *)temp_node->next->data;
        if (id != -1)
            if (block_verif[id].func(ret, last, next))
                return 1;
        last = NULL;
        next = NULL;
    }
    return verif_get(shell, ret);
}
