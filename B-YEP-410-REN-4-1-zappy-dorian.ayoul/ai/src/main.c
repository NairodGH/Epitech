/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main ai
*/

#include "zappy_ai.h"

static void print_usage(void)
{
    fprintf(stderr, "%sUSAGE: ./zappy_ai -p port -n name -h machine\n\t"
        "port is the port number\n\tname is the name of the team\n\t"
        "machine is the name of the machine; localhost by default\n%s", G, W);
}

bool verif_arg(arg_t *arg)
{
    struct sockaddr_in sa;

    if (arg->name == NULL || arg->port == -1) {
        if (arg->name == NULL)
            fprintf(stderr, "%s[ERROR]%s Miss name -n\n", R, W);
        if (arg->port == -1)
            fprintf(stderr, "%s[ERROR]%s Miss port -p\n", R, W);
        return false;
    }
    if ((inet_pton(AF_INET, arg->machine, &(sa.sin_addr))) == 0) {
        fprintf(stderr, "%s[ERROR]%s Invalid machine\n", R, W);
        return false;
    }
    if (arg->port == 0) {
        fprintf(stderr, "%s[ERROR]%s Invalid port\n", R, W);
        return false;
    }
    return true;
}

bool parse_arg(arg_t *arg, int ac, char **av)
{
    int opt = 0;

    while ((opt = getopt(ac, av, "n:h:p:")) != -1) {
        switch (opt) {
        case 'n':
            arg->name = optarg;
            break;
        case 'p':
            arg->port = atoi(optarg);
            break;
        case 'h':
            arg->machine = optarg;
            break;
        default:
            print_usage();
            return false;
        }
    }
    return (verif_arg(arg));
}

bool get_arg(arg_t *arg, int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            print_usage();
            free(arg);
            exit(0);
        }
        free(arg);
        return false;
    }
    arg->port = -1;
    arg->name = NULL;
    arg->machine = "127.0.0.1";
    if (!parse_arg(arg, ac, av)) {
        free(arg);
        return false;
    }
    return true;
}

int main(int ac, char **av)
{
    arg_t *arg = malloc(sizeof(arg_t));
    bool ret = 0;

    if (!arg || !get_arg(arg, ac, av))
        return (ERROR_EXIT);
    signal(SIGINT, sig_handler);
    ret = init_client(arg);
    free(arg);
    if (!ret)
        return (ERROR_EXIT);
    return (EXIT_SUCCESS);
}
