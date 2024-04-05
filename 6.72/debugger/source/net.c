//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------


#include "../../libPS4/include/types.h"
#include "../include/net.h"


int net_select(int fd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout) {
    return syscall(93, fd, readfds, writefds, exceptfds, timeout);
}

int net_send_data(int fd, void *data, int length) {
    int left = length;
    int offset = 0;
    int sent = 0;

    errno = NULL;

    while (left > 0) {
        if (left > NET_MAX_LENGTH) {
            sent = write(fd, data + offset, NET_MAX_LENGTH);
        } else {
            sent = write(fd, data + offset, left);
        }

        if (sent <= 0) {
            if (errno && errno != EWOULDBLOCK) {
                return sent;
            }
        } else {
            offset += sent;
            left -= sent;
        }
    }

    return offset;
}

int net_recv_data(int fd, void *data, int length, int force) {
    int left = length;
    int offset = 0;
    int recv = 0;

    errno = NULL;

    while (left > 0) {
        if (left > NET_MAX_LENGTH) {
            recv = read(fd, data + offset, NET_MAX_LENGTH);
        } else {
            recv = read(fd, data + offset, left);
        }

        if (recv <= 0) {
            if (force) {
                if (errno && errno != EWOULDBLOCK) {
                    return recv;
                }
            } else {
                return offset;
            }
        } else {
            offset += recv;
            left -= recv;
        }
    }

    return offset;
}

int net_send_status(int fd, uint32_t status) {
    uint32_t d = status;

    return net_send_data(fd, &d, sizeof(uint32_t));
}


// Function to zero out a file descriptor set
void FD_ZERO(fd_set* s) {
    int i;
    unsigned long* b = s->fds_bits;
    for (i = sizeof(fd_set) / sizeof(long); i; i--)
        *b++ = 0;
}

// Function to set a file descriptor in a set
void FD_SET(int d, fd_set* s) {
    s->fds_bits[d / _NFDBITS] |= (1UL << (d % _NFDBITS));
}

// Function to clear a file descriptor in a set
void FD_CLR(int d, fd_set* s) {
    s->fds_bits[d / _NFDBITS] &= ~(1UL << (d % _NFDBITS));
}

// Function to check if a file descriptor is set in a set
int FD_ISSET(int d, fd_set* s) {
    return !!(s->fds_bits[d / _NFDBITS] & (1UL << (d % _NFDBITS)));
}