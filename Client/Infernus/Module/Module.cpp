#include "Module.h"
#include "../Category/Category.h"

Module::Module(Category* category, std::string name) {
    this->category = category;
    this->name = name;

    this->category->modules.push_back(this);
};

auto Module::baseTick(void) -> void {
    if(this->wasEnabled != this->isEnabled) {
        this->wasEnabled = this->isEnabled;

        if(this->isEnabled)
            this->onEnable();
        else
            this->onDisable();
    };

    if(this->isEnabled)
        this->onTick();
};