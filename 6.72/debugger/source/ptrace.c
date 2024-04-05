//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#include "../../libPS4/include/ps4.h"
#include "../include/ptrace.h"

// A Custom PTrace Implementation
int ptrace(int req, int pid, void *addr, int data) {
    errno = NULL;
    int r = -1;

    // Attempt to make a system call to ptrace exec
    // ptrace syscall number is 26
    r = syscall(26, req, pid, addr, data);
    if (r == -1) return -1;

    // Optional:
    // uprintf("ptrace(req %i, pid %i, addr 0x%llX, data 0x%X) = %i (errno %i)", req, pid, addr, data, r, errno);
    return r;
}

int wait4(int wpid, int *status, int options, void *rusage) {
    // Attempt to make a system call to wait4 exec
    // wait4 syscall number is 7
    return syscall(7, wpid, status, options, rusage);
}
