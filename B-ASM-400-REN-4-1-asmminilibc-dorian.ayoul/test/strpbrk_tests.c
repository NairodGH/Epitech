/*
** EPITECH PROJECT, 2022
** strpbrk_tests.c
** File description:
** strpbrk_tests
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
    symbol = (char *(*)(char *, const char *))dlsym(handle, "strpbrk");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strpbrk, str_find, .init=get_symbol, .fini=close_lib)
{
    char __s[] = "test with b :)";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(strpbrk(__s, "abcd"), symbol(__s, "abcd"));
}

Test(strpbrk, str_cant_find, .init=get_symbol, .fini=close_lib)
{
    char __s[] = "those are hard ones";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_null(symbol(__s, "xyz"));
}

Test(strpbrk, str_empty, .init=get_symbol, .fini=close_lib)
{
    char __s[] = "";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_null(symbol(__s, "duh"));
}