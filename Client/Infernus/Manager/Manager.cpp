#include "Manager.h"

Manager::Manager(Client* client) {
    this->client = client;

    this->initHooks();
    this->initCategories();
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
    
    new Category(this, "Combat");
    new Category(this, "Movement");
    new Category(this, "Player");
    new Category(this, "Visuals");
    new Category(this, "World");
    new Category(this, "Other");

    this->initModules();

};

#include "../Module/Modules/Other/TestModule.h"

auto Manager::initModules(void) -> void {

    auto combat = this->getCategory("Combat");
    auto movement = this->getCategory("Movement");
    auto player = this->getCategory("Player");
    auto visuals = this->getCategory("Visuals");
    auto world = this->getCategory("World");
    auto other = this->getCategory("Other");

    
    /* Other */

    if(other != nullptr && other->modules.empty()) {

        new TestModule(other);

    };


};

auto Manager::getCategory(std::string name) -> Category* {
    
    for(auto category : this->categories)
        if(category->name == name)
            return category;
    
    return nullptr;

};