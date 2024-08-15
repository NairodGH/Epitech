/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function file for CPE Dante's star project
*/

#include "../lib/my/lib.h"

static bool solve(char *maze, size_t height, size_t width, size_t pos)
{
    if (pos == height * width - 2) {
        maze[pos] = 'o';
        return true;
    }
    if (maze[pos] == '*') {
        maze[pos] = 'o';
        if (solve(maze, height, width, pos + 1) == true)
            return true;
        if (solve(maze, height, width, pos + width) == true)
            return true;
        maze[pos] = '*';
        return false;
    }
    return false;
}

int main(int ac, char **av)
{
    int fd;
    struct stat st;
    char *maze;
    size_t height = 1;
    size_t width = 1;

    if (ac != 2 || stat(av[1], &st) == -1 || (fd = open(av[1], O_RDONLY)) == -1
    || (!(maze = malloc(st.st_size)) || read(fd, maze, st.st_size) < 0)) {
        write(2, "Error: couldn't open the file\n", 30);
        return (84);
    }
    for (size_t i = 0; maze[i] != '\n'; i++)
        width++;
    height += get_height(maze);
    if (solve(maze, height, width, 0) == false)
        printf("no solution found");
    else
        printf("%s", maze);
    free(maze);
    return (0);
}