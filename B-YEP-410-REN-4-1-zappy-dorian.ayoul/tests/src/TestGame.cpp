/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGameAlloc, Basic)
{
    const char *teams[] = {
        "team1",
        "team2",
        "team3",
        "team4",
        "team5",
        "team6",
        "team7",
        "team8",
        "team9",
        "team10",
        NULL
    };
    game_t *game = game_create((char **)teams, 10, 10, 1);

    EXPECT_TRUE(game != nullptr);
    game_destroy(game);
}
