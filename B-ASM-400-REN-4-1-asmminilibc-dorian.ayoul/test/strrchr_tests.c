/*
** EPITECH PROJECT, 2022
** strrchr_tests.c
** File description:
** strrchr_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static char *(*symbol)(const char *, int) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (char *(*)(const char *, int))dlsym(handle, "strrchr");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strrchr, normal_str, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "test";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strrchr(__s, 't'), symbol(__s, 't'));
}

Test(strrchr, empty_str, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "";

    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strrchr(__s, 'a'), symbol(__s, 'a'));
}

Test(strrchr, str_with_null_char, .init=get_symbol, .fini=close_lib)
{
    const char __s[] = "test\0toast";

    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strchr(__s, 'o'), symbol(__s, 'o'));
}