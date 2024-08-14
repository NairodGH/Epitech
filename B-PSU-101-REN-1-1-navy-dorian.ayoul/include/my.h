/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

void my_putchar(char c);
int my_strlen(char *str);
int my_atoi(char *str);
int connection(int ac, char **av);
int load_boards(char board1[10][18], char board2[10][18], int ac, char **av);
int defend(char board1[10][18]);
int display(char board1[10][18], char board2[10][18]);