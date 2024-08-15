/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

char *bstrcat_plus(char *word1, char *inter, char *word2)
{
    int len = strlen(word1) + strlen(inter) + strlen(word2);
    char *dest = calloc(sizeof(char), (len + 1));

    if (!dest)
        return NULL;
    strcpy(dest, word1);
    strcat(dest, inter);
    strcat(dest, word2);
    return dest;
}

char **env_to_array(list_t *list)
{
    list_node_t *temp_node = NULL;
    env_t *temp_env = NULL;
    char **array = binit_array_light(0);
    char *temp = NULL;

    foreach(list->head, temp_node) {
        temp_env = (env_t  *)temp_node->data;
        temp = bstrcat_plus(temp_env->var, "=", temp_env->value);
        if (!temp)
            return NULL;
        array = badd_array(array, temp);
    }
    return array;
}
