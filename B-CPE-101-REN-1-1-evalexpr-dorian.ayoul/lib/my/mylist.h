/*
** EPITECH PROJECT, 2020
** mylist.h
** File description:
** header for list structures
*/

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
}linked_list_t;