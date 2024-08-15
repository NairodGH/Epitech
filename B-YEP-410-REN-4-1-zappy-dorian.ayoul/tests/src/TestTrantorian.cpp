/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestTrantorianAlloc, Test1)
{
    team_t *team = team_create("team1", 5);

    ASSERT_TRUE(team != nullptr);

    trantorian_t *trantorian = trantorian_create(team, 10, 10, true);
    EXPECT_TRUE(trantorian != nullptr);
    EXPECT_TRUE(trantorian->team == team);
    EXPECT_TRUE(trantorian->pos.x < 10);
    EXPECT_TRUE(trantorian->pos.y < 10);

    trantorian_destroy(trantorian);
    team_destroy(team);
}
