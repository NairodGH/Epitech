/*
** EPITECH PROJECT, 2022
** libstring.c
** File description:
** lib of strings ?
*/

#include "../string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at_norm;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void assign_s(string_t *this, const string_t* str)
{
    if (this->str)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}