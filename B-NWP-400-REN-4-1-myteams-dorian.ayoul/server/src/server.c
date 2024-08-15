/*
** EPITECH PROJECT, 2022
** server.c
** File description:
** server
*/

#include "server.h"

bool *get_value(void)
{
    static bool value = false;

    return (&value);
}

int check_if_set(server_t *serv, lcli_t *list, int fd)
{
    int connfd = 0;
    struct sockaddr_in cliadd;
    socklen_t len = sizeof(cliadd);

    if (FD_ISSET(fd, &serv->readfds)) {
        if (get_client(list, fd) == NULL)
            connfd = accept(serv->socket->fd, (struct sockaddr *)&cliadd, &len);
        else
            connfd = fd;
        FD_SET(connfd, &serv->temp);
        FD_SET(connfd, &serv->writefds);
        serv->buffer = read_socket(connfd);
        if (serv->buffer == NULL)
            return 1;
        create_client(connfd, list);
        manage_client(connfd, list, serv->buffer, serv);
        free(serv->buffer);
    }
    return 0;
}

int loop_server_split(server_t *serv, lcli_t *list)
{
    for (int fd = 0; fd != FD_SETSIZE; ++fd)
        if (check_if_set(serv, list, fd) == 1)
            return 1;
    return 0;
}

void loop_server(server_t *serv, lcli_t *list)
{
    int sel = 0;

    while (1) {
        serv->readfds = serv->temp;
        sel = select_fds(&serv->readfds, &serv->writefds);
        if (sel == -1 || *(get_value()))
            break;
        if (loop_server_split(serv, list) == 1)
            return;
    }
}

void start_server(server_t *serv, lcli_t *list, clients_t *list_clients)
{
    FD_ZERO(&serv->readfds);
    FD_ZERO(&serv->writefds);
    FD_ZERO(&serv->fds);
    FD_ZERO(&serv->temp);
    FD_SET(serv->socket->fd, &serv->temp);
    loop_server(serv, list);
    save_data(list);
    end_server(serv, list);
    free(list_clients);
}
