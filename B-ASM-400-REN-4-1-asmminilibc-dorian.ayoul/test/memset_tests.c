/*
** EPITECH PROJECT, 2022
** memset_tests.c
** File description:
** memset_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static void *(*symbol)(void *, int, size_t) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (void *(*)(void *, int, size_t))dlsym(handle, "memset");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(memset, normal_case, .init=get_symbol, .fini=close_lib)
{
    char __s[5];
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memset(__s, 't', 5), symbol(__s, 't', 5));
}

Test(memset, too_big_case, .init=get_symbol, .fini=close_lib)
{
    char __s[1];

    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memset(__s, 't', 10), symbol(__s, 't', 10));
}

Test(memset, null_case, .init=get_symbol, .fini=close_lib)
{
    char *__s = NULL;

    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(memset(__s, 't', 0), symbol(__s, 't', 0));
}