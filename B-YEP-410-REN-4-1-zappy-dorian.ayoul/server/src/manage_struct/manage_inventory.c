/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "inventory.h"

inventory_t *inventory_create(void)
{
    return calloc(1, sizeof(inventory_t));
}

void inventory_destroy(inventory_t *inventory)
{
    if (inventory == NULL)
        return;
    free(inventory);
}
