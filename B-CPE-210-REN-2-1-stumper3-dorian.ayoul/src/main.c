/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main project file
*/

#include "my.h"
#include "sandpile.h"

static int check_args_error(int ac, char **av)
{
    if (ac != 4) {
        write(2, "Error: there must be 4 parameters\n", 34);
        return (84);
    }
    if (my_strlen(av[2]) != 4) {
        write(2, "Error: arg 2 must contain 4 characters\n", 39);
        return (84);
    }
    for (int i = 0; av[2][i] != '\0'; i++)
        if (av[2][i] == av[2][0] && i != 0 || av[2][i] == av[2][1] && i != 1 ||
            av[2][i] == av[2][2] && i != 2 || av[2][i] == av[2][3] && i != 3) {
            write(2, "Error: arg 2 characters must be different\n", 42);
            return (84);
        }
    for (int i = 0; av[3][i] != '\0'; i++)
        if (av[3][i] < 48 || av[3][i] > 57) {
            write(2, "Error: arg 3 must be a positive integer\n", 40);
            return (84);
        }
    return (0);
}

static int check_file_error(char *buff, char *sand)
{
    if (my_strlen(buff) == 0 || get_map_length(buff) == 0) {
        write(2, "Error: file map mustn't be empty\n", 33);
        return (84);
    }
    for (int i = 0, count = 0; buff[i] != '\0'; i++, count++) {
        if (buff[i] == '\n' && count != get_map_length(buff)) {
            write(2, "Error: the file map must be rectangular\n", 40);
            return (84);
        }
        if (buff[i] == '\n')
            count = -1;
    }
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != '\n' && !(buff[i] == sand[0] || buff[i] == sand[1] ||
            buff[i] == sand[2] || buff[i] == sand[3])) {
            write(2, "Error: file map must contains arg 2 chars\n", 42);
            return (84);
        }
    }
    return (0);
}

static int get_2d_map(char ***map, char *buff)
{
    char **temp;

    temp = malloc(sizeof(char *) * get_map_height(buff));
    if (temp == NULL)
        return (84);
    for (int i = 0; i != get_map_height(buff); i++) {
        temp[i] = malloc(sizeof(char) * (get_map_length(buff) + 1));
        if (temp[i] == NULL)
            return (84);
    }
    for (int i = 0, k = 0; i != get_map_height(buff); i++) {
        for (int j = 0; j != get_map_length(buff); j++, k++) {
            temp[i][j] = buff[k];
        }
        temp[i][get_map_length(buff)] = '\0';
        k++;
    }
    *map = temp;
    return (0);
}

int main(int ac, char **av)
{
    struct stat st;
    char *buff;
    char **map;
    int fd;

    if (check_args_error(ac, av) == 84)
        return (84);
    if (stat(av[1], &st) == -1 || (fd = open(av[1], O_RDONLY)) == -1 ||
        !(buff = malloc(st.st_size + 1)) || read(fd, buff, st.st_size) == -1) {
        write(2, "Error: arg 1 file couldn't be opened\n", 37);
        return (84);
    }
    buff[st.st_size] = '\0';
    if (check_file_error(buff, av[2]) == 84)
        return (84);
    if (get_2d_map(&map, buff) == 84)
        return (84);
    sandpile(map, get_map_height(buff), av[2], my_getnbr(av[3]));
    free(buff);
    return (0);
}
