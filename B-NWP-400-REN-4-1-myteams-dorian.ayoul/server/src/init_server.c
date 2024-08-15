/*
** EPITECH PROJECT, 2022
** init_server.c
** File description:
** init_server
*/

#include "server.h"

int init_server_split(server_t *serv, clients_t *list_clients, lcli_t *list)
{
    serv->socket = create_socket();
    if (!serv->socket) {
        printf("Error malloc\n");
        clear_message(list->client->l_message);
        clear_client(list, serv);
        free(list_clients);
        printf("Error socket\n");
        exit(84);
    }
    serv->socket = init_socket(serv->socket, serv->port, MAX_CLIENT);
    if (serv->socket == NULL) {
        save_data(list);
        end_server(serv, list);
        free(list_clients);
        printf("Error socket\n");
        exit(84);
    }
    start_server(serv, list, list_clients);
    return 0;
}

int init_server(int port)
{
    server_t serv;
    clients_t *list_clients = init_client();
    lcli_t *list = create_list(list_clients);

    if (!list) {
        printf("Error malloc\n");
        exit(84);
    }
    if (count_nb_clients(list) >= MAX_CLIENT) {
        clear_message(list->client->l_message);
        clear_client(list, &serv);
        free(list_clients);
        printf("client max\n");
        return 0;
    }
    serv.port = port;
    init_server_split(&serv, list_clients, list);
    return 0;
}
