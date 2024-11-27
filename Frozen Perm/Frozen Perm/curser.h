#include <Windows.h>
#include <thread>

bool mouseLocked = false;
POINT lockPosition;

void Crypt();

void LockCurser() {
    mouseLocked = true;

    GetCursorPos(&lockPosition);  

    std::thread([]() {
        while (mouseLocked) {
            SetCursorPos(lockPosition.x, lockPosition.y);  
            std::this_thread::sleep_for(std::chrono::milliseconds(20));  
        }
        }).detach();
}

void UnlockCurser() {
    mouseLocked = false;
}

