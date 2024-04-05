//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Maintained by Me (A0ZHAR)
//---------------------------------------------------------
// 
// This header contains ELF definitions taken from llvm
#pragma once
#ifndef _ELF_DEFS_H
#define _ELF_DEFS_H

//
// e_ident size and indices.
//
#define EI_MAG0       0   // File identification index.
#define EI_MAG1       1   // File identification index.
#define EI_MAG2       2   // File identification index.
#define EI_MAG3       3   // File identification index.
#define EI_CLASS      4   // File class.
#define EI_DATA       5   // Data encoding.
#define EI_VERSION    6   // File version.
#define EI_OSABI      7   // OS/ABI identification.
#define EI_ABIVERSION 8   // ABI version.
#define EI_PAD        9   // Start of padding bytes.
#define EI_NIDENT     16  // Number of bytes in e_ident.

// File types
#define ET_NONE  0       // No file type
#define ET_REL  1       // Relocatable file
#define ET_EXEC  2       // Executable file
#define ET_DYN  3       // Shared object file
#define ET_CORE  4       // Core file
#define ET_LOPROC  0xff00  // Beginning of processor-specific codes
#define ET_HIPROC  0xffff  // Processor-specific

// Versioning
#define EV_NONE  0 
#define EV_CURRENT  1


// Machine architectures
#define EM_NONE  0  // No machine
#define EM_M32  1  // AT&T WE 32100
#define EM_SPARC  2  // SPARC
#define EM_386  3  // Intel 386
#define EM_68K  4  // Motorola 68000
#define EM_88K  5  // Motorola 88000
#define EM_486  6  // Intel 486 (deprecated)
#define EM_860  7  // Intel 80860
#define EM_MIPS  8  // MIPS R3000
#define EM_S370  9  // IBM System/370
#define EM_MIPS_RS3_LE  10  // MIPS RS3000 Little-endian
#define EM_PARISC  15  // Hewlett-Packard PA-RISC
#define EM_VPP500  17  // Fujitsu VPP500
#define EM_SPARC32PLUS  18  // Enhanced instruction set SPARC
#define EM_960  19  // Intel 80960
#define EM_PPC  20  // PowerPC
#define EM_PPC64  21  // PowerPC64
#define EM_S390  22  // IBM System/390
#define EM_SPU  23  // IBM SPU/SPC
#define EM_V800  36  // NEC V800
#define EM_FR20  37  // Fujitsu FR20
#define EM_RH32  38  // TRW RH-32
#define EM_RCE  39  // Motorola RCE
#define EM_ARM  40  // ARM
#define EM_ALPHA  41  // DEC Alpha
#define EM_SH  42  // Hitachi SH
#define EM_SPARCV9  43  // SPARC V9
#define EM_TRICORE  44  // Siemens TriCore
#define EM_ARC  45  // Argonaut RISC Core
#define EM_H8_300  46  // Hitachi H8/300
#define EM_H8_300H  47  // Hitachi H8/300H
#define EM_H8S  48  // Hitachi H8S
#define EM_H8_500  49  // Hitachi H8/500
#define EM_IA_64  50  // Intel IA-64 processor architecture
#define EM_MIPS_X  51  // Stanford MIPS-X
#define EM_COLDFIRE  52  // Motorola ColdFire
#define EM_68HC12  53  // Motorola M68HC12
#define EM_MMA  54  // Fujitsu MMA Multimedia Accelerator
#define EM_PCP  55  // Siemens PCP
#define EM_NCPU  56  // Sony nCPU embedded RISC processor
#define EM_NDR1  57  // Denso NDR1 microprocessor
#define EM_STARCORE  58  // Motorola Star*Core processor
#define EM_ME16  59  // Toyota ME16 processor
#define EM_ST100  60  // STMicroelectronics ST100 processor
#define EM_TINYJ  61  // Advanced Logic Corp. TinyJ embedded processor family
#define EM_X86_64  62  // AMD x86-64 architecture
#define EM_PDSP  63  // Sony DSP Processor
#define EM_PDP10  64  // Digital Equipment Corp. PDP-10
#define EM_PDP11  65  // Digital Equipment Corp. PDP-11
#define EM_FX66  66  // Siemens FX66 microcontroller
#define EM_ST9PLUS  67  // STMicroelectronics ST9+ 8/16 bit microcontroller
#define EM_ST7  68  // STMicroelectronics ST7 8-bit microcontroller
#define EM_68HC16  69  // Motorola MC68HC16 Microcontroller
#define EM_68HC11  70  // Motorola MC68HC11 Microcontroller
#define EM_68HC08  71  // Motorola MC68HC08 Microcontroller
#define EM_68HC05  72  // Motorola MC68HC05 Microcontroller
#define EM_SVX  73  // Silicon Graphics SVx
#define EM_ST19  74  // STMicroelectronics ST19 8-bit microcontroller
#define EM_VAX  75  // Digital VAX
#define EM_CRIS  76  // Axis Communications 32-bit embedded processor
#define EM_JAVELIN  77  // Infineon Technologies 32-bit embedded processor
#define EM_FIREPATH  78  // Element 14 64-bit DSP Processor
#define EM_ZSP  79  // LSI Logic 16-bit DSP Processor
#define EM_MMIX  80  // Donald Knuth's educational 64-bit processor
#define EM_HUANY  81  // Harvard University machine-independent object files
#define EM_PRISM  82  // SiTera Prism
#define EM_AVR  83  // Atmel AVR 8-bit microcontroller
#define EM_FR30  84  // Fujitsu FR30
#define EM_D10V  85  // Mitsubishi D10V
#define EM_D30V  86  // Mitsubishi D30V
#define EM_V850  87  // NEC v850
#define EM_M32R  88  // Mitsubishi M32R
#define EM_MN10300  89  // Matsushita MN10300
#define EM_MN10200  90  // Matsushita MN10200
#define EM_PJ  91  // picoJava
#define EM_OPENRISC  92  // OpenRISC 32-bit embedded processor
#define EM_ARC_COMPACT  93  // ARC International ARCompact processor (old spelling/synonym: EM_ARC_A5)
#define EM_XTENSA  94  // Tensilica Xtensa Architecture
#define EM_VIDEOCORE  95  // Alphamosaic VideoCore processor
#define EM_TMM_GPP  96  // Thompson Multimedia General Purpose Processor
#define EM_NS32K  97  // National Semiconductor 32000 series
#define EM_TPC  98  // Tenor Network TPC processor
#define EM_SNP1K  99  // Trebia SNP 1000 processor
#define EM_ST200  100  // STMicroelectronics (www.st.com) ST200
#define EM_IP2K  101  // Ubicom IP2xxx microcontroller family
#define EM_MAX  102  // MAX Processor
#define EM_CR  103  // National Semiconductor CompactRISC microprocessor
#define EM_F2MC16  104  // Fujitsu F2MC16
#define EM_MSP430  105  // Texas Instruments embedded microcontroller msp430
#define EM_BLACKFIN  106  // Analog Devices Blackfin (DSP) processor
#define EM_SE_C33  107  // S1C33 Family of Seiko Epson processors
#define EM_SEP  108  // Sharp embedded microprocessor
#define EM_ARCA  109  // Arca RISC Microprocessor
#define EM_UNICORE  110  // Microprocessor series from PKU-Unity Ltd. and MPRC of Peking University
#define EM_EXCESS  111  // eXcess: 16/32/64-bit configurable embedded CPU
#define EM_DXP  112  // Icera Semiconductor Inc. Deep Execution Processor
#define EM_ALTERA_NIOS2  113  // Altera Nios II soft-core processor
#define EM_CRX  114  // National Semiconductor CompactRISC CRX
#define EM_XGATE  115  // Motorola XGATE embedded processor
#define EM_C166  116  // Infineon C16x/XC16x processor
#define EM_M16C  117  // Renesas M16C series microprocessors
#define EM_DSPIC30F  118  // Microchip Technology dsPIC30F Digital SignalController
#define EM_CE  119  // Freescale Communication Engine RISC core
#define EM_M32C  120  // Renesas M32C series microprocessors
#define EM_TSK3000  131  // Altium TSK3000 core
#define EM_RS08  132  // Freescale RS08 embedded processor
#define EM_SHARC  133  // Analog Devices SHARC family of 32-bit DSPprocessors
#define EM_ECOG2  134  // Cyan Technology eCOG2 microprocessor
#define EM_SCORE7  135  // Sunplus S+core7 RISC processor
#define EM_DSP24  136  // New Japan Radio (NJR) 24-bit DSP Processor
#define EM_VIDEOCORE3  137  // Broadcom VideoCore III processor
#define EM_LATTICEMICO32  138  // RISC processor for Lattice FPGA architecture
#define EM_SE_C17  139  // Seiko Epson C17 family
#define EM_TI_C6000  140  // The Texas Instruments TMS320C6000 DSP family
#define EM_TI_C2000  141  // The Texas Instruments TMS320C2000 DSP family
#define EM_TI_C5500  142  // The Texas Instruments TMS320C55x DSP family
#define EM_MMDSP_PLUS  160  // STMicroelectronics 64bit VLIW Data Signal Processor
#define EM_CYPRESS_M8C  161  // Cypress M8C microprocessor
#define EM_R32C  162  // Renesas R32C series microprocessors
#define EM_TRIMEDIA  163  // NXP Semiconductors TriMedia architecture family
#define EM_HEXAGON  164  // Qualcomm Hexagon processor
#define EM_8051  165  // Intel 8051 and variants
#define EM_STXP7X  166  // STMicroelectronics STxP7x family of configurable and extensible RISC processors
#define EM_NDS32  167  // Andes Technology compact code size embedded RISC processor family
#define EM_ECOG1  168  // Cyan Technology eCOG1X family
#define EM_ECOG1X  168  // Cyan Technology eCOG1X family
#define EM_MAXQ30  169  // Dallas Semiconductor MAXQ30 Core Micro-controllers
#define EM_XIMO16  170  // New Japan Radio (NJR) 16-bit DSP Processor
#define EM_MANIK  171  // M2000 Reconfigurable RISC Microprocessor
#define EM_CRAYNV2  172  // Cray Inc. NV2 vector architecture
#define EM_RX  173  // Renesas RX family
#define EM_METAG  174  // Imagination Technologies META processor architecture
#define EM_MCST_ELBRUS  175  // MCST Elbrus general purpose hardware architecture
#define EM_ECOG16  176  // Cyan Technology eCOG16 family
#define EM_CR16  177  // National Semiconductor CompactRISC CR16 16-bit microprocessor
#define EM_ETPU  178  // Freescale Extended Time Processing Unit
#define EM_SLE9X  179  // Infineon Technologies SLE9X core
#define EM_L10M  180  // Intel L10M
#define EM_K10M  181  // Intel K10M
#define EM_AARCH64  183  // ARM AArch64
#define EM_AVR32  185  // Atmel Corporation 32-bit microprocessor family
#define EM_STM8  186  // STMicroeletronics STM8 8-bit microcontroller
#define EM_TILE64  187  // Tilera TILE64 multicore architecture family
#define EM_TILEPRO  188  // Tilera TILEPro multicore architecture family
#define EM_MICROBLAZE  189  // Xilinx MicroBlaze 32-bit RISC soft processor core
#define EM_CUDA  190  // NVIDIA CUDA architecture
#define EM_TILEGX  191  // Tilera TILE-Gx multicore architecture family
#define EM_CLOUDSHIELD  192  // CloudShield architecture family
#define EM_COREA_1ST  193  // KIPO-KAIST Core-A 1st generation processor family
#define EM_COREA_2ND  194  // KIPO-KAIST Core-A 2nd generation processor family
#define EM_ARC_COMPACT2  195  // Synopsys ARCompact V2
#define EM_OPEN8  196  // Open8 8-bit RISC soft processor core
#define EM_RL78  197  // Renesas RL78 family
#define EM_VIDEOCORE5  198  // Broadcom VideoCore V processor
#define EM_78KOR  199  // Renesas 78KOR family
#define EM_56800EX  200  // Freescale 56800EX Digital Signal Controller (DSC)
#define EM_MBLAZE  47787 // Xilinx MicroBlaze


// Object file classes.

#define ELFCLASSNONE  0 
#define ELFCLASS32  1  // 32-bit object file
#define ELFCLASS64  2  // 64-bit object file


// Object file byte orderings.

#define ELFDATANONE  0  // Invalid data encoding.
#define ELFDATA2LSB  1  // Little-endian object file
#define ELFDATA2MSB  2  // Big-endian object file


// OS ABI identification.

#define ELFOSABI_NONE  0           // UNIX System V ABI
#define ELFOSABI_HPUX  1           // HP-UX operating system
#define ELFOSABI_NETBSD  2         // NetBSD
#define ELFOSABI_LINUX  3          // GNU/Linux
#define ELFOSABI_HURD  4           // GNU/Hurd
#define ELFOSABI_SOLARIS  6        // Solaris
#define ELFOSABI_AIX  7            // AIX
#define ELFOSABI_IRIX  8           // IRIX
#define ELFOSABI_FREEBSD  9        // FreeBSD
#define ELFOSABI_TRU64  10         // TRU64 UNIX
#define ELFOSABI_MODESTO  11       // Novell Modesto
#define ELFOSABI_OPENBSD  12       // OpenBSD
#define ELFOSABI_OPENVMS  13       // OpenVMS
#define ELFOSABI_NSK  14           // Hewlett-Packard Non-Stop Kernel
#define ELFOSABI_AROS  15          // AROS
#define ELFOSABI_FENIXOS  16       // FenixOS
#define ELFOSABI_C6000_ELFABI  64  // Bare-metal TMS320C6000
#define ELFOSABI_C6000_LINUX  65   // Linux TMS320C6000
#define ELFOSABI_ARM  97           // ARM
#define ELFOSABI_STANDALONE  255   // Standalone (embedded) application


// X86_64 relocations.

#define R_X86_64_NONE  0 
#define R_X86_64_64  1 
#define R_X86_64_PC32  2 
#define R_X86_64_GOT32  3 
#define R_X86_64_PLT32  4 
#define R_X86_64_COPY  5 
#define R_X86_64_GLOB_DAT  6 
#define R_X86_64_JUMP_SLOT  7 
#define R_X86_64_RELATIVE  8 
#define R_X86_64_GOTPCREL  9 
#define R_X86_64_32  10 
#define R_X86_64_32S  11 
#define R_X86_64_16  12 
#define R_X86_64_PC16  13 
#define R_X86_64_8  14 
#define R_X86_64_PC8  15 
#define R_X86_64_DTPMOD64  16 
#define R_X86_64_DTPOFF64  17 
#define R_X86_64_TPOFF64  18 
#define R_X86_64_TLSGD  19 
#define R_X86_64_TLSLD  20 
#define R_X86_64_DTPOFF32  21 
#define R_X86_64_GOTTPOFF  22 
#define R_X86_64_TPOFF32  23 
#define R_X86_64_PC64  24 
#define R_X86_64_GOTOFF64  25 
#define R_X86_64_GOTPC32  26 
#define R_X86_64_GOT64  27 
#define R_X86_64_GOTPCREL64  28 
#define R_X86_64_GOTPC64  29 
#define R_X86_64_GOTPLT64  30 
#define R_X86_64_PLTOFF64  31 
#define R_X86_64_SIZE32  32 
#define R_X86_64_SIZE64  33 
#define R_X86_64_GOTPC32_TLSDESC  34 
#define R_X86_64_TLSDESC_CALL  35 
#define R_X86_64_TLSDESC  36 
#define R_X86_64_IRELATIVE  37


// i386 relocations.

#define R_386_NONE  0 
#define R_386_32  1 
#define R_386_PC32  2 
#define R_386_GOT32  3 
#define R_386_PLT32  4 
#define R_386_COPY  5 
#define R_386_GLOB_DAT  6 
#define R_386_JUMP_SLOT  7 
#define R_386_RELATIVE  8 
#define R_386_GOTOFF  9 
#define R_386_GOTPC  10 
#define R_386_32PLT  11 
#define R_386_TLS_TPOFF  14 
#define R_386_TLS_IE  15 
#define R_386_TLS_GOTIE  16 
#define R_386_TLS_LE  17 
#define R_386_TLS_GD  18 
#define R_386_TLS_LDM  19 
#define R_386_16  20 
#define R_386_PC16  21 
#define R_386_8  22 
#define R_386_PC8  23 
#define R_386_TLS_GD_32  24 
#define R_386_TLS_GD_PUSH  25 
#define R_386_TLS_GD_CALL  26 
#define R_386_TLS_GD_POP  27 
#define R_386_TLS_LDM_32  28 
#define R_386_TLS_LDM_PUSH  29 
#define R_386_TLS_LDM_CALL  30 
#define R_386_TLS_LDM_POP  31 
#define R_386_TLS_LDO_32  32 
#define R_386_TLS_IE_32  33 
#define R_386_TLS_LE_32  34 
#define R_386_TLS_DTPMOD32  35 
#define R_386_TLS_DTPOFF32  36 
#define R_386_TLS_TPOFF32  37 
#define R_386_TLS_GOTDESC  39 
#define R_386_TLS_DESC_CALL  40 
#define R_386_TLS_DESC  41 
#define R_386_IRELATIVE  42 
#define R_386_NUM  43


// MBlaze relocations.

#define R_MICROBLAZE_NONE  0 
#define R_MICROBLAZE_32  1 
#define R_MICROBLAZE_32_PCREL  2 
#define R_MICROBLAZE_64_PCREL  3 
#define R_MICROBLAZE_32_PCREL_LO  4 
#define R_MICROBLAZE_64  5 
#define R_MICROBLAZE_32_LO  6 
#define R_MICROBLAZE_SRO32  7 
#define R_MICROBLAZE_SRW32  8 
#define R_MICROBLAZE_64_NONE  9 
#define R_MICROBLAZE_32_SYM_OP_SYM  10 
#define R_MICROBLAZE_GNU_VTINHERIT  11 
#define R_MICROBLAZE_GNU_VTENTRY  12 
#define R_MICROBLAZE_GOTPC_64  13 
#define R_MICROBLAZE_GOT_64  14 
#define R_MICROBLAZE_PLT_64  15 
#define R_MICROBLAZE_REL  16 
#define R_MICROBLAZE_JUMP_SLOT  17 
#define R_MICROBLAZE_GLOB_DAT  18 
#define R_MICROBLAZE_GOTOFF_64  19 
#define R_MICROBLAZE_GOTOFF_32  20 
#define R_MICROBLAZE_COPY  21


// ELF Relocation types for PPC32

#define R_PPC_NONE  0       /* No relocation. */
#define R_PPC_ADDR32  1 
#define R_PPC_ADDR24  2 
#define R_PPC_ADDR16  3 
#define R_PPC_ADDR16_LO  4 
#define R_PPC_ADDR16_HI  5 
#define R_PPC_ADDR16_HA  6 
#define R_PPC_ADDR14  7 
#define R_PPC_ADDR14_BRTAKEN  8 
#define R_PPC_ADDR14_BRNTAKEN  9 
#define R_PPC_REL24  10 
#define R_PPC_REL14  11 
#define R_PPC_REL14_BRTAKEN  12 
#define R_PPC_REL14_BRNTAKEN  13 
#define R_PPC_REL32  26 
#define R_PPC_TPREL16_LO  70 
#define R_PPC_TPREL16_HA  72


// ELF Relocation types for PPC64

#define  R_PPC64_NONE  0 
#define  R_PPC64_ADDR32  1 
#define  R_PPC64_ADDR16_LO  4 
#define  R_PPC64_ADDR16_HI  5 
#define  R_PPC64_ADDR14  7 
#define  R_PPC64_REL24  10 
#define  R_PPC64_REL32  26 
#define  R_PPC64_ADDR64  38 
#define  R_PPC64_ADDR16_HIGHER  39 
#define  R_PPC64_ADDR16_HIGHEST  41 
#define  R_PPC64_REL64  44 
#define  R_PPC64_TOC16  47 
#define  R_PPC64_TOC16_LO  48 
#define  R_PPC64_TOC16_HA  50 
#define  R_PPC64_TOC  51 
#define  R_PPC64_ADDR16_DS  56 
#define  R_PPC64_ADDR16_LO_DS  57 
#define  R_PPC64_TOC16_DS  63 
#define  R_PPC64_TOC16_LO_DS  64 
#define  R_PPC64_TLS  67 
#define  R_PPC64_TPREL16_LO  70 
#define  R_PPC64_TPREL16_HA  72 
#define  R_PPC64_DTPREL16_LO  75 
#define  R_PPC64_DTPREL16_HA  77 
#define  R_PPC64_GOT_TLSGD16_LO  80 
#define  R_PPC64_GOT_TLSGD16_HA  82 
#define  R_PPC64_GOT_TLSLD16_LO  84 
#define  R_PPC64_GOT_TLSLD16_HA  86 
#define  R_PPC64_GOT_TPREL16_LO_DS  88 
#define  R_PPC64_GOT_TPREL16_HA  90 
#define  R_PPC64_TLSGD  107 
#define  R_PPC64_TLSLD  108


// ELF Relocation types for AArch64


#define R_AARCH64_NONE  0x100 

#define R_AARCH64_ABS64  0x101 
#define R_AARCH64_ABS32  0x102 
#define R_AARCH64_ABS16  0x103 
#define R_AARCH64_PREL64  0x104 
#define R_AARCH64_PREL32  0x105 
#define R_AARCH64_PREL16  0x106 

#define R_AARCH64_MOVW_UABS_G0  0x107 
#define R_AARCH64_MOVW_UABS_G0_NC  0x108 
#define R_AARCH64_MOVW_UABS_G1  0x109 
#define R_AARCH64_MOVW_UABS_G1_NC  0x10a 
#define R_AARCH64_MOVW_UABS_G2  0x10b 
#define R_AARCH64_MOVW_UABS_G2_NC  0x10c 
#define R_AARCH64_MOVW_UABS_G3  0x10d 
#define R_AARCH64_MOVW_SABS_G0  0x10e 
#define R_AARCH64_MOVW_SABS_G1  0x10f 
#define R_AARCH64_MOVW_SABS_G2  0x110 

#define R_AARCH64_LD_PREL_LO19  0x111 
#define R_AARCH64_ADR_PREL_LO21  0x112 
#define R_AARCH64_ADR_PREL_PG_HI21  0x113 
#define R_AARCH64_ADD_ABS_LO12_NC  0x115 
#define R_AARCH64_LDST8_ABS_LO12_NC  0x116 

#define R_AARCH64_TSTBR14  0x117 
#define R_AARCH64_CONDBR19  0x118 
#define R_AARCH64_JUMP26  0x11a 
#define R_AARCH64_CALL26  0x11b 

#define R_AARCH64_LDST16_ABS_LO12_NC  0x11c 
#define R_AARCH64_LDST32_ABS_LO12_NC  0x11d 
#define R_AARCH64_LDST64_ABS_LO12_NC  0x11e 

#define R_AARCH64_LDST128_ABS_LO12_NC  0x12b 

#define R_AARCH64_ADR_GOT_PAGE  0x137 
#define R_AARCH64_LD64_GOT_LO12_NC  0x138 

#define R_AARCH64_TLSLD_MOVW_DTPREL_G2  0x20b 
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1  0x20c 
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC  0x20d 
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0  0x20e 
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC  0x20f 
#define R_AARCH64_TLSLD_ADD_DTPREL_HI12  0x210 
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12  0x211 
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC  0x212 
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12  0x213 
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC  0x214 
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12  0x215 
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC  0x216 
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12  0x217 
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC  0x218 
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12  0x219 
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC  0x21a 

#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G1  0x21b 
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC  0x21c 
#define R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21  0x21d 
#define R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC  0x21e 
#define R_AARCH64_TLSIE_LD_GOTTPREL_PREL19  0x21f 

#define R_AARCH64_TLSLE_MOVW_TPREL_G2  0x220 
#define R_AARCH64_TLSLE_MOVW_TPREL_G1  0x221 
#define R_AARCH64_TLSLE_MOVW_TPREL_G1_NC  0x222 
#define R_AARCH64_TLSLE_MOVW_TPREL_G0  0x223 
#define R_AARCH64_TLSLE_MOVW_TPREL_G0_NC  0x224 
#define R_AARCH64_TLSLE_ADD_TPREL_HI12  0x225 
#define R_AARCH64_TLSLE_ADD_TPREL_LO12  0x226 
#define R_AARCH64_TLSLE_ADD_TPREL_LO12_NC  0x227 
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12  0x228 
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC  0x229 
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12  0x22a 
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC  0x22b 
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12  0x22c 
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC  0x22d 
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12  0x22e 
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC  0x22f 

#define R_AARCH64_TLSDESC_ADR_PAGE  0x232 
#define R_AARCH64_TLSDESC_LD64_LO12_NC  0x233 
#define R_AARCH64_TLSDESC_ADD_LO12_NC  0x234 

#define R_AARCH64_TLSDESC_CALL  0x239


// ARM Specific e_flags

#define EF_ARM_SOFT_FLOAT  0x00000200U 
#define EF_ARM_VFP_FLOAT  0x00000400U 
#define EF_ARM_EABI_UNKNOWN  0x00000000U 
#define EF_ARM_EABI_VER1  0x01000000U 
#define EF_ARM_EABI_VER2  0x02000000U 
#define EF_ARM_EABI_VER3  0x03000000U 
#define EF_ARM_EABI_VER4  0x04000000U 
#define EF_ARM_EABI_VER5  0x05000000U 
#define EF_ARM_EABIMASK  0xFF000000U


// ELF Relocation types for ARM
// Meets 2.08 ABI Specs.


#define R_ARM_NONE  0x00 
#define R_ARM_PC24  0x01 
#define R_ARM_ABS32  0x02 
#define R_ARM_REL32  0x03 
#define R_ARM_LDR_PC_G0  0x04 
#define R_ARM_ABS16  0x05 
#define R_ARM_ABS12  0x06 
#define R_ARM_THM_ABS5  0x07 
#define R_ARM_ABS8  0x08 
#define R_ARM_SBREL32  0x09 
#define R_ARM_THM_CALL  0x0a 
#define R_ARM_THM_PC8  0x0b 
#define R_ARM_BREL_ADJ  0x0c 
#define R_ARM_TLS_DESC  0x0d 
#define R_ARM_THM_SWI8  0x0e 
#define R_ARM_XPC25  0x0f 
#define R_ARM_THM_XPC22  0x10 
#define R_ARM_TLS_DTPMOD32  0x11 
#define R_ARM_TLS_DTPOFF32  0x12 
#define R_ARM_TLS_TPOFF32  0x13 
#define R_ARM_COPY  0x14 
#define R_ARM_GLOB_DAT  0x15 
#define R_ARM_JUMP_SLOT  0x16 
#define R_ARM_RELATIVE  0x17 
#define R_ARM_GOTOFF32  0x18 
#define R_ARM_BASE_PREL  0x19 
#define R_ARM_GOT_BREL  0x1a 
#define R_ARM_PLT32  0x1b 
#define R_ARM_CALL  0x1c 
#define R_ARM_JUMP24  0x1d 
#define R_ARM_THM_JUMP24  0x1e 
#define R_ARM_BASE_ABS  0x1f 
#define R_ARM_ALU_PCREL_7_0  0x20 
#define R_ARM_ALU_PCREL_15_8  0x21 
#define R_ARM_ALU_PCREL_23_15  0x22 
#define R_ARM_LDR_SBREL_11_0_NC  0x23 
#define R_ARM_ALU_SBREL_19_12_NC  0x24 
#define R_ARM_ALU_SBREL_27_20_CK  0x25 
#define R_ARM_TARGET1  0x26 
#define R_ARM_SBREL31  0x27 
#define R_ARM_V4BX  0x28 
#define R_ARM_TARGET2  0x29 
#define R_ARM_PREL31  0x2a 
#define R_ARM_MOVW_ABS_NC  0x2b 
#define R_ARM_MOVT_ABS  0x2c 
#define R_ARM_MOVW_PREL_NC  0x2d 
#define R_ARM_MOVT_PREL  0x2e 
#define R_ARM_THM_MOVW_ABS_NC  0x2f 
#define R_ARM_THM_MOVT_ABS  0x30 
#define R_ARM_THM_MOVW_PREL_NC  0x31 
#define R_ARM_THM_MOVT_PREL  0x32 
#define R_ARM_THM_JUMP19  0x33 
#define R_ARM_THM_JUMP6  0x34 
#define R_ARM_THM_ALU_PREL_11_0  0x35 
#define R_ARM_THM_PC12  0x36 
#define R_ARM_ABS32_NOI  0x37 
#define R_ARM_REL32_NOI  0x38 
#define R_ARM_ALU_PC_G0_NC  0x39 
#define R_ARM_ALU_PC_G0  0x3a 
#define R_ARM_ALU_PC_G1_NC  0x3b 
#define R_ARM_ALU_PC_G1  0x3c 
#define R_ARM_ALU_PC_G2  0x3d 
#define R_ARM_LDR_PC_G1  0x3e 
#define R_ARM_LDR_PC_G2  0x3f 
#define R_ARM_LDRS_PC_G0  0x40 
#define R_ARM_LDRS_PC_G1  0x41 
#define R_ARM_LDRS_PC_G2  0x42 
#define R_ARM_LDC_PC_G0  0x43 
#define R_ARM_LDC_PC_G1  0x44 
#define R_ARM_LDC_PC_G2  0x45 
#define R_ARM_ALU_SB_G0_NC  0x46 
#define R_ARM_ALU_SB_G0  0x47 
#define R_ARM_ALU_SB_G1_NC  0x48 
#define R_ARM_ALU_SB_G1  0x49 
#define R_ARM_ALU_SB_G2  0x4a 
#define R_ARM_LDR_SB_G0  0x4b 
#define R_ARM_LDR_SB_G1  0x4c 
#define R_ARM_LDR_SB_G2  0x4d 
#define R_ARM_LDRS_SB_G0  0x4e 
#define R_ARM_LDRS_SB_G1  0x4f 
#define R_ARM_LDRS_SB_G2  0x50 
#define R_ARM_LDC_SB_G0  0x51 
#define R_ARM_LDC_SB_G1  0x52 
#define R_ARM_LDC_SB_G2  0x53 
#define R_ARM_MOVW_BREL_NC  0x54 
#define R_ARM_MOVT_BREL  0x55 
#define R_ARM_MOVW_BREL  0x56 
#define R_ARM_THM_MOVW_BREL_NC  0x57 
#define R_ARM_THM_MOVT_BREL  0x58 
#define R_ARM_THM_MOVW_BREL  0x59 
#define R_ARM_TLS_GOTDESC  0x5a 
#define R_ARM_TLS_CALL  0x5b 
#define R_ARM_TLS_DESCSEQ  0x5c 
#define R_ARM_THM_TLS_CALL  0x5d 
#define R_ARM_PLT32_ABS  0x5e 
#define R_ARM_GOT_ABS  0x5f 
#define R_ARM_GOT_PREL  0x60 
#define R_ARM_GOT_BREL12  0x61 
#define R_ARM_GOTOFF12  0x62 
#define R_ARM_GOTRELAX  0x63 
#define R_ARM_GNU_VTENTRY  0x64 
#define R_ARM_GNU_VTINHERIT  0x65 
#define R_ARM_THM_JUMP11  0x66 
#define R_ARM_THM_JUMP8  0x67 
#define R_ARM_TLS_GD32  0x68 
#define R_ARM_TLS_LDM32  0x69 
#define R_ARM_TLS_LDO32  0x6a 
#define R_ARM_TLS_IE32  0x6b 
#define R_ARM_TLS_LE32  0x6c 
#define R_ARM_TLS_LDO12  0x6d 
#define R_ARM_TLS_LE12  0x6e 
#define R_ARM_TLS_IE12GP  0x6f 
#define R_ARM_PRIVATE_0  0x70 
#define R_ARM_PRIVATE_1  0x71 
#define R_ARM_PRIVATE_2  0x72 
#define R_ARM_PRIVATE_3  0x73 
#define R_ARM_PRIVATE_4  0x74 
#define R_ARM_PRIVATE_5  0x75 
#define R_ARM_PRIVATE_6  0x76 
#define R_ARM_PRIVATE_7  0x77 
#define R_ARM_PRIVATE_8  0x78 
#define R_ARM_PRIVATE_9  0x79 
#define R_ARM_PRIVATE_10  0x7a 
#define R_ARM_PRIVATE_11  0x7b 
#define R_ARM_PRIVATE_12  0x7c 
#define R_ARM_PRIVATE_13  0x7d 
#define R_ARM_PRIVATE_14  0x7e 
#define R_ARM_PRIVATE_15  0x7f 
#define R_ARM_ME_TOO  0x80 
#define R_ARM_THM_TLS_DESCSEQ16  0x81 
#define R_ARM_THM_TLS_DESCSEQ32  0x82


// Mips Specific e_flags

#define EF_MIPS_NOREORDER  0x00000001  // Don't reorder instructions
#define EF_MIPS_PIC  0x00000002  // Position independent code
#define EF_MIPS_CPIC  0x00000004  // Call object with Position independent code
#define EF_MIPS_ABI_O32  0x00001000  // This file follows the first MIPS 32 bit ABI

//ARCH_ASE
#define EF_MIPS_MICROMIPS  0x02000000  // microMIPS
#define EF_MIPS_ARCH_ASE_M16 0x04000000  // Has Mips-16 ISA extensions
// ARCH
#define EF_MIPS_ARCH_1  0x00000000  // MIPS1 instruction set
#define EF_MIPS_ARCH_2  0x10000000  // MIPS2 instruction set
#define EF_MIPS_ARCH_3  0x20000000  // MIPS3 instruction set
#define EF_MIPS_ARCH_4  0x30000000  // MIPS4 instruction set
#define EF_MIPS_ARCH_5  0x40000000  // MIPS5 instruction set
#define EF_MIPS_ARCH_32  0x50000000  // MIPS32 instruction set per linux not elf.h
#define EF_MIPS_ARCH_64  0x60000000  // MIPS64 instruction set per linux not elf.h
#define EF_MIPS_ARCH_32R2  0x70000000  // mips32r2
#define EF_MIPS_ARCH_64R2  0x80000000  // mips64r2
#define EF_MIPS_ARCH  0xf0000000  // Mask for applying EF_MIPS_ARCH_ variant


// ELF Relocation types for Mips
// .

#define R_MIPS_NONE  0 
#define R_MIPS_16  1 
#define R_MIPS_32  2 
#define R_MIPS_REL32  3 
#define R_MIPS_26  4 
#define R_MIPS_HI16  5 
#define R_MIPS_LO16  6 
#define R_MIPS_GPREL16  7 
#define R_MIPS_LITERAL  8 
#define R_MIPS_GOT16  9 
#define R_MIPS_GOT  9 
#define R_MIPS_PC16  10 
#define R_MIPS_CALL16  11 
#define R_MIPS_GPREL32  12 
#define R_MIPS_SHIFT5  16 
#define R_MIPS_SHIFT6  17 
#define R_MIPS_64  18 
#define R_MIPS_GOT_DISP  19 
#define R_MIPS_GOT_PAGE  20 
#define R_MIPS_GOT_OFST  21 
#define R_MIPS_GOT_HI16  22 
#define R_MIPS_GOT_LO16  23 
#define R_MIPS_SUB  24 
#define R_MIPS_INSERT_A  25 
#define R_MIPS_INSERT_B  26 
#define R_MIPS_DELETE  27 
#define R_MIPS_HIGHER  28 
#define R_MIPS_HIGHEST  29 
#define R_MIPS_CALL_HI16  30 
#define R_MIPS_CALL_LO16  31 
#define R_MIPS_SCN_DISP  32 
#define R_MIPS_REL16  33 
#define R_MIPS_ADD_IMMEDIATE  34 
#define R_MIPS_PJUMP  35 
#define R_MIPS_RELGOT  36 
#define R_MIPS_JALR  37 
#define R_MIPS_TLS_DTPMOD32  38 
#define R_MIPS_TLS_DTPREL32  39 
#define R_MIPS_TLS_DTPMOD64  40 
#define R_MIPS_TLS_DTPREL64  41 
#define R_MIPS_TLS_GD  42 
#define R_MIPS_TLS_LDM  43 
#define R_MIPS_TLS_DTPREL_HI16  44 
#define R_MIPS_TLS_DTPREL_LO16  45 
#define R_MIPS_TLS_GOTTPREL  46 
#define R_MIPS_TLS_TPREL32  47 
#define R_MIPS_TLS_TPREL64  48 
#define R_MIPS_TLS_TPREL_HI16  49 
#define R_MIPS_TLS_TPREL_LO16  50 
#define R_MIPS_GLOB_DAT  51 
#define R_MIPS_COPY  126 
#define R_MIPS_JUMP_SLOT  127 
#define R_MIPS_NUM  218


// Special values for the st_other field in the symbol table entry for MIPS.

#define STO_MIPS_MICROMIPS  0x80 // MIPS Specific ISA for MicroMips


// Hexagon Specific e_flags
// Release 5 ABI

    // Object processor version flags  bits[3:0]
#define EF_HEXAGON_MACH_V2  0x00000001    // Hexagon V2
#define EF_HEXAGON_MACH_V3  0x00000002    // Hexagon V3
#define EF_HEXAGON_MACH_V4  0x00000003    // Hexagon V4
#define EF_HEXAGON_MACH_V5  0x00000004    // Hexagon V5

// Highest ISA version flags
#define EF_HEXAGON_ISA_MACH  0x00000000    // Same as specified in bits[3:0]
// of e_flags
#define EF_HEXAGON_ISA_V2  0x00000010    // Hexagon V2 ISA
#define EF_HEXAGON_ISA_V3  0x00000020    // Hexagon V3 ISA
#define EF_HEXAGON_ISA_V4  0x00000030    // Hexagon V4 ISA
#define EF_HEXAGON_ISA_V5  0x00000040    // Hexagon V5 ISA


// Hexagon specific Section indexes for common small data
// Release 5 ABI

#define SHN_HEXAGON_SCOMMON  0xff00        // Other access sizes
#define SHN_HEXAGON_SCOMMON_1  0xff01        // Byte-sized access
#define SHN_HEXAGON_SCOMMON_2  0xff02        // Half-word-sized access
#define SHN_HEXAGON_SCOMMON_4  0xff03        // Word-sized access
#define SHN_HEXAGON_SCOMMON_8  0xff04        // Double-word-size access


// ELF Relocation types for Hexagon
// Release 5 ABI
#define R_HEX_NONE  0 
#define R_HEX_B22_PCREL  1 
#define R_HEX_B15_PCREL  2 
#define R_HEX_B7_PCREL  3 
#define R_HEX_LO16  4 
#define R_HEX_HI16  5 
#define R_HEX_32  6 
#define R_HEX_16  7 
#define R_HEX_8  8 
#define R_HEX_GPREL16_0  9 
#define R_HEX_GPREL16_1  10 
#define R_HEX_GPREL16_2  11 
#define R_HEX_GPREL16_3  12 
#define R_HEX_HL16  13 
#define R_HEX_B13_PCREL  14 
#define R_HEX_B9_PCREL  15 
#define R_HEX_B32_PCREL_X  16 
#define R_HEX_32_6_X  17 
#define R_HEX_B22_PCREL_X  18 
#define R_HEX_B15_PCREL_X  19 
#define R_HEX_B13_PCREL_X  20 
#define R_HEX_B9_PCREL_X  21 
#define R_HEX_B7_PCREL_X  22 
#define R_HEX_16_X  23 
#define R_HEX_12_X  24 
#define R_HEX_11_X  25 
#define R_HEX_10_X  26 
#define R_HEX_9_X  27 
#define R_HEX_8_X  28 
#define R_HEX_7_X  29 
#define R_HEX_6_X  30 
#define R_HEX_32_PCREL  31 
#define R_HEX_COPY  32 
#define R_HEX_GLOB_DAT  33 
#define R_HEX_JMP_SLOT  34 
#define R_HEX_RELATIVE  35 
#define R_HEX_PLT_B22_PCREL  36 
#define R_HEX_GOTREL_LO16  37 
#define R_HEX_GOTREL_HI16  38 
#define R_HEX_GOTREL_32  39 
#define R_HEX_GOT_LO16  40 
#define R_HEX_GOT_HI16  41 
#define R_HEX_GOT_32  42 
#define R_HEX_GOT_16  43 
#define R_HEX_DTPMOD_32  44 
#define R_HEX_DTPREL_LO16  45 
#define R_HEX_DTPREL_HI16  46 
#define R_HEX_DTPREL_32  47 
#define R_HEX_DTPREL_16  48 
#define R_HEX_GD_PLT_B22_PCREL  49 
#define R_HEX_GD_GOT_LO16  50 
#define R_HEX_GD_GOT_HI16  51 
#define R_HEX_GD_GOT_32  52 
#define R_HEX_GD_GOT_16  53 
#define R_HEX_IE_LO16  54 
#define R_HEX_IE_HI16  55 
#define R_HEX_IE_32  56 
#define R_HEX_IE_GOT_LO16  57 
#define R_HEX_IE_GOT_HI16  58 
#define R_HEX_IE_GOT_32  59 
#define R_HEX_IE_GOT_16  60 
#define R_HEX_TPREL_LO16  61 
#define R_HEX_TPREL_HI16  62 
#define R_HEX_TPREL_32  63 
#define R_HEX_TPREL_16  64 
#define R_HEX_6_PCREL_X  65 
#define R_HEX_GOTREL_32_6_X  66 
#define R_HEX_GOTREL_16_X  67 
#define R_HEX_GOTREL_11_X  68 
#define R_HEX_GOT_32_6_X  69 
#define R_HEX_GOT_16_X  70 
#define R_HEX_GOT_11_X  71 
#define R_HEX_DTPREL_32_6_X  72 
#define R_HEX_DTPREL_16_X  73 
#define R_HEX_DTPREL_11_X  74 
#define R_HEX_GD_GOT_32_6_X  75 
#define R_HEX_GD_GOT_16_X  76 
#define R_HEX_GD_GOT_11_X  77 
#define R_HEX_IE_32_6_X  78 
#define R_HEX_IE_16_X  79 
#define R_HEX_IE_GOT_32_6_X  80 
#define R_HEX_IE_GOT_16_X  81 
#define R_HEX_IE_GOT_11_X  82 
#define R_HEX_TPREL_32_6_X  83 
#define R_HEX_TPREL_16_X  84 
#define R_HEX_TPREL_11_X  85


// ELF Relocation types for S390/zSeries
#define R_390_NONE  0 
#define R_390_8  1 
#define R_390_12  2 
#define R_390_16  3 
#define R_390_32  4 
#define R_390_PC32  5 
#define R_390_GOT12  6 
#define R_390_GOT32  7 
#define R_390_PLT32  8 
#define R_390_COPY  9 
#define R_390_GLOB_DAT  10 
#define R_390_JMP_SLOT  11 
#define R_390_RELATIVE  12 
#define R_390_GOTOFF  13 
#define R_390_GOTPC  14 
#define R_390_GOT16  15 
#define R_390_PC16  16 
#define R_390_PC16DBL  17 
#define R_390_PLT16DBL  18 
#define R_390_PC32DBL  19 
#define R_390_PLT32DBL  20 
#define R_390_GOTPCDBL  21 
#define R_390_64  22 
#define R_390_PC64  23 
#define R_390_GOT64  24 
#define R_390_PLT64  25 
#define R_390_GOTENT  26 
#define R_390_GOTOFF16  27 
#define R_390_GOTOFF64  28 
#define R_390_GOTPLT12  29 
#define R_390_GOTPLT16  30 
#define R_390_GOTPLT32  31 
#define R_390_GOTPLT64  32 
#define R_390_GOTPLTENT  33 
#define R_390_PLTOFF16  34 
#define R_390_PLTOFF32  35 
#define R_390_PLTOFF64  36 
#define R_390_TLS_LOAD  37 
#define R_390_TLS_GDCALL  38 
#define R_390_TLS_LDCALL  39 
#define R_390_TLS_GD32  40 
#define R_390_TLS_GD64  41 
#define R_390_TLS_GOTIE12  42 
#define R_390_TLS_GOTIE32  43 
#define R_390_TLS_GOTIE64  44 
#define R_390_TLS_LDM32  45 
#define R_390_TLS_LDM64  46 
#define R_390_TLS_IE32  47 
#define R_390_TLS_IE64  48 
#define R_390_TLS_IEENT  49 
#define R_390_TLS_LE32  50 
#define R_390_TLS_LE64  51 
#define R_390_TLS_LDO32  52 
#define R_390_TLS_LDO64  53 
#define R_390_TLS_DTPMOD  54 
#define R_390_TLS_DTPOFF  55 
#define R_390_TLS_TPOFF  56 
#define R_390_20  57 
#define R_390_GOT20  58 
#define R_390_GOTPLT20  59 
#define R_390_TLS_GOTIE20  60 
#define R_390_IRELATIVE  61

// Special section indices.
#define SHN_UNDEF  0       // Undefined  missing  irrelevant  or meaningless
#define SHN_LORESERVE  0xff00  // Lowest reserved index
#define SHN_LOPROC  0xff00  // Lowest processor-specific index
#define SHN_HIPROC  0xff1f  // Highest processor-specific index
#define SHN_LOOS  0xff20  // Lowest operating system-specific index
#define SHN_HIOS  0xff3f  // Highest operating system-specific index
#define SHN_ABS  0xfff1  // Symbol has absolute value; does not need relocation
#define SHN_COMMON  0xfff2  // FORTRAN COMMON or C external global variables
#define SHN_XINDEX  0xffff  // Mark that the index is > SHN_LORESERVE
#define SHN_HIRESERVE  0xffff  // Highest reserved index


// Section types.
#define SHT_NULL  0   // No associated section (inactive entry).
#define SHT_PROGBITS  1   // Program-defined contents.
#define SHT_SYMTAB  2   // Symbol table.
#define SHT_STRTAB  3   // String table.
#define SHT_RELA  4   // Relocation entries; explicit addends.
#define SHT_HASH  5   // Symbol hash table.
#define SHT_DYNAMIC  6   // Information for dynamic linking.
#define SHT_NOTE  7   // Information about the file.
#define SHT_NOBITS  8   // Data occupies no space in the file.
#define SHT_REL  9   // Relocation entries; no explicit addends.
#define SHT_SHLIB  10  // Reserved.
#define SHT_DYNSYM  11  // Symbol table.
#define SHT_INIT_ARRAY  14  // Pointers to initialization functions.
#define SHT_FINI_ARRAY  15  // Pointers to termination functions.
#define SHT_PREINIT_ARRAY  16  // Pointers to pre-init functions.
#define SHT_GROUP  17  // Section group.
#define SHT_SYMTAB_SHNDX  18  // Indices for SHN_XINDEX entries.
#define SHT_LOOS  0x60000000  // Lowest operating system-specific type.
#define SHT_GNU_ATTRIBUTES  0x6ffffff5  // Object attributes.
#define SHT_GNU_HASH  0x6ffffff6  // GNU-style hash table.
#define SHT_GNU_verdef  0x6ffffffd  // GNU version definitions.
#define SHT_GNU_verneed  0x6ffffffe  // GNU version references.
#define SHT_GNU_versym  0x6fffffff  // GNU symbol versions table.
#define SHT_HIOS  0x6fffffff  // Highest operating system-specific type.
#define SHT_LOPROC  0x70000000  // Lowest processor arch-specific type.
// Fixme: All this is duplicated in MCSectionELF. Why??
// Exception Index table
#define SHT_ARM_EXIDX  0x70000001U 
// BPABI DLL dynamic linking pre-emption map
#define SHT_ARM_PREEMPTMAP  0x70000002U 
//  Object file compatibility attributes
#define SHT_ARM_ATTRIBUTES  0x70000003U 
#define SHT_ARM_DEBUGOVERLAY  0x70000004U 
#define SHT_ARM_OVERLAYSECTION  0x70000005U 
#define SHT_HEX_ORDERED  0x70000000  // Link editor is to sort the entries in this section based on their sizes
#define SHT_X86_64_UNWIND  0x70000001  // Unwind information

#define SHT_MIPS_REGINFO  0x70000006  // Register usage information
#define SHT_MIPS_OPTIONS  0x7000000d  // General options

#define SHT_HIPROC  0x7fffffff  // Highest processor arch-specific type.
#define SHT_LOUSER  0x80000000  // Lowest type reserved for applications.
#define SHT_HIUSER  0xffffffff  // Highest type reserved for applications.


// Section flags.
#define SHF_WRITE  0x1 // Section data should be writable during execution. 
#define SHF_ALLOC  0x2 // Section occupies memory during program execution. 
#define SHF_EXECINSTR  0x4 // Section contains executable machine instructions. 
#define SHF_MERGE  0x10 // The data in this section may be merged. 
#define SHF_STRINGS  0x20 // The data in this section is null-terminated strings. 
#define SHF_INFO_LINK  0x40U // A field in this section holds a section header table index. 
#define SHF_LINK_ORDER  0x80U // Adds special ordering requirements for link editors. 

// This section requires special OS-specific processing to avoid incorrect
// behavior.
#define SHF_OS_NONCONFORMING  0x100U

// This section is a member of a section group.
#define SHF_GROUP  0x200U

// This section holds Thread-Local Storage.
#define SHF_TLS  0x400U

// Start of target-specific flags.

/// XCORE_SHF_CP_SECTION - All sections with the "c" flag are grouped
/// together by the linker to form the constant pool and the cp register is
/// set to the start of the constant pool by the boot code.
#define XCORE_SHF_CP_SECTION  0x800U

/// XCORE_SHF_DP_SECTION - All sections with the "d" flag are grouped
/// together by the linker to form the data section and the dp register is
/// set to the start of the section by the boot code.
#define XCORE_SHF_DP_SECTION  0x1000U

#define SHF_MASKOS  0x0ff00000

// Bits indicating processor-specific flags.
#define SHF_MASKPROC  0xf0000000

// If an object file section does not have this flag set  then it may not hold
// more than 2GB and can be freely referred to in objects using smaller code
// models. Otherwise  only objects using larger code models can refer to them.
// For example  a medium code model object can refer to data in a section that
// sets this flag besides being able to refer to data in a section that does
// not set it; likewise  a small code model object can refer only to code in a
// section that does not set this flag.
#define SHF_X86_64_LARGE  0x10000000

// All sections with the GPREL flag are grouped into a global data area
// for faster accesses
#define SHF_HEX_GPREL  0x10000000

// Do not strip this section. FIXME: We need target specific SHF_ enums.
#define SHF_MIPS_NOSTRIP  0x8000000


// Section Group Flags

#define GRP_COMDAT  0x1
#define GRP_MASKOS  0x0ff00000
#define GRP_MASKPROC  0xf0000000


// The size (in bytes) of symbol table entries.

#define SYMENTRY_SIZE32  16  // 32-bit symbol entry size
#define SYMENTRY_SIZE64  24  // 64-bit symbol entry size.


// Symbol bindings.

#define STB_LOCAL  0    // Local symbol  not visible outside obj file containing def
#define STB_GLOBAL  1   // Global symbol  visible to all object files being combined
#define STB_WEAK  2     // Weak symbol  like global but lower-precedence
#define STB_LOOS  10  // Lowest operating system-specific binding type
#define STB_HIOS  12  // Highest operating system-specific binding type
#define STB_LOPROC  13  // Lowest processor-specific binding type
#define STB_HIPROC  15  // Highest processor-specific binding type


// Symbol types.

#define STT_NOTYPE  0    // Symbol's type is not specified
#define STT_OBJECT  1    // Symbol is a data object (variable  array  etc.)
#define STT_FUNC  2    // Symbol is executable code (function  etc.)
#define STT_SECTION  3    // Symbol refers to a section
#define STT_FILE  4    // Local  absolute symbol that refers to a file
#define STT_COMMON  5    // An uninitialized common block
#define STT_TLS  6    // Thread local data object
#define STT_LOOS  7    // Lowest operating system-specific symbol type
#define STT_HIOS  8    // Highest operating system-specific symbol type
#define STT_GNU_IFUNC  10  // GNU indirect function
#define STT_LOPROC  13   // Lowest processor-specific symbol type
#define STT_HIPROC  15   // Highest processor-specific symbol type



#define STV_DEFAULT  0   // Visibility is specified by binding type
#define STV_INTERNAL  1   // Defined by processor supplements
#define STV_HIDDEN  2   // Not visible to other components
#define STV_PROTECTED  3   // Visible in other components but not preemptable


// Symbol number.

#define STN_UNDEF  0


// Segment types.

#define PT_NULL  0  // Unused segment.
#define PT_LOAD  1  // Loadable segment.
#define PT_DYNAMIC  2  // Dynamic linking information.
#define PT_INTERP  3  // Interpreter pathname.
#define PT_NOTE  4  // Auxiliary information.
#define PT_SHLIB  5  // Reserved.
#define PT_PHDR  6  // The program header table itself.
#define PT_TLS  7  // The thread-local storage template.
#define PT_LOOS  0x60000000  // Lowest operating system-specific pt entry type.
#define PT_HIOS  0x6fffffff  // Highest operating system-specific pt entry type.
#define PT_LOPROC  0x70000000  // Lowest processor-specific program hdr entry type.
#define PT_HIPROC  0x7fffffff  // Highest processor-specific program hdr entry type.

// x86-64 program header types.
// These all contain stack unwind tables.
#define PT_GNU_EH_FRAME  0x6474e550
#define PT_SUNW_EH_FRAME  0x6474e550
#define PT_SUNW_UNWIND  0x6464e550

#define PT_GNU_STACK  0x6474e551  // Indicates stack executability.
#define PT_GNU_RELRO  0x6474e552  // Read-only after relocation.

// ARM program header types.
#define PT_ARM_ARCHEXT  0x70000000  // Platform architecture compatibility info
// These all contain stack unwind tables.
#define PT_ARM_EXIDX  0x70000001
#define PT_ARM_UNWIND  0x70000001


// Segment flag bits.

#define PF_X  1          // Execute
#define PF_W  2          // Write
#define PF_R  4          // Read
#define PF_MASKOS  0x0ff00000 // Bits for operating system-specific semantics.
#define PF_MASKPROC  0xf0000000 // Bits for processor-specific semantics.


// Dynamic table entry tags.

#define DT_NULL  0         // Marks end of dynamic array.
#define DT_NEEDED  1         // String table offset of needed library.
#define DT_PLTRELSZ  2         // Size of relocation entries in PLT.
#define DT_PLTGOT  3         // Address associated with linkage table.
#define DT_HASH  4         // Address of symbolic hash table.
#define DT_STRTAB  5         // Address of dynamic string table.
#define DT_SYMTAB  6         // Address of dynamic symbol table.
#define DT_RELA  7         // Address of relocation table (Rela entries).
#define DT_RELASZ  8         // Size of Rela relocation table.
#define DT_RELAENT  9         // Size of a Rela relocation entry.
#define DT_STRSZ  10        // Total size of the string table.
#define DT_SYMENT  11        // Size of a symbol table entry.
#define DT_INIT  12        // Address of initialization function.
#define DT_FINI  13        // Address of termination function.
#define DT_SONAME  14        // String table offset of a shared objects name.
#define DT_RPATH  15        // String table offset of library search path.
#define DT_SYMBOLIC  16        // Changes symbol resolution algorithm.
#define DT_REL  17        // Address of relocation table (Rel entries).
#define DT_RELSZ  18        // Size of Rel relocation table.
#define DT_RELENT  19        // Size of a Rel relocation entry.
#define DT_PLTREL  20        // Type of relocation entry used for linking.
#define DT_DEBUG  21        // Reserved for debugger.
#define DT_TEXTREL  22        // Relocations exist for non-writable segments.
#define DT_JMPREL  23        // Address of relocations associated with PLT.
#define DT_BIND_NOW  24        // Process all relocations before execution.
#define DT_INIT_ARRAY  25        // Pointer to array of initialization functions.
#define DT_FINI_ARRAY  26        // Pointer to array of termination functions.
#define DT_INIT_ARRAYSZ  27        // Size of DT_INIT_ARRAY.
#define DT_FINI_ARRAYSZ  28        // Size of DT_FINI_ARRAY.
#define DT_RUNPATH  29        // String table offset of lib search path.
#define DT_FLAGS  30        // Flags.
#define DT_ENCODING  32        // Values from here to DT_LOOS follow the rules
// for the interpretation of the d_un union.

#define DT_PREINIT_ARRAY  32       // Pointer to array of preinit functions.
#define DT_PREINIT_ARRAYSZ  33     // Size of the DT_PREINIT_ARRAY array.

#define DT_LOOS  0x60000000  // Start of environment specific tags.
#define DT_HIOS  0x6FFFFFFF  // End of environment specific tags.
#define DT_LOPROC  0x70000000  // Start of processor specific tags.
#define DT_HIPROC  0x7FFFFFFF  // End of processor specific tags.

#define DT_RELACOUNT  0x6FFFFFF9  // ELF32_Rela count.
#define DT_RELCOUNT  0x6FFFFFFA  // ELF32_Rel count.

#define DT_FLAGS_1  0X6FFFFFFB  // Flags_1.
#define DT_VERDEF  0X6FFFFFFC  // The address of the version definition table.
#define DT_VERDEFNUM  0X6FFFFFFD  // The number of entries in DT_VERDEF.
#define DT_VERNEED  0X6FFFFFFE  // The address of the version Dependency table.
#define DT_VERNEEDNUM  0X6FFFFFFF  // The number of entries in DT_VERNEED.


// DT_FLAGS values.

#define DF_ORIGIN  0x01  // The object may reference $ORIGIN.
#define DF_SYMBOLIC  0x02  // Search the shared lib before searching the exe.
#define DF_TEXTREL  0x04  // Relocations may modify a non-writable segment.
#define DF_BIND_NOW  0x08  // Process all relocations on load.
#define DF_STATIC_TLS  0x10  // Reject attempts to load dynamically.


// State flags selectable in the `d_un.d_val' element of the DT_FLAGS_1 entry.

#define DF_1_NOW  0x00000001  // Set RTLD_NOW for this object.
#define DF_1_GLOBAL  0x00000002  // Set RTLD_GLOBAL for this object.
#define DF_1_GROUP  0x00000004  // Set RTLD_GROUP for this object.
#define DF_1_NODELETE  0x00000008  // Set RTLD_NODELETE for this object.
#define DF_1_LOADFLTR  0x00000010  // Trigger filtee loading at runtime.
#define DF_1_INITFIRST  0x00000020  // Set RTLD_INITFIRST for this object.
#define DF_1_NOOPEN  0x00000040  // Set RTLD_NOOPEN for this object.
#define DF_1_ORIGIN  0x00000080  // $ORIGIN must be handled.
#define DF_1_DIRECT  0x00000100  // Direct binding enabled.
#define DF_1_TRANS  0x00000200
#define DF_1_INTERPOSE  0x00000400  // Object is used to interpose.
#define DF_1_NODEFLIB  0x00000800  // Ignore default lib search path.
#define DF_1_NODUMP  0x00001000  // Object can't be dldump'ed.
#define DF_1_CONFALT  0x00002000  // Configuration alternative created.
#define DF_1_ENDFILTEE  0x00004000  // Filtee terminates filters search.
#define DF_1_DISPRELDNE  0x00008000  // Disp reloc applied at build time.
#define DF_1_DISPRELPND  0x00010000  // Disp reloc applied at run-time.


// ElfXX_VerDef structure version (GNU versioning)

#define VER_DEF_NONE  0
#define VER_DEF_CURRENT  1


// VerDef Flags (ElfXX_VerDef::vd_flags)

#define VER_FLG_BASE  0x1
#define VER_FLG_WEAK  0x2
#define VER_FLG_INFO  0x4


// Special constants for the version table. (SHT_GNU_versym/.gnu.version)

#define VER_NDX_LOCAL  0       // Unversioned local symbol
#define VER_NDX_GLOBAL  1       // Unversioned global symbol
#define VERSYM_VERSION  0x7fff  // Version Index mask
#define VERSYM_HIDDEN  0x8000  // Hidden bit (non-default version)


// ElfXX_VerNeed structure version (GNU versioning)

#define VER_NEED_NONE  0
#define VER_NEED_CURRENT  1


#endif