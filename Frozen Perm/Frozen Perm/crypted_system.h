#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <vector>

bool ExecuteCommandHidden(const std::string& command) {
	STARTUPINFOA si = { sizeof(STARTUPINFOA) };
	PROCESS_INFORMATION pi;

	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;

	std::string fullCommand = "cmd.exe /c " + command;

	std::vector<char> cmdLineBuffer(fullCommand.begin(), fullCommand.end());
	cmdLineBuffer.push_back('\0'); // Null-Terminierer hinzufügen

	BOOL result = CreateProcessA(
		NULL,                   // Der Name der ausführbaren Datei (NULL verwendet cmd.exe)
		cmdLineBuffer.data(),   // Befehlszeile
		NULL,                   // Prozess-Sicherheitsattribute
		NULL,                   // Thread-Sicherheitsattribute
		FALSE,                  // Erben von Handles
		CREATE_NO_WINDOW,       // Kein Konsolenfenster anzeigen
		NULL,                   // Umgebungsvariablen
		NULL,                   // Startverzeichnis
		&si,                    // STARTUPINFO-Struktur
		&pi                     // PROCESS_INFORMATION-Struktur
	);

	if (result) {
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return true;
	}
	else {
		std::cerr << "Error creating process: " << GetLastError() << std::endl;
		return false;
	}
}