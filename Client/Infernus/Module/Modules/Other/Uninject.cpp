#include "Uninject.h"
#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto Uninject::onEnable(void) -> void {
    this->category->manager->isRunning = false;
};