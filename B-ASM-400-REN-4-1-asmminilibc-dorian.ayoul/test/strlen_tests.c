/*
** EPITECH PROJECT, 2022
** strlen_tests.c
** File description:
** strlen_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static size_t (*symbol)(const char *) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (size_t(*)(const char *))dlsym(handle, "strlen");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strlen, normal_str, .init=get_symbol, .fini=close_lib)
{
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strlen("test"), symbol("test"));
}

Test(strlen, empty_str, .init=get_symbol, .fini=close_lib)
{
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strlen(""), symbol(""));
}

Test(strlen, str_with_null_char, .init=get_symbol, .fini=close_lib)
{
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strlen("test\0test"), symbol("test\0test"));
}