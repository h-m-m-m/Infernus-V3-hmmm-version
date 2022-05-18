#include "GameMode.h"

Manager* gmMgr = nullptr;

typedef void (__thiscall* GameMode_Tick)(GameMode*);
GameMode_Tick _GameMode_Tick;

auto GameMode_Tick_Callback(GameMode* GM) -> void {

    //

    _GameMode_Tick(GM);
    
};

auto GameMode_Hook::init(void) -> void {
    gmMgr = this->manager;

    auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 0A 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B");

    if(!sig)
        return Utils::debugLog("Unable to find signature for GameMode::tick Hook!");
    
    int offset = *reinterpret_cast<int*>(sig + 3);
    uintptr_t** VTable = reinterpret_cast<uintptr_t**>(sig + offset + 7);

    if(VTable == nullptr)
        return Utils::debugLog("Unable to find signature for [ GameMode::tick ] Hook!");
    
    if(MH_CreateHook((void*)VTable[8], &GameMode_Tick_Callback, reinterpret_cast<LPVOID*>(&_GameMode_Tick)) != MH_OK)
        return Utils::debugLog("Failed to create hook for [ GameMode::tick ] ");
    
    Utils::debugLog("Enabling [ GameMode::tick ] Hook");
    MH_EnableHook((void*)VTable[8]);
};