#include "ClientInstance.h"
#include "../Minecraft.h"

auto ClientInstance::getGuiData() -> GuiData* {
    auto guiData = (GuiData*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            guiData = *(GuiData**)((uintptr_t)(this) + 0x500);
        break;
    };

    return guiData;
}

auto ClientInstance::getMinecraftGame() -> MinecraftGame* {
    auto mcGame = (MinecraftGame*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            mcGame = *(MinecraftGame**)((uintptr_t)(this) + 0xA8);
        break;
    };

    return mcGame;
};

auto ClientInstance::getLocalPlayer(void) -> Player* {
    using GetLocalPlayer = Player* (__thiscall*)(ClientInstance*);
    static auto _GetLocalPlayer = (GetLocalPlayer)nullptr;

    if(_GetLocalPlayer == nullptr) {
        switch(Minecraft::getVersion().second) {
            case MC_VER::v1_18_31:
                _GetLocalPlayer = (GetLocalPlayer)(this->VTable[24]);
            break;
        };
    };

    return (_GetLocalPlayer != nullptr ? _GetLocalPlayer(this) : nullptr);
};