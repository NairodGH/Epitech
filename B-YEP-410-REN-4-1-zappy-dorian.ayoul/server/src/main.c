/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static void print_usage(void)
{
    printf("USAGE:\n");
    printf("./zappy_server -p port -x width -y height -n name1 name2 ... "
        "-c clientsNb -f freq\n");
    printf("\t-p\tport number\t\t\t(8080 by default)\n");
    printf("\t-x\tmap width\t\t\t(10 by default and 100 max)\n");
    printf("\t-y\ttmap height\t\t\t(10 by default and 100 max)\n");
    printf("\t-n\tname of the team\n");
    printf("\t-c\tnumber of client per team\t(1 by default)\n");
    printf("\t-f\tcycle frequency\t\t\t(100 by default)\n");
}

int main(int argc, char **argv)
{
    args_t *args = init_args();

    if (args == NULL)
        return ERROR_EXIT;
    if (parse_params(argc, argv, args) == ERROR ||
        verif_params(args) == ERROR) {
        print_usage();
        destroy_args(args);
        return ERROR_EXIT;
    }
    srand(time(NULL));
    if (server_start(args) == ERROR) {
        destroy_args(args);
        return ERROR_EXIT;
    }
    destroy_args(args);
    return SUCCESS;
}
