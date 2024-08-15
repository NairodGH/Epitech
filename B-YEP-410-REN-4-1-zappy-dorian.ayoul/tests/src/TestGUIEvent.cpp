/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static CommandFixture sc;

TEST(TestGUIEvent, pnw)
{
    char *buff = nullptr;

    sc.startTest();
    command_pnw(sc.getCore(), sc.getClient()->trantorian);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pnw #%s %ld %ld %d %ld %s\n",
        sc.getClient()->trantorian->uuid,
        sc.getClient()->trantorian->pos.x,
        sc.getClient()->trantorian->pos.y,
        (int)sc.getClient()->trantorian->direction,
        sc.getClient()->trantorian->level,
        sc.getClient()->trantorian->team->name) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, pex)
{
    char *buff = nullptr;

    sc.startTest();
    command_pex(sc.getCore(), sc.getClient()->trantorian);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pex %s\n",
        sc.getClient()->trantorian->uuid) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, pbc)
{
    char *buff = nullptr;
    char *msg = strdup("MESSAGE");

    ASSERT_TRUE(msg != nullptr);

    sc.startTest();
    command_pbc(sc.getCore(), sc.getClient()->trantorian, msg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pbc %s %s\n",
        sc.getClient()->trantorian->uuid,
        msg) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    free(msg);
}

TEST(TestGUIEvent, pic)
{
    char *buff = nullptr;
    list_t *list = list_create();

    ASSERT_TRUE(list != nullptr);

    list_push_data(list, (trantorian_t *)sc.getClient()->trantorian);
    list_push_data(list, (trantorian_t *)sc.getOtherCli()->trantorian);

    sc.startTest();
    command_pic(sc.getCore(), sc.getClient()->trantorian, list);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pic %ld %ld %ld %s %s\n",
        sc.getClient()->trantorian->pos.x,
        sc.getClient()->trantorian->pos.y,
        sc.getClient()->trantorian->level,
        sc.getClient()->trantorian->uuid,
        sc.getOtherCli()->trantorian->uuid) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    list_destroy(list, NULL);
}

TEST(TestGUIEvent, pie)
{
    char *buff = nullptr;

    sc.startTest();
    command_pie(sc.getCore(), sc.getClient()->trantorian, true);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pie %ld %ld %d\n",
        sc.getClient()->trantorian->pos.x,
        sc.getClient()->trantorian->pos.y, true) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, pfk)
{
    char *buff = nullptr;

    sc.startTest();
    command_pfk(sc.getCore(), sc.getClient()->trantorian);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pfk %s\n",
        sc.getClient()->trantorian->uuid) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, pdi)
{
    char *buff = nullptr;

    sc.startTest();
    command_pdi(sc.getCore(), sc.getClient()->trantorian);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pdi %s\n",
        sc.getClient()->trantorian->uuid) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, enw)
{
    char *buff = nullptr;
    trantorian_t *egg = trantorian_create(sc.getClient()->trantorian->team, 3, 3, true);

    ASSERT_TRUE(egg != nullptr);

    sc.startTest();
    command_enw(sc.getCore(), sc.getClient()->trantorian, egg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "enw %s %s %ld %ld\n",
        egg->uuid,
        sc.getClient()->trantorian->uuid,
        egg->pos.x,
        egg->pos.y) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    trantorian_destroy(egg);
}

TEST(TestGUIEvent, eht)
{
    char *buff = nullptr;
    trantorian_t *egg = trantorian_create(sc.getClient()->trantorian->team, 3, 3, true);

    ASSERT_TRUE(egg != nullptr);

    sc.startTest();
    command_eht(sc.getCore(), egg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "eht %s\n",
        egg->uuid) != -1);
    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    trantorian_destroy(egg);
}

TEST(TestGUIEvent, ebo)
{
    char *buff = nullptr;
    trantorian_t *egg = trantorian_create(sc.getClient()->trantorian->team, 3, 3, true);

    ASSERT_TRUE(egg != nullptr);

    sc.startTest();
    command_ebo(sc.getCore(), egg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "ebo %s\n",
        egg->uuid) != -1);
    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    trantorian_destroy(egg);
}

TEST(TestGUIEvent, edi)
{
    char *buff = nullptr;
    trantorian_t *egg = trantorian_create(sc.getClient()->trantorian->team, 3, 3, true);

    ASSERT_TRUE(egg != nullptr);

    sc.startTest();
    command_edi(sc.getCore(), egg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "edi %s\n",
        egg->uuid) != -1);
    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    trantorian_destroy(egg);
}

TEST(TestGUIEvent, seg)
{
    char *buff = nullptr;

    sc.startTest();
    command_seg(sc.getCore(), sc.getClient()->trantorian->team);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "seg %s\n",
        sc.getClient()->trantorian->team->name) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
}

TEST(TestGUIEvent, smg)
{
    char *buff = nullptr;
    char *msg = strdup("MESSAGE");

    ASSERT_TRUE(msg != nullptr);

    sc.startTest();
    command_smg(sc.getCore(), msg);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "smg %s\n",
        msg) != -1);

    ASSERT_EQ(sc.getRes(), buff);

    free(buff);
    free(msg);
}
