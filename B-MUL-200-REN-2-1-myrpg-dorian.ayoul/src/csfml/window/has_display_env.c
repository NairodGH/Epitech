/*
** EPITECH PROJECT, 2021
** has_display_env.c
** File description:
** Check if the display environment variable is set
*/

#include <window.h>
#include <nep/nstring.h>

PRIVATE bool is_display_env(char *env)
{
    char *disp = "DISPLAY=";
    nsize_t len = nstrlen(disp);

    if (env == NULL)
        return (false);
    if (nstrlen(env) < len)
        return (false);
    return (nstrncmp(env, disp, nstrlen(disp)));
}

bool has_display_env(char **env)
{
    bool has_env = false;

    if (env == NULL)
        return (false);
    for (unsigned int itr = 0; env[itr]; ++itr)
        has_env = has_env || is_display_env(env[itr]);
    return (has_env);
}