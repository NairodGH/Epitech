/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static CommandFixture sc;

TEST(TestGUIProtocol, suc)
{
    char *expect = nullptr;

    sc.startTest();
    command_suc(sc.getCore(), sc.getClient());
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "suc\n");
}

TEST(TestGUIProtocol, sbp)
{
    char *expect = nullptr;

    sc.startTest();
    command_sbp(sc.getCore(), sc.getClient());
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, msz)
{
    char *expect = nullptr;

    sc.startTest();
    command_msz(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "msz 3 3\n");
}

TEST(TestGUIProtocol, bct1)
{
    map_t *map = sc.getCore()->game->map;
    char *command = strdup("0 1\n");

    ASSERT_TRUE(command != nullptr);

    GET_CELL(map, 0, 1)->food = 1;
    GET_CELL(map, 0, 1)->linemate = 2;
    GET_CELL(map, 0, 1)->deraumere = 3;
    GET_CELL(map, 0, 1)->sibur = 4;
    GET_CELL(map, 0, 1)->mendiane = 5;
    GET_CELL(map, 0, 1)->phiras = 6;
    GET_CELL(map, 0, 1)->thystame = 7;

    sc.startTest();
    command_bct(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "bct 0 1 1 2 3 4 5 6 7\n");
    free(command);
}

TEST(TestGUIProtocol, bct2)
{
    map_t *map = sc.getCore()->game->map;
    char *command = strdup("2 2\n");

    ASSERT_TRUE(command != nullptr);

    GET_CELL(map, 2, 2)->food = 1;
    GET_CELL(map, 2, 2)->linemate = 2;
    GET_CELL(map, 2, 2)->deraumere = 3;
    GET_CELL(map, 2, 2)->sibur = 4;
    GET_CELL(map, 2, 2)->mendiane = 5;
    GET_CELL(map, 2, 2)->phiras = 6;
    GET_CELL(map, 2, 2)->thystame = 7;

    sc.startTest();
    command_bct(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "bct 2 2 1 2 3 4 5 6 7\n");
    free(command);
}

TEST(TestGUIProtocol, bctIncorrect1)
{
    char *command = strdup("-10 1\n");

    ASSERT_TRUE(command != nullptr);

    sc.startTest();
    command_bct(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, bctIncorrect2)
{
    char *command = strdup("100000000 1\n");

    ASSERT_TRUE(command != nullptr);

    sc.startTest();
    command_bct(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, mct)
{
    sc.startTest();
    command_mct(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    ASSERT_EQ(sc.getRes(),
        "bct 0 0 0 0 0 0 0 0 0\n"
        "bct 1 0 0 0 0 0 0 0 0\n"
        "bct 2 0 0 0 0 0 0 0 0\n"
        "bct 0 1 1 2 3 4 5 6 7\n"
        "bct 1 1 0 0 0 0 0 0 0\n"
        "bct 2 1 0 0 0 0 0 0 0\n"
        "bct 0 2 0 0 0 0 0 0 0\n"
        "bct 1 2 0 0 0 0 0 0 0\n"
        "bct 2 2 1 2 3 4 5 6 7\n"
    );
}

TEST(TestGUIProtocol, tna)
{
    sc.startTest();
    command_tna(sc.getCore(), sc.getClient(), NULL);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "tna team1\n");
}

TEST(TestGUIProtocol, ppo)
{
    char *expected = NULL;

    sc.startTest();
    command_ppo(sc.getCore(), sc.getClient(), sc.getClient()->trantorian->uuid);
    sc.endTest();

    ASSERT_TRUE(asprintf(&expected, "ppo %s %ld %ld %d\n",
        sc.getClient()->trantorian->uuid,
        sc.getClient()->trantorian->pos.x,
        sc.getClient()->trantorian->pos.y,
        (int)sc.getClient()->trantorian->direction
    ) != -1);

    ASSERT_EQ(sc.getRes(), expected);
    free(expected);
}

TEST(TestGUIProtocol, ppoIncorrect)
{
    char *command = strdup("scsq\n");

    ASSERT_TRUE(command != nullptr);

    sc.startTest();
    command_ppo(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, plv)
{
    char *expected = NULL;

    sc.startTest();
    command_plv(sc.getCore(), sc.getClient(), sc.getClient()->trantorian->uuid);
    sc.endTest();

    ASSERT_TRUE(asprintf(&expected, "plv %s %ld\n",
        sc.getClient()->trantorian->uuid,
        sc.getClient()->trantorian->level
    ) != -1);

    ASSERT_EQ(sc.getRes(), expected);
    free(expected);
}

TEST(TestGUIProtocol, plvIncorrect)
{
    char *command = strdup("scsq\n");

    ASSERT_TRUE(command != nullptr);

    sc.startTest();
    command_plv(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, pin)
{
    char *expected = NULL;

    sc.getClient()->trantorian->inventory->food = 1;
    sc.getClient()->trantorian->inventory->linemate = 2;
    sc.getClient()->trantorian->inventory->deraumere = 3;
    sc.getClient()->trantorian->inventory->sibur = 4;
    sc.getClient()->trantorian->inventory->mendiane = 5;
    sc.getClient()->trantorian->inventory->phiras = 6;
    sc.getClient()->trantorian->inventory->thystame = 7;

    sc.startTest();
    command_pin(sc.getCore(), sc.getClient(), sc.getClient()->trantorian->uuid);
    sc.endTest();

    ASSERT_TRUE(asprintf(&expected, "pin %s %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
        sc.getClient()->trantorian->uuid,
        sc.getCore()->game->map->width, sc.getCore()->game->map->height,
        sc.getClient()->trantorian->inventory->food,
        sc.getClient()->trantorian->inventory->linemate,
        sc.getClient()->trantorian->inventory->deraumere,
        sc.getClient()->trantorian->inventory->sibur,
        sc.getClient()->trantorian->inventory->mendiane,
        sc.getClient()->trantorian->inventory->phiras,
        sc.getClient()->trantorian->inventory->thystame
    ) != -1);

    ASSERT_EQ(sc.getRes(), expected);
    free(expected);
}

TEST(TestGUIProtocol, pinIncorrect)
{
    char *command = strdup("");

    ASSERT_TRUE(command != nullptr);

    sc.startTest();
    command_pin(sc.getCore(), sc.getClient(), command);
    sc.endTest();

    ASSERT_EQ(sc.getRes(), "sbp\n");
}

TEST(TestGUIProtocol, sgt)
{
    char *expected = NULL;

    sc.startTest();
    command_sgt(sc.getCore(), sc.getClient(), sc.getClient()->trantorian->uuid);
    sc.endTest();

    ASSERT_TRUE(asprintf(&expected, "sgt %ld\n",
        sc.getCore()->game->freq
    ) != -1);

    ASSERT_EQ(sc.getRes(), expected);
    free(expected);
}
