/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestMapAlloc, Test1)
{
    map_t *map = map_create(5, 5);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);
    map_destroy(map);
}

TEST(TestMapDispatch, Basic)
{
    map_t *map = map_create(5, 5);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25; i++) {
        EXPECT_TRUE(map->map[i]->food == 0 || map->map[i]->food == 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25; i++) {
        EXPECT_TRUE(map->map[i]->food == 0 || map->map[i]->food == 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25; i++) {
        EXPECT_TRUE(map->map[i]->food == 1 || map->map[i]->food == 2);
    }

    map_destroy(map);
}

TEST(TestMapDispatch, LittleMap)
{
    map_t *map = map_create(2, 2);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 4; i++) {
        EXPECT_TRUE(map->map[i]->food == 0 || map->map[i]->food == 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 4; i++) {
        EXPECT_EQ(map->map[i]->food, 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 4; i++) {
        EXPECT_TRUE(map->map[i]->food == 1 || map->map[i]->food == 2);
    }

    map_destroy(map);
}

TEST(TestMapDispatch, BigMap)
{
    map_t *map = map_create(500, 500);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25000; i++) {
        EXPECT_TRUE(map->map[i]->food == 0 || map->map[i]->food == 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25000; i++) {
        EXPECT_EQ(map->map[i]->food, 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 25000; i++) {
        EXPECT_TRUE(map->map[i]->food == 1 || map->map[i]->food == 2);
    }

    map_destroy(map);
}

TEST(TestMapDispatch, RectangleMap)
{
    map_t *map = map_create(300, 100);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 3000; i++) {
        EXPECT_TRUE(map->map[i]->food == 0 || map->map[i]->food == 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 3000; i++) {
        EXPECT_EQ(map->map[i]->food, 1);
    }

    game_dispatch_ressources(NULL, map);
    for (size_t i = 0; i < 3000; i++) {
        EXPECT_TRUE(map->map[i]->food == 1 || map->map[i]->food == 2);
    }

    map_destroy(map);
}
