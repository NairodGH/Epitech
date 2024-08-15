/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main gui
*/

#include "zappy_gui.h"

static void print_usage(void)
{
    fprintf(stderr, "%sUSAGE: ./zappy_gui -p port -n name -h machine\n\t"
        "port is the port number\n\t"
        "machine is the name of the machine; localhost by default\n%s", G, W);
}

bool verif_arg(arg_t *arg)
{
    struct sockaddr_in sa;

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

    while ((opt = getopt(ac, av, "h:p:")) != -1) {
        switch (opt) {
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
    if (ac <= 2) {
        if (ac != 1 && strcmp(av[1], "-help") == 0) {
            print_usage();
            free(arg);
            exit(0);
        }
        print_usage();
        free(arg);
        return false;
    }
    arg->port = -1;
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
    SetTraceLogLevel(LOG_NONE);
    InitWindow(1280, 720, "Zappy");
    SetTargetFPS(60);
    ret = init_client(arg);
    unload_textures(get_textures());
    unload_fonts(get_font());
    CloseWindow();
    free(arg);
    if (!ret)
        return (ERROR_EXIT);
    return (EXIT_SUCCESS);
}
