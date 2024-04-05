//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#pragma once
#ifndef _NET_H
#define _NET_H

#include "../../libPS4/include/ps4.h"
#include "./errno.h"

#define FD_SETSIZE     1024
#define NET_MAX_LENGTH 8192

#define	SO_USELOOPBACK 0x0040     // bypass hardware when possible 
#define	SO_LINGER      0x0080     // linger on close if data present 
#define	SO_NOSIGPIPE   0x0800     // no SIGPIPE from EPIPE 
#define	SO_SNDBUF      0x1001     // send buffer size 
#define	SO_RCVBUF      0x1002     // receive buffer size 
#define	SO_USELOOPBACK 0x0040     // bypass hardware when possible 
#define	SO_LINGER      0x0080     // linger on close if data present 
#define	SO_NOSIGPIPE   0x0800     // no SIGPIPE from EPIPE 
#define	SO_SNDBUF      0x1001     // send buffer size 
#define	SO_RCVBUF      0x1002     // receive buffer size 
#define	SO_DEBUG       0x00000001 // turn on debugging info recording 
#define	SO_ACCEPTCONN  0x00000002 // socket has had listen() 
#define	SO_REUSEADDR   0x00000004 // allow local address reuse 
#define	SO_KEEPALIVE   0x00000008 // keep connections alive 
#define	SO_DONTROUTE   0x00000010 // just use interface addresses 
#define	SO_BROADCAST   0x00000020 // permit sending of broadcast msgs 

//
// NOTE (From Previous Developer):
// ---------
// I would like to move away from the stupid sony wrapper functions. 
// They do not always return what I expect and I want to use straight syscalls
//

typedef unsigned long fd_mask;

#define	_howmany(x, y)	(((x) + ((y) - 1)) / (y))

#define _NFDBITS (sizeof(fd_mask) * 8) // bits per mask

typedef struct _FD_SET_T {
    fd_mask fds_bits[_howmany(FD_SETSIZE, _NFDBITS)];
} fd_set;


int net_select(int fd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
int net_send_data(int fd, void *data, int length);
int net_recv_data(int fd, void *data, int length, int force);
int net_send_status(int fd, uint32_t status);

// Function to zero out a file descriptor set
void FD_ZERO(fd_set* s);
// Function to set a file descriptor in a set
void FD_SET(int d, fd_set* s);
// Function to clear a file descriptor in a set
void FD_CLR(int d, fd_set* s);
// Function to check if a file descriptor is set in a set
int FD_ISSET(int d, fd_set* s);
#endif
