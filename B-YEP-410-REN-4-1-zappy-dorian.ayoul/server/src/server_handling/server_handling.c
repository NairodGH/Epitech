/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static client_t *setup_new_client(server_t *serv, int fd)
{
    client_t *client = NULL;

    if (fd < 0) {
        fprintf(stderr, "[ERROR] Creation of new connection failed\n");
        return NULL;
    }
    client = client_create(fd);
    if (client == NULL) {
        fprintf(stderr, "[ERROR] Creation of new client failed\n");
        close(fd);
        return NULL;
    }
    if (list_push_data(serv->clients, (void *)client) == LIST_FAILURE) {
        fprintf(stderr, "[ERROR] Insertion of new client failed\n");
        close(fd);
        client_destroy(client);
        return NULL;
    }
    return client;
}

static void server_accept_connection(server_t *serv)
{
    socklen_t socket_size = sizeof(sockaddr_in_t);
    int fd_temp = accept(serv->socket->fd,
        (struct sockaddr *)serv->socket->addr, &socket_size);
    client_t *client = setup_new_client(serv, fd_temp);

    if (client != NULL) {
        printf("[INFO] New client connected.\n");
        client_push_command(serv, client, strdup("WELCOME\n"));
    }
}

static void server_catch_sigpipe(void)
{
    struct sigaction new_actn = {0};
    struct sigaction old_actn = {0};

    new_actn.sa_handler = SIG_IGN;
    sigemptyset(&new_actn.sa_mask);
    sigaction(SIGPIPE, &new_actn, &old_actn);
}

int server_loop(core_t *core)
{
    fd_set readfds = {0};
    fd_set writefds = {0};

    server_catch_sigpipe();
    while (1) {
        game_update(core);
        set_read_fds(core->server, &readfds);
        set_write_fds(core->server, &writefds);
        nlib_select_fds(&readfds, &writefds);
        nlib_commands_update(core->server->commands_to_send, &writefds);
        clients_update_delete(core);
        clients_update(core, &readfds);
        if (FD_ISSET(core->server->socket->fd, &readfds))
            server_accept_connection(core->server);
    }
    return SUCCESS;
}
