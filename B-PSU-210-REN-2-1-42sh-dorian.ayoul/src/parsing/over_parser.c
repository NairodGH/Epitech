/*
** EPITECH PROJECT, 2021
** The parsing over to get blocks of ID_WITHOUT
** File description:
** over_parser
*/

#include "42sh.h"

list_node_t *set_strings(list_node_t *temp, block_t *block, size_t streak)
{
    list_node_t *save = NULL;
    elem_t *temp_elem = NULL;

    for (size_t i = 0; i != streak; i++, temp = temp->next) {
        temp_elem = (elem_t *)temp->data;
        block->cmd_block[i] = strdup(temp_elem->elem);
        if (!block->cmd_block[i])
            return NULL;
        save = temp;
    }
    return save;
}

size_t get_streak_len(list_node_t *parsed)
{
    size_t streak = 0;
    list_node_t *temp_node = parsed;
    elem_t *temp_elem = NULL;

    for (; temp_node != NULL; temp_node = temp_node->next) {
        temp_elem = (elem_t *)temp_node->data;
        if (temp_elem->id_type != ID_WITHOUT)
            return streak;
        else
            streak++;
    }
    return streak;
}

static block_t *set_streak_and_block(size_t *len, elem_t *elem, list_node_t *n)
{
    (*len) = get_streak_len(n);
    return create_elem_block(elem, *len);
}

list_t *get_all_blocks(list_t *parsed)
{
    list_t *cmd_block = create_list();
    list_node_t *temp_node = NULL;
    elem_t *temp_elem = NULL;
    block_t *temp_block = NULL;
    size_t streak = 0;

    foreach(parsed->head, temp_node) {
        temp_elem = (elem_t *)temp_node->data;
        if (temp_elem->id_type == ID_WITHOUT) {
            temp_block = set_streak_and_block(&streak, temp_elem, temp_node);
            temp_node = set_strings(temp_node, temp_block, streak);
        }
        else
            temp_block = create_elem_block(temp_elem, strlen(temp_elem->elem));
        if (temp_block->separator == NULL && temp_block->cmd_block == NULL)
            return NULL;
        add_node(cmd_block, create_node((void *)temp_block));
        if (!temp_node) break;
    }
    return cmd_block;
}

list_t *over_parser(list_t *parsed)
{
    list_t *blocks = get_all_blocks(parsed);
    list_node_t *temp_node = NULL;
    block_t *temp_block = NULL;

    if (!blocks)
        return NULL;
    foreach(blocks->head, temp_node) {
        temp_block = (block_t *)temp_node->data;
        if (temp_block->id_type == D_SEPARATOR)
            temp_node = delete_excess(blocks, temp_node);
        if (!temp_node)
            break;
    }
    set_bool_fd(blocks);
    return blocks;
}
