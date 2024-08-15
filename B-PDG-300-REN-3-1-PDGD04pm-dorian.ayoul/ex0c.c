/*
** EPITECH PROJECT, 2022
** ex0c.c
** File description:
** final exercises of task 0
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;

    if (!tmp)
        return false;
    else {
        if (!tmp->next) {
            int_list_del_elem_at_front(front_ptr);
            return true;
        }
        while (tmp->next->next)
            tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
    }
    return true;
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t tmp = *front_ptr;
    int_list_t tmp2;

    if (!tmp || position > int_list_get_size(tmp))
        return false;
    else {
        for (size_t i = 0; i < position - 1; i++)
            tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp2);
    }
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    while (*front_ptr)
        int_list_del_elem_at_back(front_ptr);
}