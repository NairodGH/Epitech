/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static void free_argv(char **argv)
{
    for (int i = 0; argv[i] != nullptr; i++)
        free(argv[i]);
    free(argv);
}

TEST(TestParseParams, MultipleTeams)
{
    int argc = 4;
    char **argv = (char **)calloc(argc + 1, sizeof(char *));

    ASSERT_TRUE(argv != nullptr);

    argv[0] = strdup("./serv");
    ASSERT_TRUE(argv[0] != nullptr);
    argv[1] = strdup("-n");
    ASSERT_TRUE(argv[1] != nullptr);
    argv[2] = strdup("team1");
    ASSERT_TRUE(argv[2] != nullptr);
    argv[3] = strdup("team2");
    ASSERT_TRUE(argv[3] != nullptr);

    args_t *args = init_args();
    ASSERT_TRUE(args != nullptr);

    ASSERT_TRUE(parse_params(argc, argv, args) == SUCCESS);
    free_argv(argv);
    destroy_args(args);
}

TEST(TestParseParams, NoTeam)
{
    int argc = 4;
    char **argv = (char **)calloc(argc + 1, sizeof(char *));

    ASSERT_TRUE(argv != nullptr);

    argv[0] = strdup("./serv");
    ASSERT_TRUE(argv[0] != nullptr);
    argv[1] = strdup("-p");
    ASSERT_TRUE(argv[1] != nullptr);
    argv[2] = strdup("8080");
    ASSERT_TRUE(argv[2] != nullptr);

    args_t *args = init_args();
    ASSERT_TRUE(args != nullptr);

    ASSERT_TRUE(parse_params(argc, argv, args) == SUCCESS);
    ASSERT_TRUE(verif_params(args) == ERROR);
    free_argv(argv);
    destroy_args(args);
}
