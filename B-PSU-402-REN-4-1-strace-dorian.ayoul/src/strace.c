/*
** EPITECH PROJECT, 2022
** strace.c
** File description:
** strace
*/

#include "../include/syscall.h"

int display_val(char type, reg_size val, pid_t pid, bool s)
{
    int i = 0;

    if (s && type == NUM)
        return printf("%lld", val);
    if (s && type == STRING) {
        printf("\"");
        for (char c = 1; i < STR_MAX_SIZE && c != '\0'; i++, val++) {
            c = ptrace(PTRACE_PEEKDATA, pid, val, NULL);
            printf("%c", isprint(c) ? c : 0);
        }
        if (i == STR_MAX_SIZE)
            return printf("\"...");
        return printf("\"");
    }
    if (s && type != 0 && val == 0)
        return printf("NULL");
    return printf("%#llx", val);
}

void display(pid_t pid, struct user_regs_struct regs, bool s, reg_size *ret)
{
    syscall_t *syscall = &table[ORIG];

    if (strcmp(syscall->name, "rt_sigprocmask") == 0 ||
        strcmp(syscall->name, "execve") == 0)
        return;
    printf("%s(", syscall->name);
    for (char i = 0; i < syscall->args_nb; i++) {
        display_val(syscall->args[i], !i ? regs.rdi : i == 1 ? regs.rsi : i == 2
        ? regs.rdx : i == 3 ? regs.r10 : i == 4 ? regs.r8 : regs.r9, pid, s);
        if (i + 1 != syscall->args_nb)
            printf(", ");
    }
    if (ORIG == __NR_pkey_free || ORIG == __NR_exit || ORIG == __NR_exit_group)
        printf(") = ?\n");
    else {
        printf(") = ");
        display_val(syscall->ret, regs.rax, pid, s);
        printf("\n");
        *ret = regs.rax;
    }
}

int strace(pid_t pid, bool s)
{
    int status;
    struct user_regs_struct regs = {0};
    reg_size final_ret = 0;

    waitpid(pid, &status, 0);
    CHECK(ptrace(PTRACE_SETOPTIONS, pid, NULL, PTRACE_O_EXITKILL |
    PTRACE_O_TRACEEXIT | PTRACE_O_TRACESYSGOOD));
    for (unsigned short low_order_bytes; WIFSTOPPED(status) &&
        (WSTOPSIG(status) == SIGTRAP || WSTOPSIG(status) == SIGSTOP) &&
        ORIG != __NR_exit && ORIG != __NR_exit_group;) {
        CHECK(ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL));
        waitpid(pid, &status, 0);
        CHECK(ptrace(PTRACE_GETREGS, pid, NULL, &regs));
        CHECK(low_order_bytes = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL));
        if ((low_order_bytes & SYSCALL_HEX) && regs.rip != SYSCALL_HEX &&
            ORIG < SYSCALL_TABLE_SIZE)
            display(pid, regs, s, &final_ret);
    }
    printf("+++ exited with %lld +++\n", final_ret);
    return 0;
}

int start_with_pid(char *str, bool s)
{
    pid_t pid;
    int status;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return 84;
    pid = atoi(str);
    waitpid(pid, &status, 0);
    CHECK(ptrace(PTRACE_ATTACH, pid));
    return strace(pid, s);
}

int main(int ac, char **av)
{
    bool s = (ac > 1 && strcmp(av[1], "-s") == 0 ? true : false);
    pid_t pid;

    if (ac == 1 || ac == 2 && (strcmp(av[1], "-s") == 0 ||
        strcmp(av[1], "-p") == 0 || strcmp(av[1], "-h") == 0) ||
        ac == 3 && strcmp(av[1], "-s") == 0 && strcmp(av[2], "-p") == 0) {
        fprintf(stderr, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        return ERROR_CODE;
    }
    if (!(strcmp(av[1], "-p") == 0 || ac > 3 && strcmp(av[2], "-p") == 0)) {
        if ((pid = fork()) == 0) {
            CHECK(ptrace(PTRACE_TRACEME));
            CHECK(execvp(av[1 + s], &av[1 + s]));
            return 0;
        } else
            return strace(pid, s);
    }
    return start_with_pid(s ? av[3] : av[2], s);
}
