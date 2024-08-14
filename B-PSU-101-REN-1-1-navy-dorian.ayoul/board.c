/*
** EPITECH PROJECT, 2020
** board1.c
** File description:
** navy board1-related functions
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

int pos_file_error(char b[32])
{
    for (int k = 0; k != 32; k += 8) {
        if (my_strlen(b) != 32 || b[k] < 50 || b[k] > 53 || b[k + 1] != ':' ||
            b[k + 2] < 65 || b[k + 2] > 72 || b[k + 3] < 49 || b[k + 3] > 56 ||
            b[k + 4] != ':' || b[k + 5] < 65 || b[k + 5] > 72 || b[k + 6] < 49
            || b[k + 6] > 56 || b[k + 7] != '\n' && b[k + 7] != '\0')
            return (84);
        if (k != 0 && b[k - 8] > b[k]) return (84);
        if (b[k + 2] == b[k + 5] && b[k + 3] > b[k + 6]) return (84);
        if (b[k + 3] == b[k + 6] && b[k + 2] > b[k + 5]) return (84);
        if (b[k + 2] != b[k + 5] && b[k + 3] != b[k + 6]) return (84);
        if (b[k + 2] == b[k + 5] && b[k + 6] - b[k + 3] != b[k] - 49)
            return (84);
        if (b[k + 3] == b[k + 6] && b[k + 5] - b[k + 2] != b[k] - 49)
            return (84);
    }
    return (0);
}

int get_boats_pos(char board1[10][18], int ac, char **av)
{
    int fd = open(ac == 2 ? av[1] : av[2], S_IRUSR);
    char b[32];

    if (fd == -1) return (84);
    read(fd, b, 32), close(fd);
    if (pos_file_error(b) == 84) return (84);
    for (int i = 0, j = 0, k = 0, v = 0; k != 32; k += 8, v = 0) {
        if (b[k + 2] == b[k + 5]) v = 1, j = 2 + (b[k + 2] - 65) * 2;
        for (i = b[k + 3] - 47; i <= b[k + 6] - 47 && v == 1; i++)
            board1[i][j] = b[k];
        if (v == 1) continue;
        i = b[k + 3] - 47;
        for (j = 2 + (b[k + 2] - 65) * 2; j <= 2 + (b[k + 5] - 65) * 2; j++)
            (board1[i][j] == ' ') && (j++), board1[i][j] = b[k];
    }
    for (int i = 2, j = 2, k = 0; i != 10; i++) {
        for (j = 2; j != 18; j++) (board1[i][j] > 49) && (k++);
        if (i == 9 && j == 18 && k != 14) return (84);
    }
    return (0);
}

int load_boards(char board1[10][18], char board2[10][18], int ac, char **av)
{
    for (int i = 2; i != 10; i++) board1[i][0] = i + 47, board1[0][0] = ' ';
    for (int i = 2; i != 10; i++) board2[i][0] = i + 47, board2[0][0] = ' ';
    for (int i = 0; i != 10; i++) board1[i][1] = '|', board1[i][17] = '\n';
    for (int i = 0; i != 10; i++) board2[i][1] = '|', board2[i][17] = '\n';
    for (int j = 2; j != 17; j++) board1[0][j] = j % 2 == 0 ? j / 2 + 64 : ' ';
    for (int j = 2; j != 17; j++) board2[0][j] = j % 2 == 0 ? j / 2 + 64 : ' ';
    for (int j = 0; j != 17; j++) board1[1][j] = '-', board1[1][1] = '+';
    for (int j = 0; j != 17; j++) board2[1][j] = '-', board2[1][1] = '+';
    for (int i = 2; i != 10; i++)
        for (int j = 2; j != 17; j++)
            j % 2 == 0 ? board1[i][j] = '.' : (board1[i][j] = ' ');
    for (int i = 2; i != 10; i++)
        for (int j = 2; j != 17; j++)
            j % 2 == 0 ? board2[i][j] = '.' : (board2[i][j] = ' ');
    if (get_boats_pos(board1, ac, av) == 84) return (84);
    return (0);
}

int defend(char board1[10][18])
{
    int fd = open("bonus/test", O_RDWR);
    char b[2];

    write(1, "\nwaiting for enemy's attack...", 30), pause(), read(fd, b, 2);
    if (board1[b[1] - 47][2 + (b[0] - 65) * 2] != '.') {
        board1[b[1] - 47][2 + (b[0] - 65) * 2] = 'x';
        lseek(fd, 2, SEEK_SET), write(fd, "h", 1), kill(enemy_pid, 10);
        write(1, "\n", 1), write(1, b, 2), write(1, ": hit\n", 6);
    }
    if (board1[b[1] - 47][2 + (b[0] - 65) * 2] == '.') {
        board1[b[1] - 47][2 + (b[0] - 65) * 2] = 'o';
        lseek(fd, 2, SEEK_SET), write(fd, "m", 1), kill(enemy_pid, 10);
        write(1, "\n", 1), write(1, b, 2), write(1, ": missed\n", 9);
    }
    for (int i = 2, j = 2, k = 0; i != 10; i++)
        for (j = 2; j != 18; j++)
            (board1[i][j] == 'x') && (k++), (k == 14) && (enemy_pid = 1);
    close(fd);
}

int display(char board1[10][18], char board2[10][18])
{
    write(1, "\nmy positions:\n", 15), write(1, board1, 180);
    write(1, "\nenemy's positions:\n", 20), write(1, board2, 180);
}