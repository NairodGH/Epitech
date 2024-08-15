/*
** EPITECH PROJECT, 2022
** ex0b.c
** File description:
** more exercises of task 0
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem, unsigned int
position)
{
    int_list_t new = malloc(sizeof(int_node_t));
    int_list_t tmp = *front_ptr;

    if (!new || position > int_list_get_size(*front_ptr))
        return false;
    new->value = elem;
    new->next = NULL;
    if (position == 0) {
        int_list_add_elem_at_front(front_ptr, elem);
        return true;
    }
    for (size_t i = 1; i < position; i++)
        tmp = tmp->next;
    new->next = tmp->next;
    tmp->next = new;
    return true;
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (!list)
        return 0;
    else
        return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t tmp = list;

    if (!list)
        return 0;
    else {
        while (tmp->next)
            tmp = tmp->next;
        return tmp->value;
    }
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_list_t tmp = list;

    if (!list || position > int_list_get_size(list))
        return 0;
    else {
        for (size_t i = 0; i < position; i++)
            tmp = tmp->next;
        return tmp->value;
    }
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;

    *front_ptr = (*front_ptr)->next;
    free(tmp);
}