/*
** EPITECH PROJECT, 2022
** libstring.c
** File description:
** lib of strings ?
*/

#include "../string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = this->str;

    asprintf(&this->str, "%s%s", this->str, ap->str);
    free(tmp);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = this->str;

    asprintf(&this->str, "%s%s", this->str, ap);
    free(tmp);
}

char at_norm(const string_t *this, size_t pos)
{
    if (pos > strlen(this->str))
        return -1;
    return (this->str[pos]);
}

void clear(string_t *this)
{
    assign_c(this, "");
}

int length(const string_t *this)
{
    if (!this->str)
        return -1;
    return (strlen(this->str));
}