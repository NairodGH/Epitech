/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestInventoryAlloc, Test1)
{
    inventory_t *inventory = inventory_create();

    EXPECT_TRUE(inventory != nullptr);
    inventory_destroy(inventory);
}
