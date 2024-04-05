//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------
#include "../../libPS4/include/network.h"
#include "../include/console.h"

// Function to handle the (System Reboot) Request
int console_reboot_handle(int fd, struct cmd_packet *packet) {
    if (g_debugging) {
        debug_cleanup(curdbgctx);

        // close the socket, we are not about to call free_client
        // this is a little hacky but meh
        sceNetSocketClose(fd);
    }

    sys_console_cmd(SYS_CONSOLE_CMD_REBOOT, NULL);
    return 1;
}


// Function to handle printing data to the console
int console_print_handle(int fd, struct cmd_packet *packet) {
    struct cmd_console_print_packet *pp;
    void *data;

    pp = (struct cmd_console_print_packet *)packet->data;

    if (pp) {
        // Allocate memory for the data
        data = pfmalloc(pp->length);
        if (!data) {
            net_send_status(fd, CMD_DATA_NULL);
            return 1;
        }

        // Clear the allocated memory
        memset(data, 0, pp->length);

        // Receive data from the socket
        net_recv_data(fd, data, pp->length, 1);

        // Print data to the console
        sys_console_cmd(SYS_CONSOLE_CMD_PRINT, data);
        net_send_status(fd, CMD_SUCCESS);

        // Free allocated memory
        free(data);

        return 0;
    }

    net_send_status(fd, CMD_DATA_NULL);

    return 1;
}

// Function to handle the request of sending a System Notification
int console_notify_handle(int fd, struct cmd_packet *packet) {
    struct cmd_console_notify_packet *np;
    void *data;

    np = (struct cmd_console_notify_packet *)packet->data;

    if (np) {
        // Allocate memory for the data
        data = pfmalloc(np->length);
        if (!data) {
            net_send_status(fd, CMD_DATA_NULL);
            return 1;
        }

        // Clear the allocated memory
        memset(data, 0, np->length);

        // Receive data from the socket
        net_recv_data(fd, data, np->length, 1);

        // Send system notification with text
        sceSysUtilSendSystemNotificationWithText(np->messageType, data);
        net_send_status(fd, CMD_SUCCESS);

        // Free allocated memory
        free(data);

        return 0;
    }

    net_send_status(fd, CMD_DATA_NULL);

    return 1;
}

// TODO: Fully implement this!
// Function to handle sending information via console
int console_info_handle(int fd, struct cmd_packet *packet) {
    // struct cmd_console_info_response resp;
    // size_t len;
    // extern int (*sysctl)(int *name, unsigned int namelen, char *oldval, size_t *oldlen, char *newval, size_t newlen);
    // extern int (*sysctlbyname)(char *name, char *oldval, size_t *oldlen, char *newval, size_t newlen);
    
    net_send_status(fd, CMD_SUCCESS);
    
    // net_send_data(fd, &resp, CMD_CONSOLE_INFO_RESPONSE_SIZE);
    return 0;
}

// Function to handle all incoming packets.
// - Reboot, End, Print, Notify, and Info
int console_handle(int fd, struct cmd_packet *packet) {
    // Handle the value of the <cmd> member of recived packet,
    switch (packet->cmd) {
        case CMD_CONSOLE_REBOOT: return console_reboot_handle(fd, packet);
        case CMD_CONSOLE_END:    return 1;
        case CMD_CONSOLE_PRINT:  return console_print_handle(fd, packet);
        case CMD_CONSOLE_NOTIFY: return console_notify_handle(fd, packet);
        case CMD_CONSOLE_INFO:   return console_info_handle(fd, packet);
    };

    return 0;
}
