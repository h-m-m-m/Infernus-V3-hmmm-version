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

auto ClientInstance::getLevelRenderer(void) -> LevelRenderer* {
    auto lvlRndr = (LevelRenderer*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            lvlRndr = *(LevelRenderer**)((uintptr_t)(this) + 0xD0);
        break;
    };
    
    return lvlRndr;
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

auto ClientInstance::getFov(void) -> Vec2<float> {
    auto fov = Vec2<float>();

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            fov = Vec2<float>(*(float*)((uintptr_t)(this) + 0x690), *(float*)((uintptr_t)(this) + 0x6A4));
        break;
    };
    
    return fov;
};

auto ClientInstance::getRefDef(void) -> glmatrixf* {
    auto refdefPtr = (glmatrixf*)nullptr;

    switch(Minecraft::getVersion().second) {
        case MC_VER::v1_18_31:
            refdefPtr = (glmatrixf*)((uintptr_t)(this) + 0x2F0);
        break;
    };

    return refdefPtr;
};

auto ClientInstance::gameToScreenPos(Vec3<float> inGamePos) -> Vec2<float> {
    auto screenPos = Vec2<float>();

    auto levelRenderer = this->getLevelRenderer();
    auto guiData = this->getGuiData();

    auto badref = this->getRefDef();
    
    if(levelRenderer == nullptr || guiData == nullptr || badref == nullptr)
        return screenPos;
    
    auto fov = this->getFov();
    auto refdef = badref->correct();
    auto origin = levelRenderer->getOrigin();

    refdef->OWorldToScreen(origin, inGamePos, screenPos, fov, guiData->screenRes1);
    return screenPos;
};