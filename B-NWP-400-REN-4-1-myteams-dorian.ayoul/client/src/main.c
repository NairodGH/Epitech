/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "client.h"

void sig_handler_c(__attribute__((unused)) int signum)
{
    bool *is_end = get_value();
    (*is_end) = true;
}

bool parse_arg(arg_t *arg, char **av)
{
    struct sockaddr_in sa;
    int result = 0;

    arg->port = atoi(av[2]);
    if (arg->port == 0)
        return false;
    result = inet_pton(AF_INET, av[1], &(sa.sin_addr));
    if (result == 0) {
        printf("Bad ip\n");
        return false;
    }
    arg->ip = av[1];
    return true;
}

bool get_arg(arg_t *arg, int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            printf("USAGE: ./myteams_cli ip port\n\n\tip    "
            "is the server ip address on which the server socket listens\n\t"
            "port  is the port number on which the server socket listens\n");
            free(arg);
            exit(0);
        }
        free(arg);
        return false;
    }
    if (ac > 3) {
        free(arg);
        return false;
    }
    if (!parse_arg(arg, av)) {
        free(arg);
        return false;
    }
    return true;
}

int main(int ac, char **av)
{
    arg_t *arg = malloc(sizeof(arg_t));

    if (!arg || !get_arg(arg, ac, av)) {
        printf("Bad arg\n");
        return 84;
    }
    signal(SIGINT, sig_handler_c);
    init_client(arg);
    free(arg);
    return 0;
}
