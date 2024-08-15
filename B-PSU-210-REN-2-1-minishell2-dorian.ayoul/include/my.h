/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef MY_H
#define MY_H

void my_exit(char *input);
char **my_cd(char *input, char **env);
char **my_env(char **env);
char **my_setenv(char *input, char **env);
char **my_unsetenv(char *input, char **env);
int find_bin(char *input, char **env);
char **pipe_command(char **cmds, char *order, char **env, size_t i);
char **get_command(char *input, char **env);

#endif