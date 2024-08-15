/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** include
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

typedef struct {
    size_t nbr_elem;
    node_t *head;
    void (*free_data)(void *);
} linked_list_t;

// Manage node
node_t *create_node(void *data);
void destroy_node(node_t *node, void (*free_data)(void *));

// Manage linked list
linked_list_t *create_linked_list(void);
void destroy_linked_list(linked_list_t *list);

// Manage list
void emplace_back_list(linked_list_t *list, node_t *node);
void push_list(linked_list_t *list, node_t *node);
node_t *pop_list(linked_list_t *list);

#endif //LINKED_LIST_H
