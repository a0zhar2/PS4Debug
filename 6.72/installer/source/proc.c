//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------


#include "../include/proc.h"

// This can be made into a working function, but for now
// it's a shell
#define nlPrintf(...)

// Find a certain Process by Name, and if found, return it as
// a new <proc> struct instance
struct proc *proc_find_by_name(const char *name) {
    // If the given <name> argument is invalid then return early
    if (!name) return NULL;

    // Otherwise, create a new <proc> structure instance
    struct proc *p = *allproc;

    // Go trough each process, until the right process is found 
    while((p = p->p_forw)){
        // If the name of the current selected process, matches
        // the requested process name given by <name>, then we
        // return that process
        if (!memcmp(p->p_comm, name, strlen(name))) 
            return p;
    }
    
    // If the requested process wasn't found, we return NULL
    // indicating error
    return NULL;
}

struct proc *proc_find_by_pid(int pid) {
    struct proc *p;

    p = *allproc;
    do {
        if (p->pid == pid) {
            return p;
        }
    } while ((p = p->p_forw));

    return NULL;
}

int proc_get_vm_map(struct proc *p, struct proc_vm_map_entry **entries, uint64_t *num_entries) {
    struct proc_vm_map_entry *info = NULL;
    struct vm_map_entry *entry = NULL;
    int r = 0;

    struct vmspace *vm = p->p_vmspace;
    struct vm_map *map = &vm->vm_map;

    vm_map_lock_read(map);

    int num = map->nentries;
    if (!num) {
        goto error;
    }

    r = vm_map_lookup_entry(map, NULL, &entry);
    if (r) {
        goto error;
    }

    info = (struct proc_vm_map_entry *)malloc(num * sizeof(struct proc_vm_map_entry), M_TEMP, 2);
    if (!info) {
        r = 1;
        goto error;
    }

    // Iterate over each entry and copy relevant information
    for (int i = 0; i < num; i++) {
        info[i].start = entry->start;
        info[i].end = entry->end;
        info[i].offset = entry->offset;
        info[i].prot = entry->prot & (entry->prot >> 8);
        memcpy(info[i].name, entry->name, sizeof(info[i].name));

        // If no more entries, exit loop
        if (!(entry = entry->next))
            break;
    }

    error:
    vm_map_unlock_read(map);

    if (entries) {
        *entries = info;
    }

    if (num_entries) {
        *num_entries = num;
    }

    return 0;
}

int proc_rw_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n, int write) {
    struct thread *td = curthread(); // Get the current thread
    struct iovec iov;                // Define an iovec structure for scatter/gather I/O operations
    struct uio uio;                  // Define a uio structure for user I/O operations
    int result = 0;                  // Return value

    // Check if the process pointer is invalid, and if so
    // return early
    if (!p) return 1;

    // Check if the size of data is zero
    if (size == 0) {
        // Update bytes read/written (if pointer provided)
        if (n) *n = 0;
        
        // Then return early
        return 0;
    }

    // Initialize the iov structure with the data buffer and size
    memset(&iov, NULL, sizeof(iov));
    iov.iov_base = data; // Set iov_base to the data buffer
    iov.iov_len = size;  // Set iov_len to the size of the data

    // Initialize the uio structure with iov, pointer, size, and flags
    memset(&uio, NULL, sizeof(uio));
    uio.uio_iov = &iov;                        // Set uio_iov to point to the iov structure
    uio.uio_iovcnt = 1;                        // Set uio_iovcnt to 1
    uio.uio_offset = (uint64_t)ptr;            // Set uio_offset to the pointer
    uio.uio_resid = size;                      // Set uio_resid to the size of the data
    uio.uio_segflg = UIO_SYSSPACE;             // Set uio_segflg to indicate system space
    uio.uio_rw = write ? UIO_WRITE : UIO_READ; // Set uio_rw to indicate read or write operation
    uio.uio_td = td;                           // Set uio_td to the current thread

    // TODO: Comment this line
    result = proc_rwmem(p, &uio);

    // TODO: Comment this line
    if (n) *n = (uint64_t)((uint64_t)size - uio.uio_resid);
    
    return result;
}

inline int proc_read_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n) {
    return proc_rw_mem(p, ptr, size, data, n, 0);
}

inline int proc_write_mem(struct proc *p, void *ptr, uint64_t size, void *data, uint64_t *n) {
    return proc_rw_mem(p, ptr, size, data, n, 1);
}

int proc_allocate(struct proc *p, void **address, uint64_t size) {
    uint64_t addr = NULL;
    int r = 0;

    if (!address) {
        r = 1;
        goto error;
    }

    struct vmspace *vm = p->p_vmspace;
    struct vm_map *map = &vm->vm_map;

    vm_map_lock(map);

    r = vm_map_findspace(map, NULL, size, &addr);
    if (r) {
        vm_map_unlock(map);
        goto error;
    }

    r = vm_map_insert(map, NULL, NULL, addr, addr + size, VM_PROT_ALL, VM_PROT_ALL, 0);

    vm_map_unlock(map);

    if (r) {
        goto error;
    }

    if (address) {
        *address = (void *)addr;
    }

    error:
    return r;
}

int proc_deallocate(struct proc *p, void *address, uint64_t size) {
    int r = 0;

    struct vmspace *vm = p->p_vmspace;
    struct vm_map *map = &vm->vm_map;

    vm_map_lock(map);

    r = vm_map_delete(map, (uint64_t)address, (uint64_t)address + size);

    vm_map_unlock(map);

    return r;
}

int proc_mprotect(struct proc *p, void *address, void *end, int new_prot) {
    int r = 0;

    uint64_t addr = (uint64_t)address;
    uint64_t addrend = (uint64_t)end;

    struct vmspace *vm = p->p_vmspace;
    struct vm_map *map = &vm->vm_map;

    // update the max prot then set new prot
    r = vm_map_protect(map, addr, addrend, new_prot, 1);
    if (r) {
        return r;
    }

    r = vm_map_protect(map, addr, addrend, new_prot, 0);

    return r;
}

// Function to create a new thread for a certain Process
// @param p       Pointer to Process Struct
// @param address Address of the function to be executed in the new thread?
int proc_create_thread(struct proc *p, uint64_t address) {
    void *rpcldraddr = NULL; // Address of the allocated space for RPC loader
    void *stackaddr = NULL; // Address of the allocated stack space
    struct proc_vm_map_entry *entries = NULL; // Entries of process memory mappings
    uint64_t num_entries = 0; // Number of memory map entries
    uint64_t n = 0; // Number of bytes read or written
    int result = 0; // Result variable

    // Calculate the size of the RPC loader
    uint64_t ldrsize = sizeof(rpcldr);
    ldrsize += (PAGE_SIZE - (ldrsize % PAGE_SIZE));

    // Define the size of the stack
    uint64_t stacksize = 0x80000;

    // Allocate memory for RPC loader
    result = proc_allocate(p, &rpcldraddr, ldrsize);
    if (result) {
        nlPrintf("Unable to Allocate memory for RPC Loader!");
        goto error;
    }

   // Allocate memory for stack
    result = proc_allocate(p, &stackaddr, stacksize);
    if (result) {
        nlPrintf("Unable to allocate memory for Stack");;
        goto error;
    }

    // Write RPC loader to allocated memory
    result = proc_write_mem(p, rpcldraddr, sizeof(rpcldr), (void *)rpcldr, &n);
    if (result) {
        nlPrintf("Unable to write RPC loader to allocated memory");
        goto error;
    }

    // Get the first thread of the process (donor thread?)
    struct thread *thr = TAILQ_FIRST(&p->p_threads);

    // Get the memory map entries of the process
    result = proc_get_vm_map(p, &entries, &num_entries);
    if (result) {
        goto error;
    }

    uint64_t _scePthreadAttrInit = 0;
    uint64_t _scePthreadAttrSetstacksize = 0;
    uint64_t _scePthreadCreate = 0;
    uint64_t _thr_initial = 0;

    // Find addresses of relevant functions in memory map entries
    for (int i = 0; i < num_entries; i++) {
        // If the current entry's protection doesn't allow for 
        // Reading and Executing Memory, skip it
        if (entries[i].prot != (PROT_READ | PROT_EXEC))
            continue;

        // If the name of the current selected entry is the same as the
        // PS4 libkernel system module 
        if (!memcmp(entries[i].name, "libkernel.sprx", 14)) {
            // Find addresses of relevant functions from the module
            // then exit the for-loop
            _scePthreadAttrInit = entries[i].start + 0x00013A40;
            _scePthreadAttrSetstacksize = entries[i].start + 0x00013A60;
            _scePthreadCreate = entries[i].start + 0x00013E80;
            _thr_initial = entries[i].start + 0x00435420;
            break;
        }

        // If the name of the current selected entry is the same as the
        // PS4 libkernel_web system module 
        if (!memcmp(entries[i].name, "libkernel_web.sprx", 18)) {
            // Find addresses of relevant functions from the module
            // then exit the for-loop
            _scePthreadAttrInit = entries[i].start + 0x0001FD20;
            _scePthreadAttrSetstacksize = entries[i].start + 0x00010540;
            _scePthreadCreate = entries[i].start + 0x0000A0F0;
            _thr_initial = entries[i].start + 0x00435420;
            break;
        }
        // If the name of the current selected entry is the same as the
        // PS4 libkernel_sys system module 
        if (!memcmp(entries[i].name, "libkernel_sys.sprx", 18)) {
            // Find addresses of relevant functions from the module
            // then exit the for-loop
            _scePthreadAttrInit = entries[i].start + 0x00014570;
            _scePthreadAttrSetstacksize = entries[i].start + 0x00014590;
            _scePthreadCreate = entries[i].start + 0x000149B0;
            _thr_initial = entries[i].start + 0x00435830;
            break;
        }
    }
    // Check if function addresses were found
    if (!_scePthreadAttrInit) {
        goto error;
    }

    // Write variable values to RPC loader memory
    result = proc_write_mem(p, rpcldraddr + offsetof(struct rpcldr_header, stubentry), sizeof(address), (void *)&address, &n);
    if (result) {
        goto error;
    }
    
    result = proc_write_mem(p, rpcldraddr + offsetof(struct rpcldr_header, scePthreadAttrInit), sizeof(_scePthreadAttrInit), (void *)&_scePthreadAttrInit, &n);
    if (result) {
        goto error;
    }

    result = proc_write_mem(p, rpcldraddr + offsetof(struct rpcldr_header, scePthreadAttrSetstacksize), sizeof(_scePthreadAttrSetstacksize), (void *)&_scePthreadAttrSetstacksize, &n);
    if (result) {
        goto error;
    }

    result = proc_write_mem(p, rpcldraddr + offsetof(struct rpcldr_header, scePthreadCreate), sizeof(_scePthreadCreate), (void *)&_scePthreadCreate, &n);
    if (result) {
        goto error;
    }

    result = proc_write_mem(p, rpcldraddr + offsetof(struct rpcldr_header, thr_initial), sizeof(_thr_initial), (void *)&_thr_initial, &n);
    if (result) {
        goto error;
    }

    // Execute the loader in a new thread
    // note: do not enter in the pid information as it expects it to be stored in userland
    uint64_t ldrentryaddr = (uint64_t)rpcldraddr + *(uint64_t *)(rpcldr + 4);
    result = create_thread(thr, NULL, (void *)ldrentryaddr, NULL, stackaddr, stacksize, NULL, NULL, NULL, 0, NULL);
    if (result) {
        nlPrintf("Unable to execute the loader in new thread");
        goto error;
    }

    // Wait until loader is done
    uint8_t ldrdone = 0;
    while (!ldrdone) {
        result = proc_read_mem(p, (void *)(rpcldraddr + offsetof(struct rpcldr_header, ldrdone)), sizeof(ldrdone), &ldrdone, &n);
        if (result) { 
            goto error;
        }
    }

error:;
    // Deallocate the memory allocated for entries
    if (entries) free(entries, M_TEMP);

    // Deallocate the memory allocated for the RPC-Loader in the process?
    if (rpcldraddr) proc_deallocate(p, rpcldraddr, ldrsize);
    
    // Deallocate the memory allocated for stack inside the process?
    if (stackaddr) proc_deallocate(p, stackaddr, stacksize);
    
    // Return the Result code
    return result;
}

int proc_map_elf(struct proc *p, void *elf, void *exec) {
    struct Elf64_Ehdr *ehdr = (struct Elf64_Ehdr *)elf;

    struct Elf64_Phdr *phdr = elf_pheader(ehdr);
    if (phdr) {
        // use segments
        for (int i = 0; i < ehdr->e_phnum; i++) {
            struct Elf64_Phdr *phdr = elf_segment(ehdr, i);

            if (phdr->p_filesz) {
                proc_write_mem(p, (void *)((uint8_t *)exec + phdr->p_paddr), phdr->p_filesz, (void *)((uint8_t *)elf + phdr->p_offset), NULL);
            }
        }
    } else {
        // use sections
        for (int i = 0; i < ehdr->e_shnum; i++) {
            struct Elf64_Shdr *shdr = elf_section(ehdr, i);

            if (!(shdr->sh_flags & SHF_ALLOC)) {
                continue;
            }

            if (shdr->sh_size) {
                proc_write_mem(
                    p,
                    (void *)((uint8_t *)exec + shdr->sh_addr),
                    shdr->sh_size,
                    (void *)((uint8_t *)elf + shdr->sh_offset),
                    NULL
                );
            }
        }
    }

    return 0;
}

int proc_relocate_elf(struct proc *p, void *elf, void *exec) {
    struct Elf64_Ehdr *ehdr = (struct Elf64_Ehdr *)elf;

    for (int i = 0; i < ehdr->e_shnum; i++) {
        struct Elf64_Shdr *shdr = elf_section(ehdr, i);

        // check table
        if (shdr->sh_type == SHT_REL) {
            // process each entry in the table
            for (int j = 0; j < shdr->sh_size / shdr->sh_entsize; j++) {
                struct Elf64_Rela *reltab = &((struct Elf64_Rela *)((uint64_t)ehdr + shdr->sh_offset))[j];
                uint8_t **ref = (uint8_t **)((uint8_t *)exec + reltab->r_offset);
                uint8_t *value = NULL;

                switch (ELF64_R_TYPE(reltab->r_info)) {
                    case R_X86_64_RELATIVE:
                        // *ref = (uint8_t *)exec + reltab->r_addend;
                        value = (uint8_t *)exec + reltab->r_addend;
                        proc_write_mem(p, ref, sizeof(value), (void *)&value, NULL);
                        break;
                    case R_X86_64_64:
                    case R_X86_64_JUMP_SLOT:
                    case R_X86_64_GLOB_DAT:
                        // not supported
                        break;
                }
            }
        }
    }

    return 0;
}

int proc_load_elf(struct proc *p, void *elf, uint64_t *elfbase, uint64_t *entry) {
    void *elfaddr = NULL;
    uint64_t msize = 0;
    int r = 0;

    struct Elf64_Ehdr *ehdr = (struct Elf64_Ehdr *)elf;

    r = elf_mapped_size(elf, &msize);
    if (r) {
        goto error;
    }

    // resize to pages
    msize += (PAGE_SIZE - (msize % PAGE_SIZE));

    // allocate
    r = proc_allocate(p, &elfaddr, msize);
    if (r) {
        goto error;
    }

    // map
    r = proc_map_elf(p, elf, elfaddr);
    if (r) {
        goto error;
    }

    // relocate
    r = proc_relocate_elf(p, elf, elfaddr);
    if (r) {
        goto error;
    }

    if (elfbase) {
        *elfbase = (uint64_t)elfaddr;
    }

    if (entry) {
        *entry = (uint64_t)elfaddr + ehdr->e_entry;
    }

    error:
    return r;
}
