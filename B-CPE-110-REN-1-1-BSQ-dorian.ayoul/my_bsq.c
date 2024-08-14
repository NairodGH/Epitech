/*
** EPITECH PROJECT, 2020
** my_bsq.c
** File description:
** Finds the biggest square on a map and displays its position
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_bsq(char *buffer, int **map, int rows, int cols)
{
    int bsq = 0;
    int bsq_i = 0;
    int bsq_j = 0;
    int k = map[0][0];

    for (int i = 1; i != rows; i++) {
        for (int j = 1; j != cols; j++)
            (bsq < map[i][j]) && (bsq = map[i][j], bsq_i = i, bsq_j = j);
    }
    for (int i = 1; i != rows; i++) {
        for (int j = 1; j != cols; j++, k++) {
            if (buffer[k] == '\n') k++;
            (map[i][j] == 0) ? write(1, "o", 1) :
            ((bsq_i - bsq < i && i <= bsq_i) && (bsq_j - bsq < j && j <= bsq_j))
            ? write(1, "x", 1) : write(1, &buffer[k], 1);
        }
        write(1, "\n", 1);
    }
}

int create_map(char *buffer, int rows, int cols, int k)
{
    int **map = malloc(++rows * sizeof(int *));

    cols++;
    for (int i = 0; i != rows; i++) map[i] = malloc(cols * sizeof(int));
    for (int i = 0; i != rows; i++) for (int j = 0; j != cols;) map[i][j++] = 0;
    map[0][0] = k;
    for (int i = 1; i != rows; i++) {
        for (int j = 1; j != cols; k++) {
            if ((buffer[k + 1] == '\n' && j + 1 != cols) || (j + 1 == cols &&
                buffer[k] != '\n' && buffer[k + 1] != '\n')) return (84);
            buffer[k] == 'o' ? map[i][j++] = 0 : (buffer[k] != '\n') &&
            (map[i][j++] = 1 + ((map[i - 1][j] <= map[i][j - 1] &&
            map[i - 1][j] <= map[i - 1][j - 1]) ? map[i - 1][j] :
            (map[i][j - 1] <= map[i - 1][j] && map[i][j - 1] <=
            map[i - 1][j - 1]) ? map[i][j - 1] : map[i - 1][j - 1]));
        }
    }
    my_bsq(buffer, map, rows, cols);
    for (int i = 0; i != rows; i++) free(map[i]);
    free(map);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat sb;
    stat(argv[1], &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);
    int i = 0;
    int k = 0;
    int rows = 0;
    int cols = 0;

    if (fd == -1 || read(fd, buffer, sb.st_size) == -1) return (84);
    for (; buffer[i] != '\n'; i++) {
        if (!('0' <= buffer[i] && buffer[i] <= '9')) return (84);
        rows *= 10, rows += buffer[i] - 48;
    }
    for (k = ++i; buffer[i] != '\n'; i++) cols++;
    if (create_map(buffer, rows, cols, k) == 84) return (84);
    free(buffer), close(fd);
    return (0);
}