#include "Manager.h"

Manager::Manager(Client* client) {
    this->client = client;

    this->initHooks();
};

#include "../Hook/Hooks/SwapChain/SwapChain.h"

auto Manager::initHooks(void) -> void {

    if(!this->hooks.empty())
        return;
    
    if(MH_Initialize() != MH_OK)
        return Utils::debugLog("Failed to initialize MinHook!");
    
    new SwapChain_Hook(this);

};

auto Manager::initCategories(void) -> void {

    if(!this->categories.empty())
        return;

};