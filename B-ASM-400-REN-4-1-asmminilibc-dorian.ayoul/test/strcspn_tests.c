/*
** EPITECH PROJECT, 2022
** strcspn_tests.c
** File description:
** strcspn_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static size_t(*symbol)(const char *, const char *) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (size_t(*)(const char *, const char *))dlsym(handle, "strcspn");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strcspn, str_find, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "test with b :)";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strcspn(__s, "abcd"), symbol(__s, "abcd"));
}

Test(strcspn, str_cant_find, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "those are hard ones";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strcspn(__s, "xyz"), symbol(__s, "xyz"));
}

Test(strcspn, str_empty, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_null(symbol(__s, "duh"));
}