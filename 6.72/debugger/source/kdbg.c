//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#include "../include/kdbg.h"

void prefault(void *address, size_t size) {
    for (uint64_t i = 0; i < size; i++) {
        volatile uint8_t c;
        (void)c;

        c = ((char *)address)[i];
    }
}

void *pfmalloc(size_t size) {
    void *p = malloc(size);
    prefault(p, size);
    return p;
}

void hexdump(void *data, size_t size) {
    unsigned char *p;
    int i;

    p = (unsigned char *)data;

    for (i = 0; i < size; i++) {
        uprintf("%02X ", *p++);
        if (!(i % 16) && i != 0) {
            uprintf("\n");
        }
    }

    uprintf("\n");
}

// custom syscall 107
int sys_proc_list(struct proc_list_entry *procs, uint64_t *num) {
    return syscall(107, procs, num);
}

// custom syscall 108
int sys_proc_rw(uint64_t pid, uint64_t address, void *data, uint64_t length, uint64_t write) {
    nlPrintf("Performing Process Read/Write Operation:");
    nlPrintf("PID %llu", pid);
    nlPrintf("Address %llu", address);
    nlPrintf("Length %llu",length);
    nlPrintf("Write = %s, Read = %s",
        write ? "YES" : "NO",
        write ? "YES" : "NO"
    );
    return syscall(108, pid, address, data, length, write);
}

// Custom Syscall 109
int sys_proc_cmd(uint64_t pid, uint64_t cmd, void *data) {
    return syscall(109, pid, cmd, data);
}

// Custom Syscall 110
int sys_kern_base(uint64_t *kbase) {
    return syscall(110, kbase);
}

// Custom Syscall 111
int sys_kern_rw(uint64_t address, void *data, uint64_t length, uint64_t write) {
    return syscall(111, address, data, length, write);
}

// Custom Syscall 112
int sys_console_cmd(uint64_t cmd, void *data) {
    return syscall(112, cmd, data);
}
