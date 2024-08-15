/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef SH_H
#define SH_H

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>

#include "blib.h"
#include "linked_list.h"

#include "env.h"
#include "variable.h"
#include "tokenizer.h"
#include "resolver.h"
#include "executer.h"

#include "shell.h"
#include "block.h"
#include "return.h"

// ERROR HANDLING
void error_command(char *command_name, char *error_type);

int main_loop(shell_t *shell, bool is_tty, return_t *ret);

// DETROY
void destroy_all(shell_t *shell, return_t *ret);

#endif // SH_H
