#include "Key.h"
#include "../../../Manager/Manager.h"

typedef void(__thiscall* KeyHook)(uint64_t, bool);
KeyHook _KeyHook;

Manager* hookMgr = nullptr;

auto KeyHook_Callback(uint64_t key, bool isDown) -> void {
    hookMgr->keyMap[key] = isDown;

    auto instance = Minecraft::getClientInstance();
    auto mcGame = instance->getMinecraftGame();
    bool cancel = false;
    
    for(auto category : hookMgr->categories) {
        for(auto mod : category->modules) {

            if (mod->newKey && isDown) {
                mod->newKey = false;
                mod->setKey(key);
                return;
            };

            if(isDown && mod->key == key) {
                if(mcGame != nullptr && mcGame->canUseKeys)
                    mod->isEnabled = !mod->isEnabled;
            };
            
            if(mod->isEnabled)
                mod->onKey(key, isDown, &cancel);

        };
    };

    if(!cancel)
        _KeyHook(key, isDown);
};

auto Key_Hook::init(void) -> void {
    
    hookMgr = this->manager;

    auto sig = Mem::findSig("48 ? ? 48 ? ? ? 4C 8D 05 ? ? ? ? 89");

    if(!sig)
        return Utils::debugLog("Unable to find signature for [ Key ] Hook!");

    if(MH_CreateHook((void*)sig, &KeyHook_Callback, reinterpret_cast<LPVOID*>(&_KeyHook)) != MH_OK)
        return Utils::debugLog("Failed to create hook for [ Key ] Hook");
    
    Utils::debugLog("Enabling [ Key ] Hook");
    MH_EnableHook((void*)sig);

};