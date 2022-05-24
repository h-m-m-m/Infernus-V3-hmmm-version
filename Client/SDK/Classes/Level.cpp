#include "Level.h"

auto Level::getPrimaryLocalPlayer(void) -> Actor* {
    using GetPrimaryLocalPlayer = Actor* (__thiscall*)(Level*);
    auto _GetPrimaryLocalPlayer = (GetPrimaryLocalPlayer)(this->VTable[59]);

    return _GetPrimaryLocalPlayer(this);
};