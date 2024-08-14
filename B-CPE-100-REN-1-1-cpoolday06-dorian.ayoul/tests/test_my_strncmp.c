/*
** EPITECH PROJECT, 2020
** test_my_strncmp
** File description:
** Test file for my_strncmp
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, compares_a_string_to_another_until_n)
{
    char tab[] = "HelloWorld";
    char test[] = "Hello";

    my_strncmp(tab, test, 5);
    cr_assert_eq(my_strncmp(tab, test, 5), 87);
}