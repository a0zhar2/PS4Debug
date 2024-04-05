//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#pragma once
#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "../../libPS4/include/types.h"
#include "./protocol.h"
#include "./net.h"
#include "./debug.h"

int console_reboot_handle(int fd, struct cmd_packet *packet);
int console_print_handle(int fd, struct cmd_packet *packet);
int console_notify_handle(int fd, struct cmd_packet *packet);
int console_info_handle(int fd, struct cmd_packet *packet);

int console_handle(int fd, struct cmd_packet *packet);

#endif
