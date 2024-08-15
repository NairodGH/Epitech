/*
** EPITECH PROJECT, 2022
** ftp.c
** File description:
** ftp
*/

#include "ftp.h"

bool new_client(int fd, client_t **clients, char *home)
{
    socket_t s_in = {0};
    socklen_t size = sizeof(s_in);
    size_t nb = 0;

    for (; clients[nb]; nb++);
    if (nb == FD_SETSIZE)
        return 0;
    clients[nb] = malloc(sizeof(client_t));
    CHECK(clients[nb]->fd = accept(fd, (struct sockaddr *)&s_in, &size), 0);
    clients[nb]->cwd = malloc(sizeof(char) * BUFSIZ);
    memset(clients[nb]->cwd, 0, BUFSIZ);
    strcpy(clients[nb]->cwd, home);
    clients[nb]->input = malloc(sizeof(char) * BUFSIZ);
    memset(clients[nb]->input, 0, BUFSIZ);
    memset(clients[nb]->connected, 0, 2);
    return dprintf(clients[nb]->fd, "220 Service ready for new user.\r\n");
}

int get_command(client_t *client, char *home)
{
    char *token;

    if (strlen(client->input) == 1) return -1;
    if (!(token = strtok(client->input, " \r"))) return dprintf(client->fd,
        ERROR500);
    if (!strcmp(token, "USER")) return user(client, strtok(NULL, " "));
    if (!strcmp(token, "PASS")) return pass(client, strtok(NULL, " "));
    if (!strcmp(token, "CWD")) return cwd(client, strtok(NULL, " "));
    if (!strcmp(token, "CDUP")) return cdup(client, home);
    if (!strcmp(token, "QUIT")) return quit(client);
    if (!strcmp(token, "DELE")) return dele(client, strtok(NULL, " "));
    if (!strcmp(token, "PWD")) return pwd(client);
    if (!strcmp(token, "PASV")) return pasv(client);
    if (!strcmp(token, "PORT")) return port(client, strtok(NULL, " "));
    if (!strcmp(token, "HELP")) return help(client, strtok(NULL, " "));
    if (!strcmp(token, "NOOP")) return noop(client);
    if (!strcmp(token, "RETR")) return retr(client, strtok(NULL, " "));
    if (!strcmp(token, "STOR")) return stor(client, strtok(NULL, " "));
    if (!strcmp(token, "LIST")) return list(client, strtok(NULL, " "));
    return dprintf(client->fd, ERROR500);
}

int handle_clients(int fd, client_t **clients, fd_set set, char *home)
{
    if (!FD_ISSET(fd, &set))
        return 0;
    for (size_t i = 0; clients[i]; i++) {
        if (clients[i]->fd == fd) {
            CHECK(read(clients[i]->fd, clients[i]->input, BUFSIZ), -1);
            clients[i]->input[strlen(clients[i]->input) - 1] = '\0';
            get_command(clients[i], home);
            memset(clients[i]->input, 0, BUFSIZ);
        }
    }
}

int server(int fd, char *home)
{
    client_t **clients;

    clients = malloc(sizeof(client_t *) * FD_SETSIZE);
    memset(clients, 0, sizeof(client_t *) * FD_SETSIZE);
    for (fd_set set;;) {
        FD_ZERO(&set);
        FD_SET(fd, &set);
        for (size_t i = 0; clients[i]; i++)
            FD_SET(clients[i]->fd, &set);
        if (select(FD_SETSIZE, &set, NULL, NULL, NULL) <= 0)
            return 84;
        if (FD_ISSET(fd, &set) && !new_client(fd, clients, home))
            return 84;
        for (size_t i = 0; i < FD_SETSIZE; i++)
            CHECK(handle_clients(i, clients, set, home), 84);
    }
    return 0;
}

int main(int ac, char **av)
{
    int fd;
    socket_t s_in = {0};

    if (ac != 3 || !strcmp(av[1], "") || !strcmp(av[2], "") || chdir(av[2]) < 0)
        return 84;
    for (size_t i = 0; av[1][i] != '\0'; i++)
        if (!('0' <= av[1][i] && av[1][i] <= '9'))
            return 84;
    CHECK(fd = socket(AF_INET, SOCK_STREAM, 0), 84);
    CHECK(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)), 84);
    s_in.sin_family = AF_INET;
    s_in.sin_port = htons((unsigned short)strtoul(av[1], NULL, 10));
    s_in.sin_addr.s_addr = INADDR_ANY;
    CHECK(bind(fd, (struct sockaddr *)&s_in, sizeof(s_in)), 84);
    CHECK(listen(fd, SOMAXCONN), 84);
    return server(fd, av[2]);
}