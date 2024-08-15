/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop{
*/

#include "ftrace.h"

const signal_t sigmap[] =
{
    {SIGHUP, "SIGHUP"},
    {SIGINT, "SIGINT"},
    {SIGQUIT, "SIGQUIT"},
    {SIGILL, "SIGILL"},
    {SIGTRAP, "SIGTRAP"},
    {SIGABRT, "SIGABRT"},
    {SIGBUS, "SIGBUS"},
    {SIGFPE, "SIGFPE"},
    {SIGKILL, "SIGKILL"},
    {SIGUSR1, "SIGUSR1"},
    {SIGSEGV, "SIGSEGV"},
    {SIGUSR2, "SIGUSR2"},
    {SIGPIPE, "SIGPIPE"},
    {SIGALRM, "SIGALRM"},
    {SIGTERM, "SIGTERM"},
    {SIGSTKFLT, "SIGSTKFLT"},
    {SIGCHLD, "SIGCHLD"},
    {SIGCONT, "SIGCONT"},
    {SIGSTOP, "SIGSTOP"},
    {SIGTSTP, "SIGTSTP"},
    {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"},
    {SIGURG, "SIGURG"},
    {SIGXCPU, "SIGXCPU"},
    {SIGXFSZ, "SIGXFSZ"},
    {SIGVTALRM, "SIGVTALRM"},
    {SIGPROF, "SIGPROF"},
    {SIGWINCH, "SIGWINCH"},
    {SIGPOLL, "SIGPOLL"},
    {SIGPWR, "SIGPWR"},
    {SIGSYS, "SIGSYS"},
    {0, NULL}
};

void handle_signal(ftrace_t *ftrace)
{
    siginfo_t sig = {0};

    if (ptrace(PTRACE_GETSIGINFO, ftrace->pid, 0, &sig) == -1 ||
        sig.si_signo == SIGSTOP || sig.si_signo == SIGTRAP)
        return;
    if (SIGHUP <= sig.si_signo && sig.si_signo <= SIGTERM)
        return handle_exit(ftrace);
    for (size_t i = 15; sigmap[i].si_signo; i++)
        if (sigmap[i].si_signo == sig.si_signo)
            fprintf(stderr, "Received signal %s\n", sigmap[i].string);
}
