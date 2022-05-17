#include "Manager.h"

Manager::Manager(Client* client) {
    this->client = client;

    this->initHooks();
};

#include "../Hook/Hooks/SwapChain/SwapChain.h"

auto Manager::initHooks(void) -> void {
    
    if(MH_Initialize() != MH_OK)
        return Utils::debugLog("Failed to initialize MinHook!");
    
    this->hooks.push_back(new SwapChain_Hook(this));

};