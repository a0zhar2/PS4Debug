//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#include "../include/elf.h"

int elf_mapped_size(void *elf, uint64_t *msize) {
    struct Elf64_Ehdr *ehdr = (struct Elf64_Ehdr *)elf;

    // check magic
    if (memcmp(ehdr->e_ident, ElfMagic, 4))
        return 1;

    uint64_t s = 0;

    struct Elf64_Phdr *phdr = elf_pheader(ehdr);
    if (phdr) {
        // use segments
        for (int i = 0; i < ehdr->e_phnum; i++) {
            struct Elf64_Phdr *phdr = elf_segment(ehdr, i);

            uint64_t delta = phdr->p_paddr + phdr->p_memsz;
            if (delta > s) {
                s = delta;
            }
        }
    } else {
        // use sections
        for (int i = 0; i < ehdr->e_shnum; i++) {
            struct Elf64_Shdr *shdr = elf_section(ehdr, i);

            uint64_t delta = shdr->sh_addr + shdr->sh_size;
            if (delta > s) {
                s = delta;
            }
        }
    }

    if (msize) *msize = s;

    return 0;
}

struct Elf64_Phdr *elf_pheader(struct Elf64_Ehdr *hdr) {
    if (!hdr->e_phoff)
        return 0;

    return (struct Elf64_Phdr *)((uint64_t)hdr + hdr->e_phoff);
}

struct Elf64_Phdr *elf_segment(struct Elf64_Ehdr *hdr, int idx) {
    uint64_t addr = (uint64_t)elf_pheader(hdr);
    if (!addr) return 0;

    return (struct Elf64_Phdr *)(addr + (hdr->e_phentsize * idx));
}

struct Elf64_Shdr *elf_sheader(struct Elf64_Ehdr *hdr) {
    if (!hdr->e_shoff)
        return 0;

    return (struct Elf64_Shdr *)((uint64_t)hdr + hdr->e_shoff);
}

struct Elf64_Shdr *elf_section(struct Elf64_Ehdr *hdr, int idx) {
    uint64_t addr = (uint64_t)elf_sheader(hdr);
    if (!addr) return 0;

    return (struct Elf64_Shdr *)(addr + (hdr->e_shentsize * idx));
}