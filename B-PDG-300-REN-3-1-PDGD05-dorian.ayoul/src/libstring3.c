/*
** EPITECH PROJECT, 2022
** libstring.c
** File description:
** lib of strings ?
*/

#include "../string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;
    size_t d = pos;
    if (n + pos < strlen(this->str) && pos > strlen(this->str))
        return 0;
    for (; d != n; d++, i++) {
        if (this->str[d] == '\0') {
            s[i] = '\0'; 
            return i + 1;
        }
        s[i] = this->str[d];
    }
    return i;
}

const char *c_str(const string_t *this)
{
    return this->str;
}

int empty(const string_t *this)
{
    if (this->str[0] == '\0')
        return 1;
    else
        return 0;
}