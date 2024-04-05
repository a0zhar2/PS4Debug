//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------


#include "../include/syscall.h"
#include "../include/installer.h"

int _main(void) {
    return syscall(11, runinstaller);
}
