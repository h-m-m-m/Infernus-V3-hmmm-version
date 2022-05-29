#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "GuiData.h"
#include "MinecraftGame.h"
#include "LevelRenderer.h"

class Player;

class ClientInstance {
private:
    uintptr_t** VTable;
public:
    auto getGuiData(void) -> GuiData*;
    auto getMinecraftGame(void) -> MinecraftGame*;
    auto getLevelRenderer(void) -> LevelRenderer*;
public:
    auto getLocalPlayer(void) -> Player*;
public:
    auto getFov(void) -> Vec2<float>;
    auto getRefDef(void) -> glmatrixf*;
    auto gameToScreenPos(Vec3<float>) -> Vec2<float>;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */