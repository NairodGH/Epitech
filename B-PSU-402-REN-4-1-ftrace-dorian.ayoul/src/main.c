/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** main
*/

#include "ftrace.h"

int main(int argc, char **argv)
{
    args_t args = {0};

    if (argc < 2) {
        fprintf(stderr, "Usage: ./ftrace <command>\n");
        return 84;
    }
    args.fileName = argv[1];
    if (argc > 2) {
        args.argv = (char **)(argv + sizeof(char *) * ARG_START);
    }
    return ftrace(&args);
}
