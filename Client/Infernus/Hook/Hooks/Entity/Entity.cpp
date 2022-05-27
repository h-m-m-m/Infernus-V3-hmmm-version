#include "Entity.h"
#include "../../../Manager/Manager.h"

typedef void (__thiscall* Actor_Tick)(Actor*, void*);
Actor_Tick _Actor_Tick;

Manager* ehMgr = nullptr;

auto Actor_Tick_Callback(Actor* e, void* a2) -> void {
    
    if(ehMgr != nullptr)
        ehMgr->entityMap[e->getRuntimeId()] = e;

    _Actor_Tick(e, a2);
};

auto Entity_Hooks::init(void) -> void {

    ehMgr = this->manager;
    
    auto sig = Mem::findSig("40 53 48 83 EC 50 48 8B D9 48 83 B9 ? ? ? ? ? 0F 84 ? ? ? ? 48 83");
    
    if(!sig)
        return Utils::debugLog("Failed to find Sig for [ Entity::tick ] Hook!");
    
    if(MH_CreateHook((void*)sig, &Actor_Tick_Callback, reinterpret_cast<LPVOID*>(&_Actor_Tick)) != MH_OK)
        return Utils::debugLog("Failed to create hook for [ Entity::tick ] ");
    
    Utils::debugLog("Enabling [ Entity::tick ] Hook");
    MH_EnableHook((void*)sig);

};