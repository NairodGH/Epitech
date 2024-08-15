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
    symbol = (void *(*)(void*, const void *, size_t))dlsym(handle, "memcpy");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(memcpy, normal_case, .init=get_symbol, .fini=close_lib)
{
    char __dest[4];
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memcpy(__dest, "testtest", 4), symbol(__dest, "testtest", 4));
}

Test(memcpy, too_big_case, .init=get_symbol, .fini=close_lib)
{
    char __dest[5];
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_str_eq(memcpy(__dest, "test\0", 10), symbol(__dest, "test\0", 10));
}

Test(memcpy, null_case, .init=get_symbol, .fini=close_lib)
{
    char *__dest = NULL;
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(memcpy(__dest, "test", 0), symbol(__dest, "test", 0));
}