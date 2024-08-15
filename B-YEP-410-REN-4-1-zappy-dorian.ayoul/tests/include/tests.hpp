/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#ifndef GOOGLE_TESTS_HPP
    #define GOOGLE_TESTS_HPP

    #include <gtest/gtest.h>

    extern "C" {
        #include "client.h"
        #include "core.h"
        #include "game.h"
        #include "inventory.h"
        #include "map.h"
        #include "server.h"
        #include "team.h"
        #include "trantorian.h"
        #include "utils.h"
    }

class CommandFixture
{
    public:
        CommandFixture();
        ~CommandFixture();

        void addClient(void);

        void coreCreate(args_t *args);

        void startTestSingleClient(client_t *cli, int pipeCli[2]);
        void startTest(void);
        void endTest(void);

        std::string getRes(void);
        std::string getResOtherCli(void);

        core_t *getCore(void);
        client_t *getClient(void);
        client_t *getOtherCli(void);

    private:
        core_t *core;
        client_t *client;
        client_t *otherPlayer;

        int pipefd[2] = {0};
        int pipefdOther[2] = {0};
        fd_set writefds = {0};
        fd_set readfds = {0};
        std::string res;
        std::string resOtherCli;
};

#endif /* GOOGLE_TESTS_HPP */
