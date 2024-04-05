//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#pragma once
#ifndef _DEBUG_H
#define _DEBUG_H

#include "../../libPS4/include/types.h"
#include "./protocol.h"
#include "./net.h"
#include "./ptrace.h"

// Definition of a structure representing 64-bit general-purpose registers
struct __reg64 {
    uint64_t r_r15; // R15 register
    uint64_t r_r14; // R14 register
    uint64_t r_r13; // R13 register
    uint64_t r_r12; // R12 register
    uint64_t r_r11; // R11 register
    uint64_t r_r10; // R10 register
    uint64_t r_r9; // R9 register
    uint64_t r_r8; // R8 register
    uint64_t r_rdi; // RDI register
    uint64_t r_rsi; // RSI register
    uint64_t r_rbp; // RBP register
    uint64_t r_rbx; // RBX register
    uint64_t r_rdx; // RDX register
    uint64_t r_rcx; // RCX register
    uint64_t r_rax; // RAX register
    uint32_t r_trapno; // Trap number
    uint16_t r_fs; // FS segment register
    uint16_t r_gs; // GS segment register
    uint32_t r_err; // Error code
    uint16_t r_es; // ES segment register
    uint16_t r_ds; // DS segment register
    uint64_t r_rip; // RIP register
    uint64_t r_cs; // CS register
    uint64_t r_rflags; // RFLAGS register
    uint64_t r_rsp; // RSP register
    uint64_t r_ss; // SS register
};

// Contents of each x87 floating point accumulator
struct fpacc87 {
    uint8_t fp_bytes[10]; // Floating point bytes
};

// Contents of each SSE extended accumulator
struct xmmacc {
    uint8_t xmm_bytes[16]; // SSE bytes
};

// Contents of the upper 16 bytes of each AVX extended accumulator
struct ymmacc {
    uint8_t ymm_bytes[16]; // AVX bytes
};

// Environment for XMM registers
struct envxmm {
    uint16_t en_cw; // Control word
    uint16_t en_sw; // Status word
    uint8_t en_tw; // Tag word
    uint8_t en_zero; // Reserved
    uint16_t en_opcode; // Last executed opcode
    uint64_t en_rip; // Floating point instruction pointer
    uint64_t en_rdp; // Floating operand pointer
    uint32_t en_mxcsr; // SSE control/status register
    uint32_t en_mxcsr_mask; // Valid bits in mxcsr
};

// Structure for saving FPU state
struct savefpu {
    struct envxmm sv_env; // Environment for XMM registers
    struct {
        struct fpacc87 fp_acc; // x87 floating point accumulator
        uint8_t fp_pad[6]; // Padding
    } sv_fp[8]; // Array of x87 FPUs
    struct xmmacc sv_xmm[16]; // Array of SSE accumulators
    uint8_t sv_pad[96]; // Padding
} __attribute__((aligned(16)));

// Header for extended state
struct xstate_hdr {
    uint64_t xstate_bv; // Bitmap of extended state features
    uint8_t xstate_rsrv0[16]; // Reserved
    uint8_t xstate_rsrv[40]; // Reserved
};

// Structure for saving FPU state with extended features
struct savefpu_xstate {
    struct xstate_hdr sx_hd; // Extended state header
    struct ymmacc sx_ymm[16]; // Array of AVX accumulators
};

// Structure for saving FPU state with extended features including AVX
struct savefpu_ymm {
    struct envxmm sv_env; // Environment for XMM registers
    struct {
        struct fpacc87 fp_acc; // x87 floating point accumulator
        int8_t fp_pad[6]; // Padding
    } sv_fp[8]; // Array of x87 FPUs
    struct xmmacc sv_xmm[16]; // Array of SSE accumulators
    uint8_t sv_pad[96]; // Padding
    struct savefpu_xstate sv_xstate; // Extended state
} __attribute__((aligned(64)));

// Definition of debug registers
struct __dbreg64 {
    uint64_t dr[16]; // Debug registers
    // Index 0-3: debug address registers
    // Index 4-5: reserved
    // Index 6: debug status
    // Index 7: debug control
    // Index 8-15: reserved
};

// Structure for debug interrupt packet
struct debug_interrupt_packet {
    uint32_t lwpid; // LWP ID
    uint32_t status; // Status
    char tdname[40]; // Thread name
    struct __reg64 reg64; // 64-bit general-purpose registers
    struct savefpu_ymm savefpu __attribute__((aligned(64))); // FPU state with extended features
    struct __dbreg64 dbreg64; // Debug registers
} __attribute__((packed));


#define DEBUG_INTERRUPT_PACKET_SIZE         0x4A0

#define	DBREG_DR7_DISABLE       0x00
#define	DBREG_DR7_LOCAL_ENABLE  0x01
#define	DBREG_DR7_GLOBAL_ENABLE 0x02

#define	DBREG_DR7_LEN_1     0x00	/* 1 byte length */
#define	DBREG_DR7_LEN_2     0x01
#define	DBREG_DR7_LEN_4     0x03
#define	DBREG_DR7_LEN_8     0x02

#define	DBREG_DR7_EXEC      0x00	/* break on execute       */
#define	DBREG_DR7_WRONLY    0x01	/* break on write         */
#define	DBREG_DR7_RDWR      0x03	/* break on read or write */

#define	DBREG_DR7_GD        0x2000

// Function to calculate the mask for DR7 register at index i
uint64_t DBREG_DR7_MASK(int i);

// Function to set the value for DR7 register at index i
uint64_t DBREG_DR7_SET(int i, uint64_t len, uint64_t access, uint64_t enable);

// Function to check if DR7 register at index i is enabled
int DBREG_DR7_ENABLED(uint64_t d, int i);

// Function to get the access mode for DR7 register at index i
uint64_t DBREG_DR7_ACCESS(uint64_t d, int i);

// Function to get the length for DR7 register at index i
uint64_t DBREG_DR7_LEN(uint64_t d, int i);

// Function to reference dr0 - dr7 by register number
uint64_t DBREG_DRX(uint64_t *d, int x);

#define DEBUG_PORT 755

extern int g_debugging;
extern struct server_client *curdbgcli;
extern struct debug_context *curdbgctx;

int debug_attach_handle(int fd, struct cmd_packet *packet);
int debug_detach_handle(int fd, struct cmd_packet *packet);
int debug_breakpt_handle(int fd, struct cmd_packet *packet);
int debug_watchpt_handle(int fd, struct cmd_packet *packet);
int debug_threads_handle(int fd, struct cmd_packet *packet);
int debug_stopthr_handle(int fd, struct cmd_packet *packet);
int debug_resumethr_handle(int fd, struct cmd_packet *packet);
int debug_getregs_handle(int fd, struct cmd_packet *packet);
int debug_setregs_handle(int fd, struct cmd_packet *packet);
int debug_getfpregs_handle(int fd, struct cmd_packet *packet);
int debug_setfpregs_handle(int fd, struct cmd_packet *packet);
int debug_getdbregs_handle(int fd, struct cmd_packet *packet);
int debug_setdbregs_handle(int fd, struct cmd_packet *packet);
int debug_stopgo_handle(int fd, struct cmd_packet *packet);
int debug_thrinfo_handle(int fd, struct cmd_packet *packet);
int debug_singlestep_handle(int fd, struct cmd_packet *packet);

int connect_debugger(struct debug_context *dbgctx, struct sockaddr_in *client);
void debug_cleanup(struct debug_context *dbgctx);

int debug_handle(int fd, struct cmd_packet *packet);

#endif
