#include <Windows.h>

auto init() -> void {
    
    //

};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) {
    
    switch(fdwReason) {

        case DLL_PROCESS_ATTACH:
            
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);

        break;

    };

    return TRUE;

};