/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGameCalcAngle, Basic1)
{
    pos_t pos_a = {0, 0};
    pos_t pos_b = {3, 4};

    EXPECT_EQ(game_calc_angle_degrees(&pos_a, &pos_b), 323);
}

TEST(TestGameCalcAngle, Basic2)
{
    pos_t pos_a = {0, 0};
    pos_t pos_b = {3, -4};

    EXPECT_EQ(game_calc_angle_degrees(&pos_a, &pos_b), 216);
}

TEST(TestGameCalcAngle, Basic3)
{
    pos_t pos_a = {0, 0};
    pos_t pos_b = {-3, -4};

    EXPECT_EQ(game_calc_angle_degrees(&pos_a, &pos_b), 143);
}

TEST(TestGameCalcAngle, Basic4)
{
    pos_t pos_a = {0, 0};
    pos_t pos_b = {-3, 4};

    EXPECT_EQ(game_calc_angle_degrees(&pos_a, &pos_b), 36);
}

TEST(TestGameCalcVectorCoord, SimpleTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {1, 4};
    pos_t b = {7, 2};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 4);
    EXPECT_EQ(res->y, 2);

    free(res);
}

TEST(TestGameCalcVectorCoord, DifferentPathTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {3, 9};
    pos_t b = {7, 6};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, -4);
    EXPECT_EQ(res->y, 3);

    free(res);
}

TEST(TestGameCalcVectorCoord, InvertCoord)
{
    pos_t map_size = {10, 10};
    pos_t a = {7, 6};
    pos_t b = {3, 9};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 4);
    EXPECT_EQ(res->y, -3);

    free(res);
}

TEST(TestGameCalcVectorCoord, SameCoord)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 5};
    pos_t b = {5, 5};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, 0);

    free(res);
}

TEST(TestGameCalcVectorCoord, SameAxe)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 4};
    pos_t b = {5, 8};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, -4);

    free(res);
}
