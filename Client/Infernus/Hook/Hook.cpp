#include "Hook.h"
#include "../Manager/Manager.h"

Hook::Hook(Manager* mgr) {
    this->manager = mgr;
    mgr->hooks.push_back(this);
};