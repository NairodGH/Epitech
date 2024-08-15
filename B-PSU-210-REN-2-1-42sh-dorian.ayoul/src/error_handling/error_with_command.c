/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "42sh.h"

void error_command(char *command_name, char *error_type)
{
    dprintf(STDERR_FILENO, "%s: %s.\n", command_name, error_type);
}
