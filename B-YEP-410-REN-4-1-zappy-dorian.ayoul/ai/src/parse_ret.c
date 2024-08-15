/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

static const com_t com[] =
{
    {"Forward\n\0", &forward_movement},
    {"Right\n\0", &right_movement},
    {"Left\n\0", &left_movement},
    {"Look\n\0", &look_around},
    {"Inventory\n\0", &inventory},
    {"Broadcast\n\0", &broadcast},
    {"Connect_nbr\n\0", &connect_nbr},
    {"Fork\n\0", &fork_player},
    {"Eject\n\0", &eject_player},
    {"Take\0", &take_object},
    {"Set\0", &set_object},
    {"Incantation\n\0", &incantation},
    {NULL, NULL}
};

static bool get_number_client(client_t *client, char *str)
{
    if (atoi(str) < 1 && !client->client_connected) {
        fprintf(stderr, "%s[ERROR]%s too many clients in this team\n", R, W);
        return false;
    }
    if (atoi(str) >= 1 && !client->client_connected) {
        client->client_connected = true;
        client->unused_slot = atoi(str);
    }
    if (client->size_map.x != -1) {
        client->init = false;
        if (!basic_command(client))
            return false;
    }
    return true;
}

static bool init_header(client_t *client, char *str)
{
    char *team_new_line = NULL;

    client->init = true;
    if (strcmp(str, "WELCOME") == 0) {
        if (!(team_new_line = add_newline(client->player->team_name)))
            return false;
        if (!send_message(NULL, client->command, client->socket, team_new_line))
            return false;
        free(team_new_line);
        return true;
    }
    for (; str[0] == ' '; (char *)((size_t)(str++)));
    if (!(strchr(str, ' ')))
        return get_number_client(client, str);
    else
        get_size_map(client, str);
    return true;
}

static char *get_arg(char *command, char *str)
{
    char *arg = NULL;
    size_t i = 0;
    size_t len = 0;
    size_t n = 0;

    for (i = 0; command[i] != '\0' && command[i] != ' '; i++);
    if (command[i] == '\0')
        return NULL;
    command[i] = '\0';
    if (strcmp(str, "ko") == 0)
        return strdup(str);
    i++;
    n = i;
    for (; command[i] != '\0'; i++, len++);
    arg = malloc(sizeof(char) * (len + 1));
    for (i = n, len = 0; command[i] != '\0'; i++, len++)
        arg[len] = command[i];
    arg[len] = '\0';
    return arg;
}

bool split_parse_ret(client_t *client, char *str, char *command)
{
    if (strlen(str) >= 18 && strncmp(str, "Elevation underway", 18) == 0) {
        incantation(client, str);
        free(command);
        return false;
    }
    if (strlen(str) >= 14 && strncmp(str, "Current level:", 14) == 0) {
        incantation(client, str);
        free(command);
        return false;
    }
    if (client->player->incantation
        && (strlen(str) >= 9 && strncmp(command, "Inventory", 9) != 0)) {
        free(command);
        return false;
    }
    return true;
}

bool parse_return(client_t *client, char *str)
{
    char *command = NULL;
    char *arg = NULL;

    if (strcmp(str, "WELCOME") == 0 || client->init)
        return (init_header(client, str));
    if (strlen(str) > 8 && strncmp(str, "message ", 8) == 0)
        return (message_broadcast(client, str));
    if (!(command = list_pop_head(client->pending_commands))
        || !split_parse_ret(client, str, command))
        return true;
    arg = get_arg(command, str);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, command) == 0) {
            com[i].func_ptr(client, ((arg) ? arg : str));
            break;
        }
    }
    free(command);
    free(arg);
    return true;
}
