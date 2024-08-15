/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-mydefender-aurelien.marcel
** File description:
** health_bar
*/

#ifndef ENVDATA_H_
#define ENVDATA_H_

#include <stdbool.h>

typedef struct token_s {
    char sep;
    char *raw;
    unsigned int len;
    unsigned int id;
    unsigned int pos;
} token_t;

typedef struct envkey_s {
    char *key;
    char *value;
} envkey_t;

int my_arrcount(char **tab);

char **my_strtok(char *str, char c);

envkey_t *create_env_key(char *key, char *value);

envkey_t **get_env_from_file(char *file_path);

char *get_env_value(envkey_t **keys, char *key_search);

char *get_env_valuedef(envkey_t **keys, char *key_search, char *def);

envkey_t *parse_env(char *str);

int get_env_len(envkey_t **env);

char *convert_env_to_str(envkey_t **env);

envkey_t **create_env_list(int count);

bool save_env_array(char *file_path, envkey_t **env);

bool env_exists(envkey_t **env, char *key);

void update_env(envkey_t **env, char *key, char *value);

#endif /* !ENVDATA_H_ */
