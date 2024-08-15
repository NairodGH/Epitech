/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestCoreAlloc, Test1)
{
    core_t *core = core_create();

    EXPECT_TRUE(core != nullptr);
    core_destroy(core);
}
