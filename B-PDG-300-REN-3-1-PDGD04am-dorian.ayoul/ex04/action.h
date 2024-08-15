/*
** EPITECH PROJECT, 2022
** action.h
** File description:
** ptr func
*/

#pragma once

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);

static void (*ptr_func[])(const char *str) =
{
    print_normal,
    print_reverse,
    print_upper,
    print_42
};