/*
** EPITECH PROJECT, 2022
** ex0a.c
** File description:
** first exercises of task 0
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    size_t size = 0;

    for (; list; size++)
        list = list->next;
    return size;
}

bool int_list_is_empty(int_list_t list)
{
    if (!list)
        return true;
    else
        return false;
}

void int_list_dump(int_list_t list)
{
    while (list) {
        printf("%d\n", list->value);
        list = list->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new = malloc(sizeof(int_node_t));

    if (!new)
        return false;
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new = malloc(sizeof(int_node_t));
    int_list_t tmp = *front_ptr;

    if (!new)
        return false;
    new->value = elem;
    new->next = NULL;
    if (!(*front_ptr))
        *front_ptr = new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    return true;
}