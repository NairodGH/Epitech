/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function file for CPE Dante's star project
*/

#include "../lib/my/lib.h"
#include "../include/generator.h"

void display_help(void)
{
    printf("Dante's star is an EPITECH CPE-200 solo project. This project is ");
    printf("in 2 parts: one generates a perfect/imperfect maze with a given ");
    printf("height/width and the other solves a maze with it's given file ");
    printf("path.\n\nUSAGE\n./generator height width [perfect]\tgenerate the ");
    printf("maze\n./generator -h\tprogram usage\n");
    exit(0);
}

int args_error_handling(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        display_help();
    if (ac != 3 && ac != 4) {
        write(2, "Error: there must be 2 or 3 arguments\n", 38);
        exit(84);
    }
    if (str_is_positive_int(av[1]) == false ||
    str_is_positive_int(av[2]) == false) {
        write(2, "Error: argument 1 and 2 must be positive integers\n", 50);
        exit(84);
    }
    if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        write(2, "Error: argument 3 must be the word 'perfect'\n", 45);
        exit(84);
    }
    return (0);
}

int binary(char *maze, map_t map, int i, bool perfect)
{
    if (!perfect && i == map.total - 1 && i - map.width > 0)
        maze[i - map.width] = '*';
    if (!perfect && i == map.total - 1 && i - 1 != 0 && maze[i - 1] != '\n')
        maze[i - 1] = '*';
    if (rand() % 2 == 0 && i - map.width > 0) {
        maze[i - map.width] = '*';
        maze[i--] = '*';
        if (maze[i] != '\n')
            i--;
    }
    else {
        maze[i--] = '*';
        if (maze[i] != '\n')
            maze[i--] = '*';
    }
    if (i >= 0 && maze[i] == '\n')
        i -= map.width + 1;
    return (i);
}

int main(int ac, char **av)
{
    int error = args_error_handling(ac, av);
    map_t map = {atoi(av[1]), atoi(av[2]) + 1, map.height * map.width - 1};
    char *maze = malloc(sizeof(char) * map.total);

    if (maze == NULL || map.height == 0 || map.width - 1 == 0)
        return (84);
    memset(maze, 'X', map.total);
    for (size_t i = 0; i != map.width - 1; i++)
        maze[i] = '*';
    for (size_t i = 1; i != map.height; i++) {
        maze[i * map.width] = '*';
        maze[i * map.width - 1] = '\n';
    }
    srand(time(NULL));
    for (int i = map.total - 1; i > 0;)
        i = binary(maze, map, i, ac == 4 ? 1 : 0);
    printf("%s", maze);
    free(maze);
    return (0);
}