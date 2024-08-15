/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct {
    Class   base;
    char    c;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
    if (this)
        return;
    return;
}

static char *char_str(CharClass *this)
{
    int size = 6 + strlen(this->base.__name__) + sizeof(char);
    char *buffer = calloc(sizeof(char), size);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, size, "<%s (%c)>", this->base.__name__, this->c);
    return buffer;
}

static Object *char_add(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Char, this->c + other->c);
}

static Object *char_sub(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Char, this->c - other->c);
}

static Object *char_mul(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Char, this->c * other->c);
}

static Object *char_div(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    if (other->c == '\0')
        raise("Division by 0");
    return new(Char, this->c / other->c);
}

static bool char_eq(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->c == other->c;
}

static bool char_gt(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->c > other->c;
}

static bool char_lt(const CharClass *this, const CharClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->c < other->c;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_str,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;
