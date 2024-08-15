/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef INVENTORY_H
    #define INVENTORY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct {
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} inventory_t;

inventory_t *inventory_create(void);
void inventory_destroy(inventory_t *inventory);

#endif // INVENTORY_H
