/*
** EPITECH PROJECT, 2022
** commands2.c
** File description:
** commands2
*/

#include "ftp.h"

static const char *cmds[14][2] =
{
    {"USER", "<SP> <username> <CRLF> : Specify user for authentication"},
    {"PASS", "<SP> <password> <CRLF> : Specify password for authentication"},
    {"CWD", "<SP> <path> <CRLF> : Change working directory"},
    {"CDUP", "<CRLF> : Change working directory to parent directory"},
    {"QUIT", "<CRLF> : Disconnection"},
    {"DELE", "<SP> <path> <CRLF> : Delete file on the server"},
    {"PWD", "<CRLF> : Print working directory"},
    {"PASV", "<CRLF> : Enable \"passive\" mode for data transfer"},
    {"PORT", "<SP> <host-port> <CRLF> : Enable \"active\" mode for data \
        transfer"},
    {"HELP", "[<SP> <string>] <CRLF> : List available cmds"},
    {"NOOP", "<CRLF> : Do nothing"},
    {"RETR", "<SP> <path> <CRLF> : Download file from server to client"},
    {"STOR", "<SP> <path> <CRLF> : Upload file from client to server"},
    {"LIST", "[<SP> <path>] <CRLF> : List files in the current working \
        directory"}
};

int help(client_t *client, char *string)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    if (!string)
        return dprintf(client->fd, "214 HELP %s\r\n", cmds[9][1]);
    string[strlen(string) - 1] = '\0';
    for (size_t i = 0; i < 14; i++)
        if (!strcmp(cmds[i][0], string))
            return dprintf(client->fd, "214 %s %s\r\n", string, cmds[i][1]);
    return dprintf(client->fd, "550 Requested action not taken.\r\n");
}

int port(client_t *client, char *host_port)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (!host_port || strtok(NULL, " "))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    return dprintf(client->fd, "220 Service ready for new user.\r\n");
}

int pasv(client_t *client)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    return dprintf(client->fd,
        "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n", 0, 0, 0, 0, 0, 0);
}

int pwd(client_t *client)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    return dprintf(client->fd, "257 \"%s\" created.\r\n", client->cwd);
}

int dele(client_t *client, char *path)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (!path || strtok(NULL, " ") ||
        !(path[strlen(path) - 1] = '\0') && remove(path) < 0)
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    return dprintf(client->fd,
        "250 Requested file action okay, completed.\r\n");
}