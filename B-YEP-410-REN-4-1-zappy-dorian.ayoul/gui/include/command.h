/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef COMMAND_H
    #define COMMAND_H

    #include <stdlib.h>

typedef struct client_s client_t;

int bct(client_t *client, char *str);
int mct(client_t *client, char *str);
int msz(client_t *client, char *str);
int ppo(client_t *client, char *str);
int pdi(client_t *client, char *str);
int pin(client_t *client, char *str);
int pnw(client_t *client, char *str);
int plv(client_t *client, char *str);
int tna(client_t *client, char *str);
int sgt(client_t *client, char *str);
int pic(client_t *client, char *str);
int pie(client_t *client, char *str);
int seg(client_t *client, char *str);

typedef struct com_s {
    const char *cmd;
    int (*func_ptr)(client_t *client, char *str);
} com_t;

#endif
