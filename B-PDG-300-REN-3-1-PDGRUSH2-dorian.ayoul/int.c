/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct {
    Class   base;
    int     x;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    if (this)
        return;
    return;
}

static char *int_str(IntClass *this)
{
    int size = 6 + strlen(this->base.__name__) + int_length(this->x);
    char *buffer = calloc(sizeof(char), size);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, size, "<%s (%d)>", this->base.__name__, this->x);
    return buffer;
}

static Object *int_add(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Int, this->x + other->x);
}

static Object *int_sub(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Int, this->x - other->x);
}

static Object *int_mul(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Int, this->x * other->x);
}

static Object *int_div(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    if (other->x == 0)
        raise("Division by 0");
    return new(Int, this->x / other->x);
}

static bool int_eq(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x == other->x;
}

static bool int_gt(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x > other->x;
}

static bool int_lt(const IntClass *this, const IntClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x < other->x;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_str,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
