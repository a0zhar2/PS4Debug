//---------------------------------------------------------
// PS4Debug (PS4 Debugging Tool) Created by Golden
// - Ported to System FW 6.72 by GiantPluto
// - Forked/Currently maintained by Me (A0ZHAR)
//---------------------------------------------------------

#pragma once
#ifndef _INSTALLER_H
#define _INSTALLER_H

#include "../../kernSDK/include/ksdk.h"
#include "proc.h"

#define PAYLOAD_BASE 0x926200000
#define PAYLOAD_SIZE 0x400000

int runinstaller();

#endif
