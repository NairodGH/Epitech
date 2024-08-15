/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

void my_exit(char *ab);
void my_cd(char *ab, char **env);
int my_env(char *ab, char **env, char **set, int mode);
void my_setenv(char *ab, char **env, char **set);
void my_unsetenv(char *ab, char **set);

int str(char *arr1, char *arr2, int mode);