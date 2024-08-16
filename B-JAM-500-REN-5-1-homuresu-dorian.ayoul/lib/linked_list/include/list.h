/*
** EPITECH PROJECT, 2022
** list
** File description:
** include
*/

#ifndef LIST_H
    #define LIST_H

    #define LIST_SUCCESS (0)
    #define LIST_FAILURE (-1)

    #include <stdio.h>
    #include <stdlib.h>

    #define foreach(head, node)                                     \
        for (node = head; node; node = node->next)                  \

    #define foreach_safe(head, node, node2)                         \
        for (node = head, node2 = node ? node->next : NULL;         \
            node; node = node2, node2 = node ? node->next : NULL)   \

typedef struct node_s {
    struct node_s *next;
    struct node_s *prev;
    void *data;
} node_t;

typedef struct list_s {
    size_t lenght;
    node_t *head;
    node_t *tail;
} list_t;

list_t *list_create(void);
node_t *list_create_node(void *data);

int list_push_data(list_t *list, void *data);
void list_push_node(list_t *list, node_t *node);

void list_remove_node(list_t *list, node_t *node);
void *list_pop_last(list_t *list);
void *list_pop_head(list_t *list);
void list_destroy_data_node(list_t *list, void *data,
    void (*destroy_data)(void *));

void list_destroy(list_t *list, void (*destroy_data)(void *data));
void list_destroy_node(node_t *node, void (*destroy_data)(void *data));

void list_print_list(list_t *list, void (*print_data)(void *));

#endif // LIST_H
