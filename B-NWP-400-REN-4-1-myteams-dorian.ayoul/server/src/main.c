/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "server.h"

void sig_handler(__attribute__((unused)) int signum)
{
    bool *is_end = get_value();
    
    (*is_end) = true;
}

int get_arg(int ac, char **av)
{
    int port = 0;

    if (ac != 2) {
        printf("Bad <port> arguments\n");
        return -1;
    }
    if (strcmp(av[1], "-help") == 0) {
        printf("USAGE: ./myteams_server port\n\n\t"
        "port is the port number on which the server socket listens.\n");
        return 0;
    }
    port = atoi(av[1]);
    if (port == 0) {
        printf("Bad port arguments\n");
        return -1;
    }
    return port;
}

int main(int ac, char **av)
{
    int port = get_arg(ac, av);

    if (port == 0)
        return 0;
    if (port == -1)
        return 84;
    signal(SIGINT, sig_handler);
    init_server(port);
    return 0;
}
