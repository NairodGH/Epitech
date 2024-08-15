/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

env_t *get_path(void)
{
    char buf[PATH_MAX] = {0};

    if (!confstr(_CS_PATH, buf, PATH_MAX))
        return NULL;
    return create_env("PATH", bstrdup(buf));
}

env_t *get_shlvl(void)
{
    return create_env("SHLVL", "1");
}

env_t *get_pwd(void)
{
    char cwd[PATH_MAX] = {0};

    getcwd(cwd, PATH_MAX);
    return create_env("PWD", bstrdup(cwd));
}

env_t *get_oldpwd(void)
{
    return create_env("OLDPWD", "");
}

env_t *get_home(void)
{
    struct passwd *pw = getpwuid(getuid());

    if (pw)
        return create_env("HOME", pw->pw_dir);
    else return create_env("HOME", "");
}