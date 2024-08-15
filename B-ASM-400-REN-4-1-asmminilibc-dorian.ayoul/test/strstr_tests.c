/*
** EPITECH PROJECT, 2022
** strstr_tests.c
** File description:
** strstr_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static char *(*symbol)(char *, const char *) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (char *(*)(char *, const char *))dlsym(handle, "strstr");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strstr, str_find, .init=get_symbol, .fini=close_lib)
{
    char __haystack[] = "a simple test";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(strstr(__haystack, "test"), symbol(__haystack, "test"));
}

Test(strstr, str_cant_find, .init=get_symbol, .fini=close_lib)
{
    char __haystack[] = "a simple what ?";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_null(symbol(__haystack, "test"));
}

Test(strstr, str_empty, .init=get_symbol, .fini=close_lib)
{
    char __haystack[] = "";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_null(symbol(__haystack, "test"));
}