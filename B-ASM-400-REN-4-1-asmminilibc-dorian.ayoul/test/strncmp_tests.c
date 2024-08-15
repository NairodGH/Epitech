/*
** EPITECH PROJECT, 2022
** strncmp_tests.c
** File description:
** strncmp_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static int(*symbol)(const char *, const char *, size_t) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (int(*)(const char *, const char *, size_t))dlsym(handle, "strncmp");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strncmp, str_equal, .init=get_symbol, .fini=close_lib)
{
    char str1[] = "test";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strncmp(str1, str1, 4), symbol(str1, str1, 4));
}

Test(strncmp, str_not_equal, .init=get_symbol, .fini=close_lib)
{
    char str1[] = "test";
    char str2[] = "testtest";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strncmp(str1, str2, 8), symbol(str1, str2, 8));
}

Test(strncmp, empty, .init=get_symbol, .fini=close_lib)
{
    char str1[] = "";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strncmp(str1, str1, 0), symbol(str1, str1, 0));
}