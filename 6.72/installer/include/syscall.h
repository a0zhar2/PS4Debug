//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#pragma once
#ifndef _SYSCALL_H
#define _SYSCALL_H

#define	SYSCALL(name, number)	       \
    __asm__(".intel_syntax noprefix"); \
    __asm__(".globl " #name "");       \
    __asm__("" #name ":");             \
    __asm__("movq rax, " #number "");  \
    __asm__("jmp syscall_macro");      \

unsigned long syscall(unsigned long n, ...);

#endif
