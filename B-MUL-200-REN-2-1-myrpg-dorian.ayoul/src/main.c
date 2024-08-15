/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** main
*/

#include <rpg/rpg.h>
#include <rpg/args.h>
#include <file_utils.h>

int print_help(void)
{
    char *help = read_file("config/help.dat");

    if (help == NULL) {
        nfprintf(stdout, "Unable to retrieve help file.\n");
        return (84);
    }
    nprintf(help);
    return (0);
}

int main(int argc, char **argv, char **env)
{
    list_t *args = create_arg_list(argc, argv);

    if (args == NULL) {
        nfprintf(stdout, "Cannot malloc arg list.\n");
        return (84);
    }
    if (!has_display_env(env)) {
        nfprintf(stdout, "DISPLAY environment variable not found.\n");
        return (84);
    }
    if (!check_assets())
        return (84);
    if (has_arg(args, "h"))
        return (print_help());
    game_start(args);
    return 0;
}
