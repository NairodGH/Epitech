/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client gui
*/

#include "zappy_gui.h"

static const com_t com[] =
{
    {"bct\0", &bct},
    {"mct\0", &mct},
    {"msz\0", &msz},
    {"ppo\0", &ppo},
    {"plv\0", &plv},
    {"pin\0", &pin},
    {"pdi\0", &pdi},
    {"pnw\0", &pnw},
    {"tna\0", &tna},
    {"sgt\0", &sgt},
    {"pic\0", &pic},
    {"pie\0", &pie},
    {NULL, NULL}
};

static bool init_header(client_t *client)
{
    char *uuid_new_line = malloc(sizeof(char) * (UUID_STR_LEN + 10));

    if (!uuid_new_line)
        return false;
    strcpy(uuid_new_line, client->uuid);
    strcat(uuid_new_line, "\n");
    strcat(uuid_new_line, "msz\n");
    strcat(uuid_new_line, "sgt\n");
    if (!send_message(NULL,
        client->command, client->socket, uuid_new_line))
        return false;
    free(uuid_new_line);
    return true;
}

static char *get_command_arg(char *str)
{
    char *arg = NULL;
    size_t i = 0;
    size_t n = 0;
    size_t j = 0;

    for (; str[i] == ' '; i++);
    for (; str[i] != '\0' && str[i] != ' '; i++);
    if (str[i] == '\0')
        return NULL;
    for (n = i; str[n] != '\0'; n++);
    arg = malloc(sizeof(char) * (n + 1));
    if (!arg) {
        fprintf(stderr, "%s[ERROR]%s can't malloc\n", R, W);
        return NULL;
    }
    for (; str[i] == ' '; i++);
    for (n = i; str[n] != '\0'; n++, j++)
        arg[j] = str[n];
    arg[j] = '\0';
    return arg;
}

static char *get_command_name(char *str)
{
    char *command_name = NULL;
    size_t i = 0;
    size_t n = 0;

    for (; str[i] != '\0' && str[i] != ' '; i++);
    command_name = malloc(sizeof(char) * (i + 1));
    if (!command_name) {
        fprintf(stderr, "%s[ERROR]%s can't malloc\n", R, W);
        return NULL;
    }
    for (n = 0; str[n] != '\0' && str[n] != ' '; n++)
        command_name[n] = str[n];
    command_name[n] = '\0';
    return command_name;
}

bool parse_return(client_t *client, char *str)
{
    char *command_name = NULL;
    char *arg = NULL;

    if (strcmp(str, "WELCOME") == 0)
        return (init_header(client));
    if (!(command_name = get_command_name(str)))
        return false;
    arg = (strcmp(command_name, "suc") == 0 || strcmp(command_name, "sbp") == 0)
        ? strdup(str) : get_command_arg(str);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strncmp(com[i].cmd, command_name, strlen(com[i].cmd)) == 0) {
            com[i].func_ptr(client, arg);
            break;
        }
    }
    free(command_name);
    free(arg);
    return true;
}
