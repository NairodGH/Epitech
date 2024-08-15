/*
** EPITECH PROJECT, 2022
** ftp.h
** File description:
** ftp
*/

#pragma once

#include <arpa/inet.h>
#include <dirent.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct sockaddr_in socket_t;

typedef struct client_s {
    char *cwd;
    char *input;
    bool connected[2];
    int fd;
} client_t;

#define CHECK(func, ret) if ((func) == -1) return ret
#define ERROR500 "500 Syntax error, command unrecognized.\r\n"

int user(client_t *client, char *name);
int pass(client_t *client, char *name);
int cwd(client_t *client, char *path);
int cdup(client_t *client, char *home);
int quit(client_t *client);
int dele(client_t *client, char *path);
int pwd(client_t *client);
int pasv(client_t *client);
int port(client_t *client, char *host_port);
int help(client_t *client, char *string);
int noop(client_t *client);
int retr(client_t *client, char *path);
int stor(client_t *client, char *path);
int list(client_t *client, char *path);
