/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdarg.h>
#include "object.h"
#include "new.h"

int int_length(int number)
{
    int length = !number;

    if (number < 0)
        length++;
    for (; number; length++)
        number /= 10;
    return length;
}

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj = NULL;

    if (!class)
        raise("Invalid class");
    va_start(ap, NULL);
    obj = va_new(class, &ap);
    va_end(ap);
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return obj;
}

void delete(Object *ptr)
{
    Class *ptr_class = (Class *)ptr;

    if (ptr) {
        if (ptr_class->__dtor__)
            ptr_class->__dtor__(ptr_class);
        free(ptr);
    }
    else
        raise("Invalid class");
}
