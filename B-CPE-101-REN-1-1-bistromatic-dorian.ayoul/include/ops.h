/*
** EPITECH PROJECT, 2020
** Header for operations
** File description:
** ~
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef OPS_H
#define OPS_H

int is_op(char str);
int is_prio(char str);
int comp_prio(char *stack, char str, int *stackcount);
void push_stack(char **dest, char *stack, int *stackcount, int *d);
void parenthesis(char str, char *stack, int *stackcount);
void push_par(char **dest, char *stack, int *stackcount, int *d);
void set_end(char **dest, int *d, int *count);
void set_count(char **dest, char str, int d, int *count);
void set_stack(char *stack, char *str, int i, int *stackcount);
int checkpar(char *str, int i);
char **trad(char *str);

#endif