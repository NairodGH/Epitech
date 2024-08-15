/*
** EPITECH PROJECT, 2021
** file_utils.h
** File description:
** File utils
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_file(char const *path);

bool write_file(char *file, char *content);

bool file_exists(const char *filepath);