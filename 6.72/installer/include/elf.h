//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

// ELF definitions taken from llvm
#pragma once
#ifndef _ELF_H
#define _ELF_H

#include "../../kernSDK/include/ksdk.h"
#include "./elf_defs.h"
#define ELF32_R_SYM(i)	((i)>>8)
#define ELF32_R_TYPE(i)   ((unsigned char)(i))
#define ELF32_R_INFO(s,t) (((s)<<8)+(unsigned char)(t))

#define ELF64_R_SYM(i)    ((i)>>32)
#define ELF64_R_TYPE(i)   ((i)&0xffffffffL)
#define ELF64_R_INFO(s,t) (((s)<<32)+((t)&0xffffffffL))

typedef uint32_t Elf32_Addr; // Program address
typedef uint32_t Elf32_Off;  // File offset
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Word;
typedef int32_t  Elf32_Sword;

typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;
typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef int32_t  Elf64_Sword;
typedef uint64_t Elf64_Xword;
typedef int64_t  Elf64_Sxword;

// Object file magic string.
static const char ElfMagic[] = { 0x7f, 'E', 'L', 'F', '\0' };

struct Elf32_Ehdr {
    unsigned char e_ident[EI_NIDENT]; // ELF Identification bytes
    Elf32_Half    e_type;      // Type of file (see ET_* below)
    Elf32_Half    e_machine;   // Required architecture for this file (see EM_*)
    Elf32_Word    e_version;   // Must be equal to 1
    Elf32_Addr    e_entry;     // Address to jump to in order to start program
    Elf32_Off     e_phoff;     // Program header table's file offset, in bytes
    Elf32_Off     e_shoff;     // Section header table's file offset, in bytes
    Elf32_Word    e_flags;     // Processor-specific flags
    Elf32_Half    e_ehsize;    // Size of ELF header, in bytes
    Elf32_Half    e_phentsize; // Size of an entry in the program header table
    Elf32_Half    e_phnum;     // Number of entries in the program header table
    Elf32_Half    e_shentsize; // Size of an entry in the section header table
    Elf32_Half    e_shnum;     // Number of entries in the section header table
    Elf32_Half    e_shstrndx;  // Sect hdr table index of sect name string table
};

// 64-bit ELF header. Fields are the same as for ELF32, but with different
// types (see above).
struct Elf64_Ehdr {
    unsigned char e_ident[EI_NIDENT];
    Elf64_Half    e_type;
    Elf64_Half    e_machine;
    Elf64_Word    e_version;
    Elf64_Addr    e_entry;
    Elf64_Off     e_phoff;
    Elf64_Off     e_shoff;
    Elf64_Word    e_flags;
    Elf64_Half    e_ehsize;
    Elf64_Half    e_phentsize;
    Elf64_Half    e_phnum;
    Elf64_Half    e_shentsize;
    Elf64_Half    e_shnum;
    Elf64_Half    e_shstrndx;
};

// Section header.
struct Elf32_Shdr {
    Elf32_Word sh_name;      // Section name (index into string table)
    Elf32_Word sh_type;      // Section type (SHT_*)
    Elf32_Word sh_flags;     // Section flags (SHF_*)
    Elf32_Addr sh_addr;      // Address where section is to be loaded
    Elf32_Off  sh_offset;    // File offset of section data, in bytes
    Elf32_Word sh_size;      // Size of section, in bytes
    Elf32_Word sh_link;      // Section type-specific header table index link
    Elf32_Word sh_info;      // Section type-specific extra information
    Elf32_Word sh_addralign; // Section address alignment
    Elf32_Word sh_entsize;   // Size of records contained within the section
};

// Section header for ELF64 - same fields as ELF32, different types.
struct Elf64_Shdr {
    Elf64_Word  sh_name;
    Elf64_Word  sh_type;
    Elf64_Xword sh_flags;
    Elf64_Addr  sh_addr;
    Elf64_Off   sh_offset;
    Elf64_Xword sh_size;
    Elf64_Word  sh_link;
    Elf64_Word  sh_info;
    Elf64_Xword sh_addralign;
    Elf64_Xword sh_entsize;
};

// Symbol table entries for ELF32.
struct Elf32_Sym {
    Elf32_Word    st_name;  // Symbol name (index into string table)
    Elf32_Addr    st_value; // Value or address associated with the symbol
    Elf32_Word    st_size;  // Size of the symbol
    unsigned char st_info;  // Symbol's type and binding attributes
    unsigned char st_other; // Must be zero; reserved
    Elf32_Half    st_shndx; // Which section (header table index) it's defined in
};

// Symbol table entries for ELF64.
struct Elf64_Sym {
    Elf64_Word      st_name;  // Symbol name (index into string table)
    unsigned char   st_info;  // Symbol's type and binding attributes
    unsigned char   st_other; // Must be zero; reserved
    Elf64_Half      st_shndx; // Which section (header tbl index) it's defined in
    Elf64_Addr      st_value; // Value or address associated with the symbol
    Elf64_Xword     st_size;  // Size of the symbol
};

// Relocation entry, without explicit addend.
struct Elf32_Rel {
    Elf32_Addr r_offset; // Location (file byte offset, or program virtual addr)
    Elf32_Word r_info;   // Symbol table index and type of relocation to apply
};

// Relocation entry with explicit addend.
struct Elf32_Rela {
    Elf32_Addr  r_offset; // Location (file byte offset, or program virtual addr)
    Elf32_Word  r_info;   // Symbol table index and type of relocation to apply
    Elf32_Sword r_addend; // Compute value for relocatable field by adding this
};

// Relocation entry, without explicit addend.
struct Elf64_Rel {
    Elf64_Addr r_offset; // Location (file byte offset, or program virtual addr).
    Elf64_Xword r_info;   // Symbol table index and type of relocation to apply.
};

// Relocation entry with explicit addend.
struct Elf64_Rela {
    Elf64_Addr  r_offset; // Location (file byte offset, or program virtual addr).
    Elf64_Xword  r_info;   // Symbol table index and type of relocation to apply.
    Elf64_Sxword r_addend; // Compute value for relocatable field by adding this.
};

// Program header for ELF32.
struct Elf32_Phdr {
    Elf32_Word p_type;   // Type of segment
    Elf32_Off  p_offset; // File offset where segment is located, in bytes
    Elf32_Addr p_vaddr;  // Virtual address of beginning of segment
    Elf32_Addr p_paddr;  // Physical address of beginning of segment (OS-specific)
    Elf32_Word p_filesz; // Num. of bytes in file image of segment (may be zero)
    Elf32_Word p_memsz;  // Num. of bytes in mem image of segment (may be zero)
    Elf32_Word p_flags;  // Segment flags
    Elf32_Word p_align;  // Segment alignment constraint
};

// Program header for ELF64.
struct Elf64_Phdr {
    Elf64_Word   p_type;   // Type of segment
    Elf64_Word   p_flags;  // Segment flags
    Elf64_Off    p_offset; // File offset where segment is located, in bytes
    Elf64_Addr   p_vaddr;  // Virtual address of beginning of segment
    Elf64_Addr   p_paddr;  // Physical addr of beginning of segment (OS-specific)
    Elf64_Xword  p_filesz; // Num. of bytes in file image of segment (may be zero)
    Elf64_Xword  p_memsz;  // Num. of bytes in mem image of segment (may be zero)
    Elf64_Xword  p_align;  // Segment alignment constraint
};

// Dynamic table entry for ELF32.
struct Elf32_Dyn {
    Elf32_Sword d_tag;            // Type of dynamic table entry.
    union {
        Elf32_Word d_val;         // Integer value of entry.
        Elf32_Addr d_ptr;         // Pointer value of entry.
    } d_un;
};

// Dynamic table entry for ELF64.
struct Elf64_Dyn {
    Elf64_Sxword d_tag;           // Type of dynamic table entry.
    union {
        Elf64_Xword d_val;        // Integer value of entry.
        Elf64_Addr  d_ptr;        // Pointer value of entry.
    } d_un;
};

// error codes
#define LDR_SUCCESS			0
#define LDR_INVALID_ELF		1
#define LDR_SIZE_ERROR		2
#define LDR_MAP_ERROR		3
#define LDR_RELOC_ERROR		4


struct Elf64_Phdr *elf_pheader(struct Elf64_Ehdr *hdr);
struct Elf64_Phdr *elf_segment(struct Elf64_Ehdr *hdr, int idx);
struct Elf64_Shdr *elf_sheader(struct Elf64_Ehdr *hdr);
struct Elf64_Shdr *elf_section(struct Elf64_Ehdr *hdr, int idx);


// functions
// elf - data where elf is stored
// size - size of elf
// exec - memory allocated RWX
// msize - size of the allocated memory
int load_elf(void *elf, uint64_t size, void *exec, uint64_t msize, void **entry);
int elf_mapped_size(void *elf, uint64_t *msize);

#endif
