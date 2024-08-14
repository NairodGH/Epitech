/*
** EPITECH PROJECT, 2020
** connection.c
** File description:
** navy connection-related functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "include/my.h"

extern int enemy_pid;

void p1connect(int sig, siginfo_t *info, void *context)
{
    write(1, "\nenemy connected\n", 17);
    enemy_pid = info->si_pid;
    kill(enemy_pid, 10);
}

void p2connect(int sig)
{
    write(1, "\nsuccessfully connected\n", 24);
}

int connection(int ac, char **av)
{
    struct sigaction act;
    int i = 1;

    write(1, "my_pid: ", 8);
    while (getpid() / i >= 10) i *= 10;
    for (int j = 0; i > 0; j++) my_putchar(getpid() / i % 10 + 48), i /= 10;
    if (ac == 2) {
        write(1, "\nwaiting for enemy connection...\n", 33);
        act.sa_flags = SA_SIGINFO | SA_RESETHAND, act.sa_sigaction = p1connect;
        sigaction(10, &act, NULL);
    }
    if (ac == 3) {
        enemy_pid = my_atoi(av[1]);
        kill(enemy_pid, 10);
        act.sa_flags = SA_RESETHAND, act.sa_handler = p2connect;
        sigaction(10, &act, NULL);
    }
    pause();
}