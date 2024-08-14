/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** pew pew
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

int enemy_pid = 0;

void continue_game(int sig)
{
}

int attack(char board2[10][18])
{
    char *move = NULL;
    int fd = open("bonus/test", O_RDWR);
    char b[3];

    write(1, "\nattack: \n", 10), usleep(10000);
    for (size_t size; getline(&move, &size, stdin) != 3
    || move[0] < 65 || move[0] > 72 || move[1] < 49 || move[1] > 56;) {
        if (move[0] == '\0') return (2);
        write(1, "wrong position", 14), free(move), close(fd);
        return (attack(board2));
    } lseek(fd, 0, SEEK_SET), write(fd, move, 2), kill(enemy_pid, 10), pause(),
    lseek(fd, 0, SEEK_SET), read(fd, b, 3);
    if (b[2] == 'h') {board2[b[1] - 47][2 + (b[0] - 65) * 2] = 'x';
        write(1, &b[0], 1), write(1, &b[1], 1), write(1, ": hit\n", 6);
    } if (b[2] == 'm') board2[b[1] - 47][2 + (b[0] - 65) * 2] = 'o',
        write(1, &b[0], 1), write(1, &b[1], 1), write(1, ": missed\n", 9);
    for (int i = 2, j = 2, k = 0; i != 10; i++)
        for (j = 2; j != 18; j++) (board2[i][j] == 'x') && (k++),
            (k == 14) && (enemy_pid = 0);
    free(move), close(fd);
}

int game_loop(int ac, char **av)
{
    char board1[10][18];
    char board2[10][18];

    signal(10, continue_game);
    if (load_boards(board1, board2, ac, av) == 84) return (84);
    display(board1, board2);
    for (int player = 1; 1; (player == 1) && (display(board1, board2))) {
        if (ac - 1 == player)
            (attack(board2) == 2) && (enemy_pid = 2);
        else
            defend(board1);
        if (enemy_pid == 0 || enemy_pid == 1 || enemy_pid == 2) {
            (enemy_pid != 2) && (display(board1, board2));
            return (0);
        }
        player == 1 ? player++ : player--;
    }
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3) return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "USAGE\n     ./navy [first_player_pid] navy_positions\n", 52),
        write(1, "DESCRIPTION\n     first_player_pid: ", 35),
        write(1, "only for the 2nd player. pid of the first player.\n", 50),
        write(1, "     navy_positions: ", 21),
        write(1, "file representing the positions of the ships.\n", 46);
        return (0);
    }
    for (int i = 0; ac == 3 && av[1][i] != '\0'; i++)
        if (57 < av[1][i] || av[1][i] < 48) return (84);
    if (connection(ac, av) == 84) return (84);
    if (game_loop(ac, av) == 84) return (84);
    if (enemy_pid == 0) write(1, "\nI won\n", 7);
    if (enemy_pid == 1) write(1, "\nEnemy won\n", 12);
    return (0);
}