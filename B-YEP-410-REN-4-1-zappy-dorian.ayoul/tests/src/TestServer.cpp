/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestServerAlloc, Test1)
{
    server_t *server = server_create(3000);

    ASSERT_TRUE(server != nullptr);
    EXPECT_TRUE(server->port == 3000);
    EXPECT_TRUE(server->socket != nullptr);
    server_destroy(server);
}
