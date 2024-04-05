//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#include "../../kernSDK/include/ksdk.h"
#include "../include/hooks.h"

int _main(void) {
    init_ksdk();

    printf("[ps4debug] kernel base 0x%llX\n", get_kbase());

    if(install_hooks()) {
        printf("[ps4debug] failed to install hooks\n");
        return 1;
    }

    return 0;
}