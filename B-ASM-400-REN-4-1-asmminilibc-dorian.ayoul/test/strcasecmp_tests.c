/*
** EPITECH PROJECT, 2022
** strcasecmp_tests.c
** File description:
** strcasecmp_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *handle;
static int(*symbol)(const char *, const char *) = NULL;

static void get_symbol(void)
{
    if (handle != NULL)
        return;
    handle = dlopen("../libasm.so", RTLD_LAZY);
    if (handle == NULL) {
        cr_log_warn("Couldn't open libasm.so at the root of the repository");
        return;
    }
    symbol = (int(*)(const char *, const char *))dlsym(handle, "strcasecmp");
}

static void close_lib(void)
{
    if (handle == NULL)
        return;
    dlclose(handle);
}

Test(strcasecmp, str_equal, .init=get_symbol, .fini=close_lib)
{
    char __s1[] = "test";
    char __s2[] = "TeSt";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strcasecmp(__s1, __s2), symbol(__s1, __s2));
}

Test(strcasecmp, str_not_equal, .init=get_symbol, .fini=close_lib)
{
    char __s1[] = "test";
    char __s2[] = "ToSt";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strcasecmp(__s1, __s2), symbol(__s1, __s2));
}

Test(strcasecmp, str_empty, .init=get_symbol, .fini=close_lib)
{
    char __s1[] = "";
    
    if (symbol == NULL)
        cr_skip_test();
    cr_assert_eq(strcasecmp(__s1, __s1), symbol(__s1, __s1));
}