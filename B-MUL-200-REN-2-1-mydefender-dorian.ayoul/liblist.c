/*
** EPITECH PROJECT, 2021
** list lib adapted
** File description:
** liblist
*/

#include "my.h"
#include "my_defender.h"

void draw_list(sfRenderWindow *w, list_t *ennemies)
{
    list_t *temp = ennemies;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(w, temp->data->sprite, NULL);
        temp = temp->next;
    }
}

void list_push(list_t **head, game_object_t *data)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return;
    node->data = data;
    node->next = (*head);
    (*head) = node;
}

void list_stack(list_t **head, game_object_t *data)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *temp = (*head);

    if (node == NULL)
        return;
    node->data = data;
    node->next = NULL;
    if ((*head) == NULL)
        (*head) = node;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void list_destroy(list_t *head)
{
    list_t *temp;

    if (head == NULL)
        return;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void list_remove(list_t **head, int index)
{
    list_t *temp = (*head);
    list_t *next = NULL;

    if ((*head) == NULL)
        return;
    if (index == 0) {
        (*head) = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; (temp != NULL) && (i < index - 1); i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}