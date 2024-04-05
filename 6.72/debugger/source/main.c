//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#include "../../libPS4/include/ps4.h"

#include "../include/ptrace.h"
#include "../include/server.h"
#include "../include/debug.h"

#define CURRENT_PATCH_V "v1.2.5"

int _main(void) {
    initKernel();
    initLibc();
    initPthread();
    initNetwork();
    initSysUtil();

    // sleep a few seconds
    // maybe lower our thread priority?
    sceKernelSleep(2);

    // just a little notify
    sceSysUtilSendSystemNotificationWithText(222, "PS4Debug "CURRENT_PATCH_V" by A0ZHAR!");
    
    // jailbreak current thread
    sys_console_cmd(SYS_CONSOLE_CMD_JAILBREAK, NULL);

    // updates
    mkdir("/update/PS4UPDATE.PUP", 0777);
    mkdir("/update/PS4UPDATE.PUP.net.temp", 0777);

    // start the server, this will block
    start_server();

    return 0;
}
