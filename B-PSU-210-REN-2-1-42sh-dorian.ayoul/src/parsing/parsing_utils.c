/*
** EPITECH PROJECT, 2021
** utils funcs
** File description:
** parsing_utils
*/

#include "42sh.h"

char *set_coma(char *line)
{
    int status = 0;
    char *dup = NULL;
    char *result = NULL;

    if (!line)
        return NULL;
    dup = copy_from_to(line, 0, '\n');
    if (!dup)
        return NULL;
    status = asprintf(&result, "%s%c", dup, ';');
    free(line);
    free(dup);
    if (status == -1)
        return NULL;
    return result;
}

list_node_t *delete_excess(list_t *blocks, list_node_t *temp_node)
{
    block_t *temp_cast = NULL;
    list_node_t *last_save = NULL;

    temp_node = temp_node->next;
    if (!temp_node)
        return NULL;
    temp_cast = (block_t *)temp_node->data;
    while (temp_cast->id_type == D_SEPARATOR && temp_node) {
        last_save = temp_node->last;
        remove_node(blocks, temp_node);
        temp_node = last_save->next;
        if (!temp_node)
            return NULL;
        temp_cast = (block_t *)temp_node->data;
    }
    return temp_node;
}

void set_bool_fd(list_t *blocks)
{
    list_node_t *temp_node = NULL;
    block_t *temp_block = NULL;

    foreach(blocks->head, temp_node) {
        temp_block = (block_t *)temp_node->data;
        if (temp_block->id_type == D_GET &&
        temp_block->id_elem != ID_DOUBLE_LEFT &&
        temp_block->id_elem != ID_LEFT && temp_node->last) {
            temp_block = (block_t *)temp_node->last->data;
            temp_block->need_fd = true;
        }
        else
            temp_block->need_fd = false;
        if (!temp_node)
            break;
    }
}