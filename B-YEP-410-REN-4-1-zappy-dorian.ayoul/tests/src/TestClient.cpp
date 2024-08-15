/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestClientAlloc, Test1)
{
    client_t *client = client_create(0);

    EXPECT_TRUE(client != nullptr);
    EXPECT_TRUE(client->sock->fd == 0);
    client_destroy(client);
}

static char *get_uuid_str(void)
{
    uuid_t uuid;
    char *uuid_str = nullptr;

    uuid_generate_time_safe(uuid);
    uuid_str = (char *)calloc(UUID_STR_LEN, sizeof(char));
    uuid_unparse(uuid, uuid_str);
    return uuid_str;
}

TEST(TestClientLogin, GUILogin)
{
    client_t *client = client_create(0);

    EXPECT_TRUE(client != nullptr);
    EXPECT_TRUE(client->sock->fd == 0);

    char *uuid = get_uuid_str();

    client_define_type(NULL, client, uuid);

    EXPECT_TRUE(client->type == CLI_GUI);

    free(uuid);
    client_destroy(client);
}
