/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class   base;
    int     x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this)
        return;
    return;
}

static char *Point_str(PointClass *this)
{
    int size = 8 + strlen(this->base.__name__) + int_length(this->x) +
        int_length(this->y);
    char *buffer = calloc(sizeof(char), size);

    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, size, "<%s (%d, %d)>", this->base.__name__, this->x,
        this->y);
    return buffer;
}

static Object *Point_add(const PointClass *this, const PointClass
    *other)
{
    return new(Point, this->x + other->x, this->y + other->y);
}

static Object *Point_sub(const PointClass *this, const PointClass
    *other)
{
    return new(Point, this->x - other->x, this->y - other->y);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
