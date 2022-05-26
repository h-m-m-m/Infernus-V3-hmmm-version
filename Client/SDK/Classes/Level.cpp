#include "Level.h"
#include "../Minecraft.h"

auto Level::getPrimaryLocalPlayer(void) -> Actor* {
    using GetPrimaryLocalPlayer = Actor* (__thiscall*)(Level*);
    auto _GetPrimaryLocalPlayer = (GetPrimaryLocalPlayer)nullptr;

    if(_GetPrimaryLocalPlayer == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _GetPrimaryLocalPlayer = (GetPrimaryLocalPlayer)(this->VTable[59]);
            break;
        };
    };

    return (_GetPrimaryLocalPlayer != nullptr ? _GetPrimaryLocalPlayer(this) : nullptr);
};