/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void client_exec_command(core_t *core, client_t *client)
{
    char *command = list_pop_head(client->command_list);

    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot get command\n");
        return;
    }
    if (client->type == CLI_DEFAULT) {
        client_def_search_command(core, client, command);
    } else if (client->type == CLI_GUI) {
        client_gui_search_command(core, client, command);
    } else {
        client_define_type(core, client, command);
    }
    free(command);
}

void client_push_exec_command(client_t *client, char *buffer)
{
    char *command = strtok(buffer, "\n");

    if (command == NULL) {
        fprintf(stderr, "[ERROR] Command is not valid\n");
        return;
    }
    for (; command != NULL; command = strtok(NULL, "\n")) {
        if (client->command_list->lenght >= 10) {
            fprintf(stderr, "[ERROR] Command list is full\n");
            return;
        }
        if (list_push_data(client->command_list, (void *)strdup(command)) ==
            LIST_FAILURE) {
            fprintf(stderr, "[ERROR] Insertion of command failed\n");
            return;
        }
        printf("[INFO] Command \"%s\" pushed in command list\n", command);
    }
}

int client_get_command(client_t *client)
{
    char *buffer = NULL;

    buffer = nlib_read_socket(client->sock);
    if (buffer == NULL)
        return EXIT;
    client_push_exec_command(client, buffer);
    free(buffer);
    return SUCCESS;
}

void client_disconnect(core_t *core, client_t *client, node_t *node)
{
    if (client->trantorian)
        command_pdi(core, client->trantorian);
    if (client->trantorian && client->trantorian->team) {
        client->trantorian->team->cli_sub--;
        trantorian_replace(core, client->trantorian->team, client->trantorian);
    }
    nlib_remove_socket_command_list(core->server->commands_to_send,
        client->sock);
    if (node != NULL) {
        list_remove_node(core->server->clients, node);
        list_destroy_node(node, (void (*)(void *))client_destroy);
    } else {
        list_destroy_data_node(core->server->clients, client,
            (void (*)(void *))client_destroy);
    }
    printf("[INFO] Client disconnected\n");
}

void clients_update(core_t *core, fd_set *readfds)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    client_t *client = NULL;

    foreach_safe(core->server->clients->head, node, safe) {
        client = (client_t *)node->data;
        if (FD_ISSET(client->sock->fd, readfds) &&
                client_get_command(client) == EXIT) {
            client_disconnect(core, client, node);
        } else if ((client->handler->command == NULL &&
                client->handler->command_it == 0) &&
                client->command_list->lenght > 0) {
            client_exec_command(core, client);
        }
    }
}
