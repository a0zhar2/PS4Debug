//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#pragma once
#ifndef _PROC_H
#define _PROC_H
#include "../../kernSDK/include/ksdk.h"
#include "rpcasm.h"
#include "elf.h"

#define PAGE_SIZE 0x4000

// Structure representing a memory map entry for a process
struct proc_vm_map_entry {
    char name[32]; // Name of the mapped region
    uint64_t start; // Start address of the mapped region
    uint64_t end; // End address of the mapped region
    uint64_t offset; // Offset of the mapped region
    uint16_t prot; // Protection flags of the mapped region
} __attribute__((packed));

struct proc *proc_find_by_name(const char *name);
struct proc *proc_find_by_pid(int pid);

int proc_get_vm_map(struct proc *p, struct proc_vm_map_entry **entries, uint64_t *num_entries);
int proc_rw_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n, int write);
int proc_read_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n);
int proc_write_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n);
int proc_allocate(struct proc*p, void **address, uint64_t size);
int proc_deallocate(struct proc *p, void *address, uint64_t size);
int proc_mprotect(struct proc *p, void *address, uint64_t size, int new_prot);
int proc_create_thread(struct proc *p, uint64_t address);
int proc_map_elf(struct proc *p, void *elf, void *exec);
int proc_relocate_elf(struct proc *p, void *elf, void *exec);
int proc_load_elf(struct proc *p, void *elf, uint64_t *elfbase, uint64_t *entry);

#endif
