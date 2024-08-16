#include "general.h"

static void reset_fd_clients(server_tcp_t *server)
{
    client_t *tmp = server->clients;

    for (; tmp != NULL; tmp = tmp->next) {
        FD_SET(tmp->sock, &server->read_fd);
        FD_SET(tmp->sock, &server->write_fd);
    }
}

static void reset_fd(homuresu_t *gn)
{
    FD_ZERO(&gn->srv_tcp->read_fd);
    FD_ZERO(&gn->srv_tcp->write_fd);
    FD_ZERO(&gn->srv_udp->read_fd);
    FD_ZERO(&gn->srv_udp->write_fd);
    FD_SET(gn->srv_tcp->sock, &gn->srv_tcp->read_fd);
    FD_SET(gn->srv_tcp->sock, &gn->srv_tcp->write_fd);
    FD_SET(gn->srv_udp->sock, &gn->srv_udp->read_fd);
    FD_SET(gn->srv_udp->sock, &gn->srv_udp->write_fd);
    reset_fd_clients(gn->srv_tcp);
}

static int loop_send_srv_tcp(homuresu_t *gn)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(gn->srv_tcp->sock + 1, NULL,
        &gn->srv_tcp->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(gn->srv_tcp->sock, &gn->srv_tcp->read_fd)) {
            // if ((check = manage_tcp_send_actions()) != 0)
            //     return check;
        }
    }
    return check;
}

static int loop_send_srv_udp(homuresu_t *gn)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(gn->srv_udp->sock + 1, NULL,
        &gn->srv_udp->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(gn->srv_udp->sock, &gn->srv_udp->read_fd)) {
            // if ((check = manage_udp_send_actions()) != 0)
            //     return check;
        }
    }
    return check;
}

static int loop_recv_srv_tcp(homuresu_t *gn)
{
    int check = 0;
    int con_fd = 0;
    struct sockaddr_in con_addr;
    socklen_t addrlen = sizeof(con_addr);
    struct timeval timeout = {0, 100};

    if (select(FD_SETSIZE, &gn->srv_tcp->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(gn->srv_tcp->sock, &gn->srv_tcp->read_fd)) {
            con_fd = accept(gn->srv_tcp->sock, (struct sockaddr *)&con_addr,
                &addrlen);
            if (con_fd == -1) {
                printf("Error : Fail to accept TCP connection\n");
                return 0;
            }
            if (assign_fd_connection(gn->srv_tcp, con_fd) != 0)
                return 84;
        }
        if (client_action_manage(gn->srv_tcp) != 0)
            return 84;
    }
    return check;
}

static int loop_recv_srv_udp(homuresu_t *gn)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(gn->srv_udp->sock + 1, &gn->srv_udp->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(gn->srv_udp->sock, &gn->srv_udp->read_fd)) {
            if (check_client_connected(gn) != 0)
                return 84;
        }
    }
    return check;
}

int loop_server(homuresu_t *gn)
{
    gn->srv_tcp->clients = init_clients(gn->srv_tcp->sock);
    if (gn->srv_tcp->clients == NULL)
        return 84;
    while (true) {
        reset_fd(gn);
        if (loop_recv_srv_tcp(gn) != 0)
            return 84;
    }
    return 0;
}