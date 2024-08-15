/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client ai
*/

#include "zappy_ai.h"

static bool split_client_push_exec(client_t *client, char *comm)
{
    if (client->received_commands->lenght >= 10) {
        fprintf(stderr, "[ERROR] Command list is full\n");
        return true;
    }
    if (list_push_data(client->received_commands,
        (void *)strdup(comm)) == LIST_FAILURE) {
        fprintf(stderr, "[ERROR] Insertion of command failed\n");
        return true;
    }
    return false;
}

bool client_push_exec_command(client_t *client, char *buffer)
{
    char *com = strtok(buffer, "\n");

    if (com == NULL) {
        fprintf(stderr, "[ERROR] Command is not valid\n");
        return true;
    }
    for (; com != NULL; com = strtok(NULL, "\n")) {
        if (strcmp(com, "dead\n") == 0 || strcmp(com, "dead") == 0) {
            printf("%s[INFO]%s Player dead\n", G, W);
            return false;
        }
        if (strlen(com) >= 14 && strncmp(com, "Current level:", 14) == 0) {
            incantation(client, com);
            continue;
        }
        if (split_client_push_exec(client, com))
            return true;
    }
    return true;
}

bool loop_parse_return(client_t *client, char *temp)
{
    node_t *node = NULL;
    node_t *node_save = NULL;

    if (!client_push_exec_command(client, temp)) {
        free(temp);
        return false;
    }
    free(temp);
    foreach_safe (client->received_commands->head, node, node_save) {
        if (!parse_return(client, (char *)node->data))
            return false;
        list_destroy_data_node(client->received_commands, node->data, free);
    }
    return true;
}
