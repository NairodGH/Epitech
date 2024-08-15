/*
** EPITECH PROJECT, 2022
** memcpy_tests.c
** File description:
** memcpy_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static void *(*symbol)(void *, const void *, size_t) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (void *(*)(void*, const void *, size_t))dlsym(handle, "memmove");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(memmove, normal_case, .init=get_symbol, .fini=close_lib)
{
    char __dest[4];
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memmove(__dest, "testtest", 4), symbol(__dest, "testtest", 4));
}

Test(memmove, empty_case, .init=get_symbol, .fini=close_lib)
{
    char __dest[1];
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memmove(__dest, "", 1), symbol(__dest, "", 1));
}

Test(memmove, null_case, .init=get_symbol, .fini=close_lib)
{
    char *__dest = NULL;
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(memmove(__dest, "test", 0), symbol(__dest, "test", 0));
}