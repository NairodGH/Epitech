/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct {
    Class   base;
    float   x;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    if (this)
        return;
    return;
}

static char *float_str(FloatClass *this)
{
    int size = 6 + strlen(this->base.__name__) + int_length(this->x) + 7;
    char *buffer = calloc(sizeof(char), size);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, size, "<%s (%f)>", this->base.__name__, this->x);
    return buffer;
}

static Object *float_add(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Float, this->x + other->x);
}

static Object *float_sub(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Float, this->x - other->x);
}

static Object *float_mul(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return new(Float, this->x * other->x);
}

static Object *float_div(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    if (other->x == 0.f)
        raise("Division by 0");
    return new(Float, this->x / other->x);
}

static bool float_eq(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x == other->x;
}

static bool float_gt(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x > other->x;
}

static bool float_lt(const FloatClass *this, const FloatClass *other)
{
    if (other == NULL)
        raise("Invalid class");
    return this->x < other->x;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;
