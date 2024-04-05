//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#pragma once
#ifndef _HOOKS_H
#define _HOOKS_H
#include "../../kernSDK/include/ksdk.h"
#include "./proc.h"
#include "./elf.h"

// custom syscall 109
#define SYS_PROC_ALLOC      1
#define SYS_PROC_FREE       2
#define SYS_PROC_PROTECT    3
#define SYS_PROC_VM_MAP     4
#define SYS_PROC_INSTALL    5
#define SYS_PROC_CALL       6
#define SYS_PROC_ELF        7
#define SYS_PROC_INFO       8
#define SYS_PROC_THRINFO    9

// custom syscall 112
#define SYS_CONSOLE_CMD_REBOOT       1
#define SYS_CONSOLE_CMD_PRINT        2
#define SYS_CONSOLE_CMD_JAILBREAK    3

// custom syscall 107
// Structure for a Process List Entry
struct proc_list_entry {
	char p_comm[32]; // Process name
	int pid; // Process ID
} __attribute__((packed));

// Arguments for system call proc_list
struct sys_proc_list_args {
	struct proc_list_entry *procs; // Pointer to an array of process list entries
	uint64_t *num; // Pointer to store the number of entries
} __attribute__((packed));

// custom syscall 108
// Arguments for system call proc_rw
struct sys_proc_rw_args {
	uint64_t pid; // Process ID
	uint64_t address; // Address of memory to read/write
	void *data; // Pointer to data buffer
	uint64_t length; // Length of data
	uint64_t write; // Flag indicating write operation
} __attribute__((packed));

// Arguments for system call proc_alloc
struct sys_proc_alloc_args {
	uint64_t address; // Address for allocation
	uint64_t length; // Length of memory to allocate
} __attribute__((packed));

// Arguments for system call proc_free
struct sys_proc_free_args {
	uint64_t address; // Address of memory to free
	uint64_t length; // Length of memory to free
} __attribute__((packed));

// Arguments for system call proc_protect
struct sys_proc_protect_args {
	uint64_t address; // Address of memory region
	uint64_t length; // Length of memory region
	uint64_t prot; // Protection flags
} __attribute__((packed));

// Arguments for system call proc_vm_map
struct sys_proc_vm_map_args {
	struct proc_vm_map_entry *maps; // Pointer to an array of memory maps
	uint64_t num; // Number of memory maps
} __attribute__((packed));

// Arguments for system call proc_install
struct sys_proc_install_args {
	uint64_t stubentryaddr; // Address of the stub entry
} __attribute__((packed));

// Arguments for system call proc_call
struct sys_proc_call_args {
	uint32_t pid; // Process ID
	uint64_t rpcstub; // Address of the remote procedure call stub
	uint64_t rax; // Value of RAX register
	uint64_t rip; // Value of RIP register
	uint64_t rdi; // Value of RDI register
	uint64_t rsi; // Value of RSI register
	uint64_t rdx; // Value of RDX register
	uint64_t rcx; // Value of RCX register
	uint64_t r8; // Value of R8 register
	uint64_t r9; // Value of R9 register
} __attribute__((packed));

// Arguments for system call proc_elf
struct sys_proc_elf_args {
	void *elf; // Pointer to ELF data
} __attribute__((packed));

// Arguments for system call proc_info
struct sys_proc_info_args {
	int pid; // Process ID
	char name[40]; // Process name
	char path[64]; // Path to the process executable
	char titleid[16]; // Title ID of the process
	char contentid[64]; // Content ID of the process
} __attribute__((packed));

// Arguments for system call proc_thrinfo
struct sys_proc_thrinfo_args {
	uint32_t lwpid; // LWP ID
	uint32_t priority; // Priority of the thread
	char name[32]; // Name of the thread
} __attribute__((packed));

// Arguments for system call proc_cmd
struct sys_proc_cmd_args {
	uint64_t pid; // Process ID
	uint64_t cmd; // Command
	void *data; // Additional data
} __attribute__((packed));

// custom syscall 110
// Arguments for system call kern_base
struct sys_kern_base_args {
	uint64_t *kbase; // Pointer to store the kernel base address
} __attribute__((packed));

// custom syscall 111
// Arguments for system call kern_rw
struct sys_kern_rw_args {
	uint64_t address; // Address of memory to read/write
	void *data; // Pointer to data buffer
	uint64_t length; // Length of data
	uint64_t write; // Flag indicating write operation
} __attribute__((packed));

// custom syscall 112
// Arguments for system call console_cmd
struct sys_console_cmd_args {
	uint64_t cmd; // Command
	void *data; // Additional data
} __attribute__((packed));

int sys_proc_list(struct thread *td, struct sys_proc_list_args *uap);
int sys_proc_rw(struct thread *td, struct sys_proc_rw_args *uap);
int sys_proc_cmd(struct thread *td, struct sys_proc_cmd_args *uap);
int sys_kern_base(struct thread *td, struct sys_kern_base_args *uap);
int sys_kern_rw(struct thread *td, struct sys_kern_rw_args *uap);
int sys_console_cmd(struct thread *td, struct sys_console_cmd_args *uap);

void hook_trap_fatal(struct trapframe *tf);
void install_syscall(uint32_t n, void *func);
int install_hooks();

#endif