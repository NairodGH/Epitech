/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static int error_handling_cd(char **cmd_block)
{
    size_t len = barray_len(cmd_block);

    if (!len) {
        error_command("cd", "Try again");
        return 1;
    }
    if (len > 2) {
        error_command("cd", "Too many arguments");
        return 1;
    }
    return 0;
}

static int manage_directory(char **cmd_block, list_t *env)
{
    int ret = 0;
    char *path = cmd_block[1];

    if (path) {
        ret = chdir(path);
        if (ret && !strcmp("-", path)) {
            path = get_env_value("OLDPWD", env);
            ret = chdir(path);
        }
    }
    else {
        path = get_env_value("HOME", env);
        if (!path) {
            error_command("cd", "No home directory");
            return 1;
        }
        ret = chdir(path);
    }
    ret ? error_command(path, strerror(errno)) : 0;
    return ret;
}

static void replace_pwd(char **cmd_block, list_t *env)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX - 1)) {
        replace_env_value("OLDPWD", get_env_value("PWD", env), env);
        replace_env_value("PWD", cwd, env);
    }
    else {
        error_command(cmd_block[1], strerror(errno));
    }
}

void cd_func(shell_t *shell, return_t *ret, block_t *block)
{
    if (error_handling_cd(block->cmd_block)) {
        ret->error_code = 1;
        return;
    }
    if (manage_directory(block->cmd_block, shell->env)) {
        ret->error_code = 1;
        return;
    }
    replace_pwd(block->cmd_block, shell->env);
}
