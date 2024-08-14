/*
** EPITECH PROJECT, 2020
** test_my_revstr
** File description:
** Test for my_revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, reverses_a_string)
{
    char dest[] = "HelloWorld";

    my_revstr(dest);
    cr_assert_str_eq(dest, "dlroWolleH");
}