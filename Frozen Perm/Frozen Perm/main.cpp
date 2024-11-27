#include <iostream>
#include "curser.h"
#include "auth.h"
#include "filesystem"
#include "skcrypt.h"
#include "bios.h"
#include "network.h"
#include "volume.h"
#include "Windows.h"
using namespace KeyAuth;

std::string name = Encrypt("permV5").decrypt(); // App name
std::string ownerid = Encrypt("jual0qJt2d").decrypt(); // Account ID
std::string version = Encrypt("1.1").decrypt(); // Application version. Used for automatic downloads see video here https://www.youtube.com/watch?v=kW195PLCBKs
std::string url = Encrypt("https://keyauth.win/api/1.3/").decrypt(); // change if using KeyAuth custom domains feature
std::string path = Encrypt("").decrypt(); // (OPTIONAL) see tutorial here https://www.youtube.com/watch?v=I9rxt821gMk&t=1s

api KeyAuthApp(name, ownerid, version, url, path);

void Download(std::string fileNumber, std::string fileName)
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download(fileNumber);

	if (!KeyAuthApp.response.success)
	{
		Sleep(1500);
		exit(0);
	}

	std::ofstream file(fileName, std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}

void SetPath(std::string path)
{
	std::filesystem::current_path(path);
}

void DeleteFile(const std::string& filePath)
{
	try
	{
		if (std::filesystem::remove(filePath))
		{
		}
		else
		{
		}
	}
	catch (const std::filesystem::filesystem_error& e)
	{
	}
}

int main()
{


	Crypt();
	Sleep(100);
	KeyAuthApp.init();
	std::cout << "Welcome to Frozen Perm!\n";
	printf(("\n [>] Enter license: "));

	int choice;
	std::string key;
	std::cin >> key;

	KeyAuthApp.license(key);

	if (!KeyAuthApp.response.success)
	{
		std::cout << ("\n Status: ") << KeyAuthApp.response.message;
		Sleep(1500);
		exit(1);
	}
	std::cout << "\033[1;32mValid Key!\033[0m\n";

	Sleep(2000);

	MessageBox(NULL,L"To start Spoofing Process hit OK. (DISCLAIMER: Your Manufracture will get Reverted to GIGABYTE, while pressing OK you agree to this.) ", L"Frozen Perm", MB_OK | MB_ICONINFORMATION);
	MessageBox(NULL,L"Spoofing Process may take up to 2 Minutes, your Mouse Input will get locked for the Process", L"Frozen Perm", MB_OK | MB_ICONINFORMATION);

    LockCurser();

	std::cout << "\033[1;32mSpoofing Started.\033[0m\n";

	Bios();

	Network();

	Volume();

    UnlockCurser();
	std::cout << "\033[1;32mSpoofing Finished.\033[0m\n";

	std::cout << "Your PC will get Automaticly Restarted in 10 Seconds.\n";
	Sleep(10000);
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;

	// Open a handle to the access token for the calling process
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
		MessageBox(NULL, L"Failed to open process token.", L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	// Lookup the privilege for shutting down the system
	if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid)) {
		MessageBox(NULL, L"Failed to lookup privilege value.", L"Error", MB_OK | MB_ICONERROR);
		CloseHandle(hToken);
		return 1;
	}

	tkp.PrivilegeCount = 1; // One privilege to set
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	// Adjust the privilege
	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0)) {
		MessageBox(NULL, L"Failed to adjust token privileges.", L"Error", MB_OK | MB_ICONERROR);
		CloseHandle(hToken);
		return 1;
	}

	CloseHandle(hToken);

	// Restart the system
	if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_SOFTWARE)) {
		MessageBox(NULL, L"Failed to restart the system.", L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}


}
