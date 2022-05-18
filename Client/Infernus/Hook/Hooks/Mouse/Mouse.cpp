#include "Mouse.h"

typedef void(__fastcall* MouseHook)(uint64_t, char, bool, int, int, void*, void*, void*);
MouseHook _MouseHook;

auto MouseHook_Callback(uint64_t a1, char action, bool isDown, int x, int y, void* a6, void* a7, void* a8) -> void {

    if(action > 0 && action < 3)
        ImGui::GetIO().MouseDown[0] = isDown;
    
    if(!ImGui::GetIO().WantCaptureMouse)
        _MouseHook(a1, action, isDown, x, y, a6, a7, a8);
};

auto Mouse_Hook::init(void) -> void {
    
    auto sig = Mem::findSig("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 54 41 55 41 56 41 57 48 83 EC 60 44");

    if(!sig)
        return Utils::debugLog("Unable to find signature for [ Mouse ] Hook!");
    
    if(MH_CreateHook((void*)sig, &MouseHook_Callback, reinterpret_cast<LPVOID*>(&_MouseHook)) != MH_OK)
        return Utils::debugLog("Failed to create hook for [ Mouse ] Hook");
    
    Utils::debugLog("Enabling [ Mouse ] Hook");
    MH_EnableHook((void*)sig);

};