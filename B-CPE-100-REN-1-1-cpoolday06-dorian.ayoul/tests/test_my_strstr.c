/*
** EPITECH PROJECT, 2020
** test_my_strstr
** File description:
** Test file for my_strstr
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, searches_for_a_string_inside_another)
{
    char tab[] = "I say HelloWorld !";
    char test[] = "HelloWorld";

    my_strstr(tab, test);
    cr_assert_str_eq(my_strstr(tab, test), "HelloWorld !");
}